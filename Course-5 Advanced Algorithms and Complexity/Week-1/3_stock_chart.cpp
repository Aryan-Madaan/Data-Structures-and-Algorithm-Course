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



bool dfs(vector<vector<int> >&rroad,vector<int>&visit,vector<int>&match,int v)  
{  
    visit[v]=true; 

    for(int i=0;i<rroad[v].size();i++){  

        int u=rroad[v][i],w=match[u]; 

        if(w<0||!visit[w]&&dfs(rroad,visit,match,w)){  
            match[v]=u;  
            match[u]=v;  
            return true;  
        }  

    }  

    return false;  
}  

int bipartite_matching(vector<vector<int> >&rroad,vector<int>&visit,vector<int>&match)  
{  
    int res=0;  

    rep(i,match.size()) match[i] = -1;

    for(int i=0;i<rroad.size();i++){  

        if(match[i]<0){  

            rep(j,rroad.size()) visit[j] = 0;

            if(dfs(rroad,visit,match,i)){  

                res++;  
            }  
        }  
    }  
    return res;  
}  


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {

        int n = 100,k = 25;
        cin >> n >> k;

        vector<vector<int> > prices(n,vector<int>(k,0));

        vector<vector<int> >rroad(2*n,vector<int>());

        rep(i,n)
        {
            rep(j,k)
            {
                cin >> prices[i][j];
            }
        }

        bool flag = true;

        rep(i,n)
        {
            rep(j,n)
            {
                if(i==j) continue;
                flag = true;

                rep(z,k)
                {
                    if(prices[i][z] >= prices[j][z])
                    {
                        // cout << i << " " << j << " " << prices[i][z] << " " << prices[j][z] << "\n";
                        flag = false;
                        break;
                    }
                }

                if(flag)
                {
                    rroad[i].pb(n+j);
                    rroad[n+j].pb(i);
                }
            }
        }

        vector<int> visit(2*n,-1) ,match(2*n,-1);

        cout << n - bipartite_matching(rroad, visit,match);
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


