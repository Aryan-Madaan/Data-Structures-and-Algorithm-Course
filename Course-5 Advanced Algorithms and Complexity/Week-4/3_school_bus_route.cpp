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
struct pair_hash {
    size_t operator()(const pair<bitset<18>, int>& p) const {
        // Hash the bitset<17>
        size_t hash1 = hash<string>()(p.first.to_string());
        // Hash the integer
        size_t hash2 = hash<int>()(p.second);
        // Combine the two hashes (e.g., using XOR and bit shifting)
        return hash1 ^ (hash2 << 1);
    }
};


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n=0, m=0;
        cin >> n >> m;
        vector<vector<int> > graph(n,vector<int>(n,INT_MAX));
        vector<vector<ll>> dp(1 << n, vector<ll>(n, INT_MAX)),prev_dp(1 << n, vector<ll>(n, INT_MAX));
        int vert1=0,vert2=0,timetaken = 0;

        vector<int> path(n,-1);

        rep(i,m)
        {
            cin >> vert1 >> vert2 >> timetaken;
            --vert1; --vert2;

            graph[vert1][vert2] =timetaken;
            graph[vert2][vert1] = timetaken;
        }

        dp[1][0] = 0;

        for(int i = 1;i<(1<<(n));i++)
        {
            rep(k,n)
            {
                if(k==0) continue;

                if((i & (1 << k)))
                {
                    rep(j,n)
                    {
                        if(j!=k&&(i & (1 << j))&&graph[k][j]!=INT_MAX)
                        {
                            if(dp[i][k]> dp[i^(1<<k)][j] + (ll)graph[k][j])
                            {
                                prev_dp[i][k] = j;
                                dp[i][k] = dp[i^(1<<k)][j] + (ll)graph[k][j];
                                // cout << "Updating" << i << " " << k  <<  dp[i][k] << " " <<"\n";
                            }
                        }
                    }
                }
            }
        }

        ll total_dist = INT_MAX;

        int last_city;
        int subsets1 = (1<<n)-1;
        int current_state=0; 

        rep(i,n)
        {
            if(i!=0)
            {
                if(total_dist > dp[(1<<n)-1][i] + graph[i][0])
                {
                    last_city = i;
                    total_dist =  min(total_dist,dp[(1<<n)-1][i]+graph[i][0]);
                }
                
                // cout << total_dist << " " << dp[(1<<n)-1][i] << " " << i << "\n";
            }
        }

        if(total_dist>=INT_MAX)
        {
            cout << -1;
        }
        else
        {
            cout << total_dist<<"\n1 ";
            vector<int> path;
            int current_city = last_city;
            while (current_city != 0) {
                path.push_back(current_city + 1);
                current_state = subsets1;
                subsets1 = subsets1 & ~(1<<current_city);
                current_city = prev_dp[current_state][current_city];
            }
            reverse(path.begin(), path.end());
            for (int city : path) {
                cout << city << " ";
            }
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


