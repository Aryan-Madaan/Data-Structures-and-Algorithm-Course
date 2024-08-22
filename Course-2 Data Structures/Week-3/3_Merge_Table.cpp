//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
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
class disSet
{
    private:
    vector<int> parent,rank;
    vector<long> rows;
    public:
    disSet(int &n,long & maxi)
    {
        long x;
        rep(i,n)
        {
            cin >> x;
            rows.push_back(x);
            maxi = max(maxi,x);
            parent.push_back(i);
            rank.push_back(1);
        }
    }
    int find1(int i)
    {
        if(i!=parent[i])
        {
            parent[i] = find1(parent[i]);
        }
        return parent[i];
    }
    void uni(int &i,int &j,long &maxi)
    {
        int i_id = find1(i),j_id = find1(j);
        if (i_id == j_id)
        {
            return;
        }
        if(rank[i_id] > rank[j_id])
        {
            rows[parent[i_id]] += rows[parent[j_id]];
            rows[parent[j_id]]=0;
            maxi = max(maxi,rows[parent[i_id]]);
            parent[j_id] = i_id;
        }
        else
        {
            rows[parent[j_id]] += rows[parent[i_id]];
            rows[parent[i_id]]=0;
            maxi = max(maxi,rows[parent[j_id]]);
            parent[i_id] = j_id;
            // cout << i << " " << j << " " << i_id << " " << j_id << " ";
            // cout << parent[i_id] << " " << parent[j_id] << "\n";
            if(rank[i_id]==rank[j_id])
            {
                rank[j_id]++;
            }
        }
    }
};

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,m;
        long maxi=0;
        cin >> n >> m;
        // vector<int> parent(n);
        // vector<ll> rank(n);
        disSet se(n,maxi);
        // rep(i,n) 
        // {
        //     cin >> rank[i];
        //     parent[i] = i;
        //     maxi = max(rank[i],maxi);
        // }
        vector<pair<int,int> > myvec;
        int n1,n2;
        rep(i,m)
        {
            cin >> n1 >> n2;
            n1--;
            n2--;
            myvec.push_back(mp(n1,n2));
        }
        vector<long> ans;
        rep(i,m){
            se.uni(myvec[i].first,myvec[i].second,maxi);
            ans.push_back(maxi);
        }
            // if(trees != 1)
            // {
            //     while(n1!=parent[n1])
            //     {
            //         n1 = parent[n1];
            //     }
            //     while(n2!=parent[n2])
            //     {
            //         n2 = parent[n2];
            //     }
            //     if(n1!=n2)
            //     {
            //         parent[n1] = n2;
            //         rank[n2]+=rank[n1];
            //         maxi = max(maxi,rank[n2]);  
            //         trees--;     
            //     }
            // }
        rep(i,m){
            cout << ans[i] <<'\n';
        }
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


