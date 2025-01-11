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

int f_starting_point(const map<int, int>& opts, vector<int>& last_ones){
    while(!last_ones.empty()){
        int start = last_ones.back();
        last_ones.pop_back();

        if(opts.find(start) != opts.end())
            return start;
    }
}

void eulerian_path(vector<vector<int>>& graph, vector<int>& path){
    int n = graph.size();
    vector<int> last_ones(1, 0);
    map<int, int> startguess;
    vector<int> new_cycle;

    path.push_back(0);
    startguess[0] = 0;

    while(!startguess.empty()){
        int start = f_starting_point(startguess, last_ones);
        int position = startguess[start];

        int next_node, cur_node;
        cur_node = start;
        int pos = position;

        do{
            next_node = graph[cur_node].back();
            new_cycle.push_back(next_node);
            graph[cur_node].pop_back();


            if(graph[cur_node].size()) {startguess[cur_node] = pos; last_ones.push_back(cur_node);}
            else                        startguess.erase(cur_node);

            pos++;
            cur_node = next_node;

        }while(cur_node != start);

        path.insert(path.begin() + position + 1, new_cycle.begin(), new_cycle.end());
        new_cycle.clear();
    }
}

void add_edge(vector<vector<int> >& graph, const string& kmer, vector<string>& k_1_mers){
    static int k_1 = kmer.size() - 1;
    static int vertex = 0;
    static map<string, int> labels;

    string L_kmer = kmer.substr(0, k_1);
    string R_kmer = kmer.substr(1, k_1);
    int L_label, R_label;

    if(labels.find(L_kmer) != labels.end()) L_label = labels[L_kmer];
    else { graph.push_back(vector<int>()); L_label = labels[L_kmer] = vertex++; k_1_mers.push_back(L_kmer); }

    if(labels.find(R_kmer) != labels.end()) R_label = labels[R_kmer];
    else { graph.push_back(vector<int>()); R_label = labels[R_kmer] = vertex++;   k_1_mers.push_back(R_kmer); }

    graph[L_label].push_back(R_label);
}

void k_1_compositions(vector<vector<int>>& graph, const string& kmer, vector<string>& k_1_mers, int from=0){
    static int k = kmer.size();
    add_edge(graph, kmer, k_1_mers);

    for(int i = from; i < k; i++){
        string newKmer = kmer;
        newKmer[i] = char('0'+(((kmer[i]-'0')+1)%2));
        k_1_compositions(graph, newKmer, k_1_mers, i+1);
    }

}

vector<vector<int> > de_bruijn_graph(vector<string>& k_1_mers){
    int k;
    cin >> k;

    vector<vector<int> > graph;
    string first_kmer (k, '0');
    k_1_compositions(graph, first_kmer, k_1_mers);

    return graph;
}

void build_k_universal_string(const vector<string>& k_1_mers, vector<int>& path, string& result){
    stringstream universal_string;
    universal_string << k_1_mers[path[1]];
    int k_1 = k_1_mers[0].size();

    for(int i = 2; i<path.size()-1; i++)
        universal_string << k_1_mers[path[i]][k_1 - 1];

    result = universal_string.str();
    int border_zeros = result.find('1') + (result.size() - result.find_last_of('1') - 1);

    result = result.substr(0, result.size() - (border_zeros - (k_1 + 1)));
}

void solve()
{
    int t=1;
    while(t--)
    {
        vector<string> k_1_mers;
        vector<vector<int> > graph = de_bruijn_graph(k_1_mers);

        vector<int> path;
        eulerian_path(graph, path);

        string k_universal_string;
        build_k_universal_string(k_1_mers, path, k_universal_string);
        cout<<k_universal_string<<endl;
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


