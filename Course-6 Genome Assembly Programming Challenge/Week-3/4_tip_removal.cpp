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

class My{
public:
    vector<vector<set<int> > > create(){
        return de_bruijn_graph();
    }
private:
    void add_edge(vector<vector<set<int> > >& graph, const string& kmer){
        static int k_1 = 15 - 1;
        static int vertex = 0;
        static map<string, int> labels;

        string L_kmer = kmer.substr(0, k_1);
        string R_kmer = kmer.substr(1, k_1);
        int L_label, R_label;

        if(labels.find(L_kmer) != labels.end()) L_label = labels[L_kmer];
        else { graph.push_back(vector<set<int>>(2, set<int>()));  L_label = labels[L_kmer] = vertex++;}

        if(labels.find(R_kmer) != labels.end()) R_label = labels[R_kmer];
        else { graph.push_back(vector<set<int>>(2, set<int>())); R_label = labels[R_kmer] = vertex++;}

        graph[L_label][0].insert(R_label);

        graph[R_label][1].insert(L_label);
    }

    vector<vector<set<int> > > de_bruijn_graph(){
        vector<vector<set<int> > > graph;
        string read;

           while( cin >> read)
            for(int j=0;j< 86;++j)
               add_edge(graph, read.substr(j, 15));
               
        return graph;
    }

};

class FindTips{
private:
    vector<vector<set<int> > > graph;
    vector<vector<int> > in_out;
    set<int> out_tips;
    set<int> in_tips;
    int nodes;
    int tips;

public:
    FindTips(vector<vector<set<int> > > g): graph(g){
        nodes = graph.size();
        tips = 0;
        in_out = vector<vector<int> >(nodes, vector<int>(2, 0));
    }

    int tips_number(){
        find_candidates();

        bfs_in_tips();

        bfs_out_tips();

        return tips;
    }

    void find_candidates(){
        for(int i = 0; i< nodes; i++){
            in_out[i][0] = graph[i][0].size();
            in_out[i][1] = graph[i][1].size();
        }

        for(int i = 0;i< nodes;i++){
            if(in_out[i][0] == 0) out_tips.insert(i);
            if(in_out[i][1] == 0) in_tips.insert(i);
        }
    }

    void bfs_in_tips(){
        while(! in_tips.empty()){
            int curtip = *(in_tips.begin());
            in_tips.erase(curtip);

            for(const auto& child : graph[curtip][0]){
                graph[curtip][0].erase(child);
                graph[child][1].erase(curtip);
                tips++;
                
                if(graph[child][1].size() == 0 && out_tips.find(child) == out_tips.end())
                    in_tips.insert(child);
            }
        }
    }

    void bfs_out_tips(){
         while(! out_tips.empty()){
            int curtip = *(out_tips.begin());
            out_tips.erase(curtip);

            for(const auto& parent : graph[curtip][1]){
                graph[curtip][1].erase(parent);
                graph[parent][0].erase(curtip);
                tips++;

                if(graph[parent][0].size() == 0) out_tips.insert(parent);
            }
        }
    }
};


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
    My dbGraph;
    vector<vector<set<int> > > graph = dbGraph.create();

    FindTips tips (graph);
    cout<<tips.tips_number()<<endl;
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


