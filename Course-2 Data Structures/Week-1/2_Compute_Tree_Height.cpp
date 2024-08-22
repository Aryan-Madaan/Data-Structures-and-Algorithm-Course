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

int dfs(vector<vector<int> > &vv,vector<bool> &vis,int i)
{
    vis[i]=1;
    if(vv[i].size()==0)
    {
        return 1;
    }
    else
    {
        int res = 1;
        rep(j,vv[i].size())
        {
            res = max(res,1 + dfs(vv,vis,vv[i][j]));
        }
        return res;
    }
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n,0);
        rep(i,n) cin >> v[i];
        vector<vector<int> > vv(n,vector<int>());
        int start = 0;
        rep(i,n)
        {
            if(v[i]!=-1)
            {
                vv[v[i]].push_back(i);
            }
            else
            {
                start = i;
            }
        }
        vector<bool> vis(n,0);
        vis[start] = 1;
        cout << dfs(vv,vis,start);
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


