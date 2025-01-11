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
#define INF 1e9
#define rep(i,n) for(int i =0;i<n;i++)
#define endl '\n'
const double eps = 1e-6, pi = acos(-1);
const char nl = '\n';
#define fora(i, f, t) for(int i=f; i<t; i++)

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

struct Edge {
    int from, to, cost;
};

class MyClass {
private:
    vector<Edge> edges;
    vector<vector<int>> init_flow;
    vector<vector<size_t> > graph;
    vector<int> lower_edges;
    int vert;
    int totalEdges;
    int minFlowReqd;
    int maxflow;

public:
    void read_data(){
        int n;

        cin >> n >> totalEdges;

        vert = n + 2;
        minFlowReqd = 0;

        graph = vector<vector<size_t> >(vert);
        init_flow = vector<vector<int>>(vert+1, vector<int>(2, 0));

        for(int i = 0;i < totalEdges; i++) {
            int u;

            int v;

            int low_bound;

            int capacity;

            cin >> u;

            cin >> v;
            
            cin >> low_bound;

            cin >> capacity;

            add_edge(u, v, capacity - low_bound);

            init_flow[u][1] += low_bound;

            init_flow[v][0] += low_bound;

            minFlowReqd += low_bound;

            lower_edges.push_back(low_bound);
        }
    }

    void solve(){
        add_source_sink();
        maxFlow();
    }

    void print(){
        if(maxflow == minFlowReqd){
            cout<<"YES"<<endl;
            fora(i, 0, totalEdges)
                cout<<lower_edges[i] + edges[2*i + 1].cost<<endl;
        }else cout<<"NO"<<endl;
    }

    void add_edge(int from, int to, int cost) {
        graph[from].push_back(edges.size());
        edges.push_back({from, to, cost});
        graph[to].push_back(edges.size());
        edges.push_back({to, from, 0});
    }

    void update_flow(size_t id, int flow) {
        edges[id].cost -= flow;
        edges[id ^ 1].cost += flow;
    }

    void add_source_sink(){
        for(int i=1; i<vert-1; i++)
        {
            add_edge(0, i, init_flow[i][0]);
            add_edge(i, vert-1, init_flow[i][1]);
        }
    }

    void bfs(vector<vector<int>>& prev){
        set<int> visited = {0};
        queue<int> nodes;

        nodes.push(0);

        while(!nodes.empty()){
            int curNod = nodes.front();
            nodes.pop();

            for(const auto& edgeid : graph[curNod]){
                const Edge edge= edges[edgeid];
                if(edge.cost > 0 && visited.find(edge.to) == visited.end()){
                    nodes.push(edge.to);
                    visited.insert(edge.to);

                    prev[edge.to][0] = curNod;
                    prev[edge.to][1] = edgeid;

                    if(edge.to == vert-1) return;
                }
            }
        }
    }


    int getMinResidual(vector<vector<int>>& prev){

        bfs(prev);

        int minres = INT_MAX;
        int curnode = vert-1;

        while(prev[curnode][0] != - 1){
            const Edge edge = edges[prev[curnode][1]];
            minres = min(minres, edge.cost);
            curnode = prev[curnode][0];
        }
        return minres;
    }

    void maxFlow(){
        vector<vector<int>> prev(vert, vector<int>(2, -1));
        int max_residual;
        maxflow = 0;             

        while((max_residual=getMinResidual(prev)) != INT_MAX){
            int curnode = vert - 1;
            while(prev[curnode][0] != - 1){
                const Edge edge = edges[prev[curnode][1]];
                update_flow(prev[curnode][1], max_residual);
                curnode = prev[curnode][0];
            }

            maxflow += max_residual;

            fora(i, 0, prev.size())
                prev[i][0] = prev[i][1] = -1;
        }
    }
};


void solve()
{
    int t=1;

    while(t--)
    {
    MyClass solver;
    solver.read_data();
    solver.solve();
    solver.print();
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


