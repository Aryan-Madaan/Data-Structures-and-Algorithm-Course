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


int dpp(vector<vector<int> >&bosses,vector<int> &funfactor,vector<bool>& vis,vector<int> &ans,int curr_node)
{
    vis[curr_node] = 1;
    if(ans[curr_node]!=-1) {

    }
    else if(bosses[curr_node].size()==0)
    {
        ans[curr_node] = funfactor[curr_node];
    }
    else
    {
        vis[curr_node] = 1;
        int m1=funfactor[curr_node],m2=0;
        rep(i,bosses[curr_node].size())
        {
            if(vis[bosses[curr_node][i]]) continue;
            vis[bosses[curr_node][i]]=1;
            rep(j,bosses[bosses[curr_node][i]].size())
            {
                if(vis[bosses[bosses[curr_node][i]][j]]) continue;
                m1 +=  dpp(bosses,funfactor,vis,ans,bosses[bosses[curr_node][i]][j]);
                // vis[bosses[bosses[curr_node][i]][j]] = 0;
            } 
            vis[bosses[curr_node][i]]=0;
            m2 += dpp(bosses,funfactor,vis,ans,bosses[curr_node][i]);   
            
        }
        ans[curr_node] = max(m1,m2);   
    }
    vis[curr_node] = 0;
    return ans[curr_node];

}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> funfactor(n,0);

        rep(i,n)
        cin >> funfactor[i];

        vector<vector<int> >bosses(n);
        int vert1 = 0,vert2 = 0;

        rep(i,n-1)
        {
            cin >> vert1 >> vert2;
            --vert1; --vert2;
            bosses[vert2].pb(vert1);
            bosses[vert1].pb(vert2);
        }

        vector<int> ans(n,-1);
        vector<bool>vis(n,0);

        dpp(bosses,funfactor,vis,ans,0);

        cout << ans[0];


    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(15) << fixed;

    // const rlim_t kStackSize = 64L * 1024L * 1024L;  // min stack size = 64 Mb
    // struct rlimit rl;
    // int result;
    // result = getrlimit(RLIMIT_STACK, &rl);
    // if (result == 0)
    // {
    //     if (rl.rlim_cur < kStackSize)
    //     {
    //         rl.rlim_cur = kStackSize;
    //         result = setrlimit(RLIMIT_STACK, &rl);
    //         if (result != 0)
    //         {
    //             fprintf(stderr, "setrlimit returned result = %d\n", result);
    //         }
    //     }
    // }
    Expresso
    solve();
    return 0;
}


