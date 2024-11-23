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
// #define endl '\n'
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


void dfs(vector<vector<bool> > &graph,vector<vector<int> > &ans,vector<bool> &vis,int i)
{
    vis[i] = 1;
    vector<int> temp;

    rep(j,graph[i].size())
    {
        // temp = {-((i*3)+1),-((graph[i][j]*3)+1),0};
        // ans.push_back(temp);
        // temp = {-((i*3)+2),-((graph[i][j]*3)+2),0};
        // ans.push_back(temp);
        // temp = {-((i*3)+3),-((graph[i][j]*3)+3),0};
        // ans.push_back(temp);
        if(graph[i][j]&&!vis[j])
        {
            dfs(graph,ans,vis,j);
        }
        else if(!graph[i][j])
        {
            rep(k,graph.size()-1)
            {
                ans.push_back({-((i)*(int)graph.size() + k+1),-((j)*(int)graph.size() + k+2),0});
            }
        }
    }
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n = 0 ,m = 0;
        cin >> n >> m;

        vector<vector<bool> > graph(n,vector<bool>(n,0));
        vector<vector<int> >ans;

        int vert1,vert2;

        rep(i,m)
        {
            cin >> vert1 >> vert2;
            --vert1;--vert2;
            graph[vert1][vert2] = 1;
            graph[vert2][vert1] = 1;
        }

        vector<bool>vis(n,0);
        vector<int> temp,temp1;

        rep(i,n)
        {
            
            for(int j = i+1;j<n;j++)
            {
                if(i!=j)
                {
                    rep(k,n)
                    {
                        ans.push_back({-((i)*n + k+1),-((j)*n + k+1),0});
                        ans.push_back({-((k)*n + i+1),-((k)*n + j+1),0});
                    }
                }
                
            }
        }

        rep(i,n)
        {
            temp.clear();
            temp1.clear();
            rep(j,n)
            {
                temp.pb((i)*n + j+1);
                temp1.pb((j)*n + i+1);
            }
            temp.pb(0);
            temp1.pb(0);
            ans.push_back(temp);
            ans.push_back(temp1);
        }

        rep(i,n)
        {
            // temp = {(i*3)+1,(i*3)+2,(i*3)+3,0};
            // ans.push_back(temp);
            // temp = {-((i*3)+1),-((i*3)+2),0};
            // ans.push_back(temp);
            // temp = {-((i*3)+2),-((i*3)+3),0};
            // ans.push_back(temp);
            // temp = {-((i*3)+1),-((i*3)+3),0};
            // ans.push_back(temp);
            if(!vis[i])
            {
                dfs(graph,ans,vis,i);
            }
        }

        cout << ans.size() << " " <<  n*n << "\n";

        rep(i,ans.size())
        {
            rep(j,ans[i].size())
            {
                
                cout << ans[i][j];
                if(j!=ans[i].size()-1)
                cout << " ";
            }
            if(i!=ans.size()-1)
            cout << "\n";
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


