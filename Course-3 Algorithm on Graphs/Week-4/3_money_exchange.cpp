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
        vector< vector<int> > graph1(n,vector<int>());
        vector<long> dis(n,1e14),wgt(edges,0);
        vector<int> prev(n,-1),ng;
        vector<bool> vis(n,0),vis1(n,0);

        unordered_map<int,bool> reachable,reachable1;

        bool flag = 0;

        rep(i,edges)
        {
            cin >> vert1 >> vert2 >> weight;
            --vert2;--vert1;
            graph[i] = mp(vert1, vert2);
            graph1[vert1].push_back(vert2);
            wgt[i] = weight;
        }

        cin >> vert1;
        --vert1;
        dis[vert1] = 0;
        reachable[vert1]=1;

        if(edges>0)
        {
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
                    ng.push_back(graph[j].second);
                }
            }

            queue<int> currency;

            currency.push(vert1);

            int vert;

            while(currency.size()>0)
            {
                vert = currency.front();
                currency.pop();

                vis[vert]=1;
                reachable[vert] = 1;

                rep(i,graph1[vert].size())
                {
                    if(!vis[graph1[vert][i]])
                    {
                        currency.push(graph1[vert][i]);
                    }
                }
            }

            int idx,curr_node;

            rep(i,ng.size())
            {
                if(reachable1.find(ng[i])==reachable1.end() && reachable.find(ng[i])!=reachable.end())
                {
                    // cout << "/n Reachable : " << ng[i]; 
                    idx = 0;
                    curr_node = ng[i];

                    // cout << "\nStarting Cycle\n";
                    while(idx<n && prev[curr_node]!=-1)
                    {
                        // cout << curr_node << " ";
                        curr_node = prev[curr_node];
                        idx++;
                    } 

                    // cout << "\nStarting Queue Check\n";
                    
                    if(idx == n)
                    {
                        reachable1[ng[i]] = 1;
                        currency.push(ng[i]);

                        while(currency.size()>0)
                        {
                            vert = currency.front();
                            // cout << vert << " ";
                            currency.pop();

                            vis1[vert]=1;
                            reachable1[vert] = 1;

                            rep(i,graph1[vert].size())
                            {
                                if(!vis1[graph1[vert][i]])
                                {
                                    currency.push(graph1[vert][i]);
                                }
                            }
                        }
                    }               
                }
            }
        }

        rep(i,n)
        {
            if(reachable.find(i)!=reachable.end()&& reachable1.find(i)!=reachable1.end())
            {
                cout << "-\n";
            }
            else if(reachable.find(i)!=reachable.end())
            {
                cout << dis[i] << "\n";
            }
            else
            {
                cout << "*\n";
            }
            
        }
        
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


