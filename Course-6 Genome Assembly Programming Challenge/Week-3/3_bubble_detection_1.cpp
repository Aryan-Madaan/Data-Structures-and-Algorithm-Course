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
 double eps = 1e-6, pi = acos(-1);
 char nl = '\n';

typedef vector<vector<int> > Matrix;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

typedef vector<set<int>> Graph;

int randomize()
{
return (rand() % 1000);
}

typedef map<int, map<int, vector<set<int>>>> PATHS;


//---------------------------------------------------------------------------------------------------

int kmersize;
int maxthreshold;

class DBG{
public:
    Graph create(){
        Graph graph;
        string read;
        cin >> kmersize >> maxthreshold;

        while(cin >> read)
            rep(i, read.size() - kmersize + 1)
               add_edge(graph, read.substr(i, kmersize));
        
        return graph;
    }
private:
    void add_edge(Graph& graph, const string& kmer){
        static int k_1 = kmersize - 1;
        static int vertex = 0;
        static map<string, int> labels;

        string L_kmer = kmer.substr(0, k_1);
        string R_kmer = kmer.substr(1, k_1);
        int L_label, R_label;

        if(labels.find(L_kmer) != labels.end()) L_label = labels[L_kmer];
        else { graph.push_back(set<int>()); L_label = labels[L_kmer] = vertex++;}

        if(labels.find(R_kmer) != labels.end()) R_label = labels[R_kmer];
        else { graph.push_back(set<int>()); R_label = labels[R_kmer] = vertex++;}

        graph[L_label].insert(R_label);
    }

};

class BubbleDetection{
private:
    Graph graph;
    Matrix in_out;
    int nodes;
    set<int> in, out;
    PATHS myway;

public:
    BubbleDetection( Graph g): graph(g){
        nodes = graph.size();
        in_out = Matrix(nodes, vector<int>(2, 0));
    }

    int bubbles(){
        find_candidates();

        for( auto& root : out){
            set<int> visited = {root};
            dfs(root, root, visited);
        }

        int bubbles = 0;
        for( auto& w_pair : myway){

             map<int, vector<set<int>>> all_w_vs_myway = w_pair.second;

            for( auto& w_v_myway_pair : all_w_vs_myway){
                 vector<set<int> > w_v_myway = w_v_myway_pair.second;

                rep(i, w_v_myway.size())
                    for(int j = i+1; j<w_v_myway.size(); j++)
                        disjoint_ways(w_v_myway[i], w_v_myway[j]) ? bubbles++ : false;
            }
        }
        return bubbles;
    }

    bool disjoint_ways( set<int>& path1,  set<int>& path2){
        for( auto& v : path1)
            if(path2.find(v) != path2.end()) return false;
        return true;
    }

    void find_candidates(){
        rep(i, nodes){
            in_out[i][1] = graph[i].size();
            for( auto& v : graph[i])
                in_out[v][0]++;
        }

        rep(i, nodes){
            if(in_out[i][0] > 1) in.insert(i);
            if(in_out[i][1] > 1) out.insert(i);
        }
    }

    void dfs(int root, int curnode, set<int>& visited){
        if(curnode != root && in.find(curnode) != in.end()){
            set<int> npath = visited;
            npath.erase(curnode);
            npath.erase(root);
            myway[root][curnode].push_back(npath);
        }

        if(visited.size() > maxthreshold) return;

        for( auto& v : graph[curnode])
            if(visited.find(v) == visited.end()){
                set<int> nvisited = visited;
                nvisited.insert(v);
                dfs(root, v, nvisited);
            }
    }
};


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        DBG myG;
        Graph g = myG.create();

        BubbleDetection bd (g);
        cout << bd.bubbles() <<endl;
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


