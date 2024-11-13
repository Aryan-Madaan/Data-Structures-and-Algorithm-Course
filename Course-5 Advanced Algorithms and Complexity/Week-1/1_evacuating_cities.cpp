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

class Compare {
public:
bool operator()(pair<int,vector<int> > &a,pair<int,vector<int> > &b)
{
    return b.first < a.first;
}
};

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int> > road(n,vector<int>()),rroad(n,vector<int>(n,0)),weight(n,vector<int>(n,0)),rweight(n,vector<int>(n,0));
        int city1,city2,wt;

        int total_flow = 0;
        rep(i,m)
        {
            cin >> city1 >> city2 >> wt;
            if(city1==city2) continue;
            --city1;--city2;
            road[city1].push_back(city2);
            rroad[city2][city1] = 1;
            rroad[city1][city2] = 1;
            rweight[city1][city2] += wt;
            weight[city1][city2] += wt;
        }

        pair<int,vector<int> > vert;

        bool flag = true;
        int min_flow = 1e9;

        int cnt=0;

        while(flag)
        {
            // cnt++;
            priority_queue <pair<int,vector<int> >,vector<pair<int,vector<int> > >, Compare > pq;
            vector<bool> visited(n,0);

            pq.push(mp(0,vector<int>(1,0)));
            
            flag = false;
            min_flow = 1e9;

            while(!pq.empty())
            {
                vert = pq.top();
                pq.pop();

                // cout << "Queue: " << vert.first << " " << vert.second.back() << "\n";

                if(visited[vert.second.back()]) continue;

                visited[vert.second.back()] = 1;

                if(vert.second.back() == n-1)
                {
                    flag = true;
                    break;
                }


                rep(i,n)
                {
                    if(rroad[vert.second.back()][i] == 1 && rweight[vert.second.back()][i] > 0)
                    {
                        // cout << "\nRoad Found: " << vert.second.back() << " " << i <<"\n";
                        vector<int> path = vert.second;
                        int val = vert.first+=1;
                        path.push_back(i);
                        if(vert.second.back() == n-1){val-2;}
                        pq.push(mp(val,path));
                    }
                }
            }

            if(!flag)
            {
                // cout << "No path found\n";
                break;
            }

            // cout << "\nPath: " << vert.second[0] << " ";
            rep(i,vert.second.size()-1)
            {
                // cout <<vert.second[i+1] << " ";
                min_flow = min(min_flow,rweight[vert.second[i]][vert.second[i+1]]);
            }

            rep(i,vert.second.size()-1)
            {
                rweight[vert.second[i]][vert.second[i+1]] -=min_flow;
                rweight[vert.second[i+1]][vert.second[i]] +=min_flow;
            }

            // cout << "\nMin Flow: " << min_flow << "\n";

            total_flow+=min_flow;
        }


        // cout << "\n\n";
        // rep(i,n)
        // {
        //     rep(j,n)
        //     {
        //         cout << rweight[i][j] << " ";
        //     }
        //     cout << "\n";
        // }


        // cout << "\n\n";
        // rep(i,n)
        // {
        //     rep(j,n)
        //     {
        //         cout << rroad[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        cout << total_flow;

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


