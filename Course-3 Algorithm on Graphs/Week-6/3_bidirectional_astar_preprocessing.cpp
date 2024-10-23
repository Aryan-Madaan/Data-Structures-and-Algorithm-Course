//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
#pragma optimize("O3",on)
#include <bits/stdc++.h>
using namespace std;
#define Expresso std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define mp make_pair
#define ff first
#define ss second
#define pb(v) push_back(v)
#define rep(i,n) for(int i =0;i<n;i++)

//---------------------------------------------------------------------------------------------------

class Compare
{
public:
    bool operator()(pair<int,long> &a, pair<int,long> &b)
    {
        return a.second>b.second;
    }
    bool operator()(pair<pair<int,long>,int> &a, pair<pair<int,long>,int> &b)
    {
        return a.first.second>b.first.second;
    }
};

float compute_dist(pair<int,int> p1, pair<int,int>p2)
{
    return sqrt((float)(p1.first-p2.first)*(float)(p1.first-p2.first) + (float)(p1.second - p2.second)*(float)(p1.second - p2.second));
}

void solve()
{
    int max_nodes = 5;

    int n,m;
    cin >> n >> m;
    vector<vii> graph(n,vii()),rgraph(n,vii());
    vi node_level(n,-1),rank(n,-1),short_cnt(n,0),contract_neigh(n,0);
    priority_queue<pair<int,long>,vector<pair<int,long> >,Compare> node_order;
    priority_queue<pair<pair<int,long>,int>,vector<pair<pair<int,long>,int> >,Compare> shortcuts;
    vii max_value(n,mp(-1,-1));
    int max_prec = -1, allowed_dist = 0;
    pair<pair<int,long>,int> tmp_vert;
    

    int vert1,vert2,len;

    rep(i,m)
    {
        cin >> vert1 >> vert2 >> len;
        --vert1; --vert2;
        graph[vert1].push_back(mp(vert2,len));
        rgraph[vert2].push_back(mp(vert1,len));
        max_value[vert1].first = max(len,max_value[vert1].first);
        max_value[vert2].second = max(len,max_value[vert2].second);
    }

    rep(i,n)
    {
        if(max_value[i].first!=-1 && max_value[i].second!=-1)
        {
            max_prec = -1;
            unordered_map<int,int> mpp;
            rep(j,graph[i].size())
            {
                max_prec = max(max_value[graph[i][j].first].first,max_prec);
                mpp[graph[i][j].first] = 1;
            }
            if(max_prec!=-1)
            {
                allowed_dist = max_value[i].first + max_value[i].second - max_prec;
                rep(j,rgraph[i].size())
                {
                    if(rgraph[i][j].second < allowed_dist)
                    {
                        shortcuts.push(mp(mp(rgraph[i][j].first,rgraph[i][j].second),1));
                    }
                }
                while(shortcuts.size()>0)
                {
                    tmp_vert = shortcuts.top();
                    shortcuts.pop();
                    if(tmp_vert.second == max_nodes) continue;
                    rep(j,graph[tmp_vert.first.first].size())
                    {
                        if(graph[tmp_vert.first.first][j].second + tmp_vert.first.second <=allowed_dist)
                        {
                            
                        }
                    }
                }
            }
        }
    }

    while(node_order.size()>0)
    {

    }




    cout << "Ready" << endl;

    priority_queue<pair<int,long>,vector<pair<int,long> >,Compare> pq,pq1;

    int q;
    cin >> q;
    while(q--)
    {
        cin >> vert1 >> vert2;
        --vert1; --vert2;

        
    }

}




//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(15) << fixed;
    Expresso
    solve();
    return 0;
}


