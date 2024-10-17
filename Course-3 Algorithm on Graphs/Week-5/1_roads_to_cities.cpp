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
    vector<pair< int,double>  > qq;
    vector<int> loc;
    int l,r,parent,min_idx;
    double tmp;
    pair< int,double> temp,temp1;

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
        tmp = loc[qq[j].first];
        loc[qq[j].first] = loc[qq[i].first];
        loc[qq[i].first] = tmp;
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

        // if(qq[curr].second < qq[parent].second)
        // {
        //     swap(curr,parent);
        //     siftup(parent);
        // }
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
    priqueue()
    {
        loc.resize(500);
        rep(i,loc.size())
        {
            loc[i] = -1;
        }
    }

    void changepri(int i, double pri)
    {
        if(loc[i]==-1 || qq[loc[i]].second <= pri) return;

        qq[loc[i]].second = pri;
        siftup(loc[i]);
    }

    void push(pair<int,double> inp)
    {
        loc[inp.first] = qq.size();
        qq.push_back(inp);
        siftup(qq.size()-1);
    }

    pair<int,double> pop()
    {
        temp1 = qq[0];
        swap(0,qq.size()-1);
        loc[temp1.first] = -1;
        qq.pop_back();
        siftdown(0);
        return temp1;
    }

    int size()
    {
        return qq.size();
    }

    void print()
    {
        cout<<"\nPrinting Queue\n";
        rep(i,qq.size())
        {
            cout << qq[i].first << ":" << qq[i].second << " ";
        }
        cout << "\n\nPrinting Loc\n";
        rep(i,6)
        {
            cout << loc[i] << " ";
        }
        cout << endl;
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
        long double curr_cost = 0;
        vector<vector<double> > dist(n,vector<double>(n,0.0));
        rep(i,n)
        {
            cin >> points[i].first >> points[i].second;
        }
        rep(i,n)
        {
            for(int j = i+1;j<n;j++)
            {
                dist[i][j] = compute_dist(points[i],points[j]);
                dist[j][i] = dist[i][j];
            }
        }

        // rep(i,n)
        // {
        //     rep(j,n)
        //     {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        pair<int,double> point;

        priqueue myqu = priqueue();

        myqu.push(mp(0,0));

        for(int i =1;i<n;i++)
        {
            myqu.push(mp(i,1e11));
        }
        // myqu.print();

        while(myqu.size()!=0)
        {
            point = myqu.pop();
            // cout << "\nQueueFirst" << point.first << " " << point.second << "\n";
            // myqu.print();
            curr_cost+=point.second;
            // cout<<"\nChanging Priority\n";
            for(int i = 0;i<n;i++)
            {
                myqu.changepri(i,dist[point.first][i]);
                // cout << i << " " << dist[point.first][i] << "\n";
            }
            // cout << "\nFinished\n";
            // myqu.print();
        }
        cout << curr_cost;
    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(12) << fixed;
    cout.precision(numeric_limits<long double>::max_digits10);
    cout << setprecision(12) << fixed;
    Expresso
    solve();
    return 0;
}


