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


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,edges,vert1,vert2,weight;

        cin >> n >> edges;

        vector<pair<int,long> > graph(edges,mp(0,0));
        vector<long> dis(n,1e10),wgt(edges,0);
        vector<int> prev(n,-1);

        bool flag = 0;

        rep(i,edges)
        {
            cin >> vert1 >> vert2 >> weight;
            --vert2;--vert1;
            graph[i] = mp(vert1, vert2);
            wgt[i] = weight;
        }

        if(edges>0){
            dis[graph[0].first] = 0;

            rep(i,n-1)
            {
                rep(j,edges)
                {
                    if(dis[graph[j].second] > dis[graph[j].first] + wgt[j])
                    {
                        dis[graph[j].second] = dis[graph[j].first] + wgt[j];
                        prev[graph[j].second] = graph[j].first;
                    }
                }
            }

            rep(j,edges)
            {
                if(dis[graph[j].second] > dis[graph[j].first] + wgt[j])
                {
                    dis[graph[j].second] = dis[graph[j].first] + wgt[j];
                    prev[graph[j].second] = graph[j].first;
                    flag = 1;
                    break;
                }
            }
        }

        if(flag) cout << 1;
        else cout << 0;
        // rep(i,ng.size()) cout << ng[i] << " ";

        
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


