//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
#pragma optimize("O3",on)
#include <bits/stdc++.h>

using namespace std;
#define Expresso std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb(v) push_back(v)
#define rep(i,n) for(int i =0;i<n;i++)

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
        vector<vector<int> > rroad(n+m+2,vector<int>(n+m+2,0)),rweight(n+m+2,vector<int>(n+m+2,0));

        vector<int> crewtoflight(n+m+2,-1);

        rep(i,n)
        {
            rep(j,m)
            {
                cin >> rroad[i+1][n+1+j];
                if(rroad[i+1][n+1+j])
                {
                    rroad[n+1+j][i+1] = 1;
                    rweight[i+1][n+1+j] = 1;
                }
            }
        }
        rep(i,n)
        {
            rroad[0][i+1] = 1;
            rroad[i+1][0] = 1;
            rweight[0][i+1] = 1;
        }

        rep(i,m)
        {
            rroad[n+i+1][n+m+1] = 1;
            rroad[n+m+1][n+i+1] = 1;
            rweight[n+i+1][n+m+1] = 1;
        }

        // rep(i,n+m+2)
        // {
        //     rep(j,n+m+2)
        //     {
        //         cout << rroad[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // cout << "\n\n";

        // int total_flow = 0;

        pair<int,vector<int> > vert;

        bool flag = true;
        int min_flow = 1e9;

        int cnt=0;

        while(flag)
        {
            // cnt++;
            priority_queue <pair<int,vector<int> >,vector<pair<int,vector<int> > >, Compare > pq;
            vector<bool> visit(n+m+2,0);

            pq.push(mp(0,vector<int>(1,0)));
            
            flag = false;
            min_flow = 1;

            while(!pq.empty())
            {
                vert = pq.top();
                pq.pop();

                // cout << "Queue: " << vert.first << " " << vert.second.back() << "\n";

                if(visit[vert.second.back()]) continue;

                visit[vert.second.back()] = 1;

                if(vert.second.back() == n+m+1)
                {
                    flag = true;
                    break;
                }


                rep(i,n+m+2)
                {
                    if(rroad[vert.second.back()][i] == 1 && rweight[vert.second.back()][i] > 0)
                    {
                        // cout << "\nRoad Found: " << vert.second.back() << " " << i <<"\n";
                        vector<int> path(vert.second);
                        int val = vert.first+=1;
                        path.push_back(i);
                        if(vert.second.back() == n+m+1)
                        {val= val-1;}
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
            // rep(i,vert.second.size()-1)
            // {
            //     // cout <<vert.second[i+1] << " ";
            //     min_flow = min(min_flow,rweight[vert.second[i]][vert.second[i+1]]);
            // }

            for(int i = 1;i<vert.second.size();i+=2)
            {
                crewtoflight[vert.second[i]-1] = vert.second[i+1] - n;
            }
            

            rep(i,vert.second.size()-1)
            {
                rweight[vert.second[i]][vert.second[i+1]] -=min_flow;
                rweight[vert.second[i+1]][vert.second[i]] +=min_flow;
            }

            // cout << "\nMin Flow: " << min_flow << "\n";

            // cout << "\n\n";
            // rep(i,n+m+2)
            // {
            //     rep(j,n+m+2)
            //     {
            //         cout << rweight[i][j] << " ";
            //     }
            //     cout << "\n";
            // }

            // total_flow+=min_flow;

            vert = mp(0,vector<int>());
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

        // cout << total_flow;

        rep(i,n)
        {
            cout << crewtoflight[i] << " ";
        }

    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
    Expresso
    solve();
    return 0;
}


