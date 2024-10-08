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

bool dfs(vector< vector<int> > &graph,vector<bool> &vis,vector<bool> &vis1,int i)
{
    if(vis1[i]==1)
    {
        // cout << "Here \n";
        return 1;
    }
    if(vis[i]==1)
    {
        return 0;
    }

    vis[i]=1;
    vis1[i] = 1;

    bool flag = 0;

    rep(j,graph[i].size())
    {
        // cout << graph[i][j] << "\n";
        flag = flag || dfs(graph,vis,vis1,graph[i][j]);
    }

    vis1[i] = 0;
    
    return flag;
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,edges,vert1,vert2;

        cin >> n >> edges;

        vector< vector<int> > graph(n,vector<int>(0));
        vector<bool> vis(n,0),vis1(n,0);
        rep(i,edges)
        {
            cin >> vert1 >> vert2;
            --vert2;--vert1;
            graph[vert1].push_back(vert2);
        }
        
        bool flag = 0;
        rep(i,n)
        {
            if(!vis[i])
            {
                // cout << "Start Node: " << i << "\n";
                flag = flag || dfs(graph,vis,vis1,i);
            }
        }
        cout << flag;
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


