//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
#pragma optimize("O3",on)
#include <bits/stdc++.h>

#include <stdio.h>
using namespace std;
#define Expresso std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mod 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long double ld;
typedef unsigned long long ull;
#define mp make_pair
#define ff first
#define ss second
#define pb(v) push_back(v)
#define INF 2e9
#define rep(i,n) for(int i =0;i<n;i++)
#define endl '\n'
const double eps = 1e-6, pi = acos(-1);
const char nl = '\n';

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int randomize()
{
return (rand() % 1000);
}


//---------------------------------------------------------------------------------------------------

class priqueue
{
    vector<pair< pair<int,int> ,double>  > qq;
    int l,r,parent,min_idx;
    double tmp;
    pair< pair<int,int> ,double> temp,temp1;

    int getparent(int i)
    {
        return (i-1)/2;
    }

    int leftchild(int i)
    {
        return 2*i + 1;
    }

    int rightchild(int i)
    {
        return 2*i + 2;
    }

    void swap(int i, int j)
    {
        temp = qq[j];
        qq[j] = qq[i];
        qq[i] = temp;
    }

    void siftup(int curr)
    {
        parent = getparent(curr);

        while (curr > 0 && qq[curr].second < qq[parent].second) {
            swap(curr, parent);
            curr = parent;
            parent = getparent(curr);
        }
    }

    void siftdown(int curr)
    {
        min_idx = curr;
        l = leftchild(curr),r =rightchild(curr);
        if(l<qq.size()&&qq[l].second<qq[min_idx].second)
        {
            min_idx = l;
        }
        if(r<qq.size()&&qq[r].second<qq[min_idx].second)
        {
            min_idx = r;
        }
        if(curr!=min_idx)
        {
            swap(curr,min_idx);
            siftdown(min_idx);
        }
    }

    public:

    void push(pair<pair<int,int>,double> inp)
    {
        qq.push_back(inp);
        siftup(qq.size()-1);
    }

    pair< pair<int,int> ,double> pop()
    {
        temp1 = qq[0];
        swap(0,qq.size()-1);
        qq.pop_back();
        siftdown(0);
        return temp1;
    }

    int size()
    {
        return qq.size();
    }
};



class DisjointSet
{
    vector<int> parent, rank;
    int n,prnt, prnt1, prnt2;
    int num_set;
    int temp;

    public:
    DisjointSet(int n)
    {
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        rep(i,n)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
        num_set = n;
    }

    int getsets()
    {
        return num_set;
    }

    int getparent(int i)
    {
        prnt = i;

        while(parent[prnt]!=-1)
        {
            prnt = parent[prnt];
        }

        return prnt;
    }

    void merge(int i, int j)
    {
        prnt1 = getparent(i);
        prnt2 = getparent(j);

        if(prnt1!=prnt2)
        {
            --num_set;
            if(rank[prnt1]>rank[prnt2])
            {
                parent[prnt2] = prnt1;
            }
            else
            {
                parent[prnt1] = prnt2;
                rank[prnt2] = max(rank[prnt1]+1,rank[prnt2]);
            }
        }
    }

};

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {

        size_t hash1 = hash<T1>()(p.first);

        size_t hash2 = hash<T2>()(p.second);

        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};


double compute_dist(pair<int,int> p1, pair<int,int>p2)
{
    return sqrt((double)(p1.first-p2.first)*(double)(p1.first-p2.first) + (double)(p1.second - p2.second)*(double)(p1.second - p2.second));
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vii points(n);
        pair<pair<int,int>,double> point;
        rep(i,n) cin >> points[i].first >> points[i].second;

        int k;
        cin >> k;

        vector<vector<double> > dist(n,vector<double>(n,0.0));

        priqueue myqu = priqueue();

        rep(i,n)
        {
            for(int j = i+1;j<n;j++)
            {
                myqu.push(mp(mp(i,j),compute_dist(points[i],points[j])));
            }
        }

        DisjointSet dis = DisjointSet(n);

        while(dis.getsets() > k)
        {
            point = myqu.pop();
            dis.merge(point.first.first,point.first.second);
        }

        unordered_map <pair<int,int>,bool,hash_pair> mpp;

        double small = 1e15;
        
        int parent1,parent2;
        while(mpp.size()<k*(k-1)&&myqu.size()>0)
        {
            point = myqu.pop();
            parent1 = dis.getparent(point.first.first);
            parent2 = dis.getparent(point.first.second);
            if(parent1!=parent2 && mpp.find(mp(parent1,parent2))==mpp.end())
            {
                mpp[mp(parent1,parent2)]=1;
                small = min(point.second,small);
            }
        }
        cout << small;

    }
    
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(15) << fixed;
    Expresso
    solve();
    return 0;
}


