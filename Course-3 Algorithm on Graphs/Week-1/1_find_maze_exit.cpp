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

bool dfs(vector< vector<int> > &graph,vector<bool> &vis,int i,int &final)
{
    if(vis[i]==1) return 0;
    vis[i]=1;

    if(i == final)
    return 1;

    bool flag = 0;

    rep(j,graph[i].size())
    {
        flag = flag | dfs(graph,vis,graph[i][j],final);
    }

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

        vector< vector<int> > graph(n+1,vector<int>(0));
        vector<bool> vis(n,0);
        rep(i,edges)
        {
            cin >> vert1 >> vert2;
            --vert2;--vert1;
            graph[vert1].push_back(vert2);
            graph[vert2].push_back(vert1);
        }
        
        cin >> vert1 >> vert2;
        --vert2;--vert1;

        if(dfs(graph,vis,vert1,vert2))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
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



