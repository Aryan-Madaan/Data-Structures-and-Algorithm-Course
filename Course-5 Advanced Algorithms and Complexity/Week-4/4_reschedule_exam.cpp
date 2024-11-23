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

void add_edge(vector<vector<int>> &graph, vector<vector<int>> &rev_graph, int u, int v) {

    int u_neg,v_neg;
    // cout << u << " " << v << " ";
    // ++u;++v;

    if(u<0){
        u_neg = 2*(abs(u)-1);
        u = 2*(abs(u)-1) + 1;
    }
    else
    {
        u_neg = 2*(abs(u)-1) + 1;
        u = 2*(abs(u)-1);
    }
    if(v<0)
    {
        v_neg = 2*(abs(v)-1);
        v = 2*(abs(v)-1) + 1;
    }
    else
    {
        v_neg = 2*(abs(v)-1) + 1;
        v = 2*(abs(v)-1);
    }

    // cout << u << " " << v << " " << u_neg << " " << v_neg<< " " << graph.size() << " " << rev_graph.size()<< "\n";

    graph[u_neg].pb(v);
    graph[v_neg].pb(u) ;

    rev_graph[v].pb(u_neg);
    rev_graph[u].pb(v_neg);
    // graph[u].pb(v);
    // rev_graph[v].pb(u);
}

void dfs_post_order(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &finish_stack, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs_post_order(graph, visited, finish_stack, neighbor);
    }
    finish_stack.push(node);
}

void dfs_assign_scc(vector<vector<int>> &rev_graph, vector<bool> &visited, vector<int> &scc_label, int node, int scc_num) {
    visited[node] = true;
    scc_label[node] = scc_num;
    for (int neighbor : rev_graph[node]) {
        if (!visited[neighbor])
            dfs_assign_scc(rev_graph, visited, scc_label, neighbor, scc_num);
    }
}

void solve_2sat(int n, int m, const string &colors, vector<pair<int, int>> &edges) {
    int vars = 3 * n;
    vector<vector<int>> graph(2 * vars), rev_graph(2 * vars);
    int u,v;

    // Step 1: Build the implication graph
    for (int i = 0; i < n; ++i) {
        int base = 3 * i + 1;
        if (colors[i] == 'R') {
            add_edge(graph, rev_graph, base + 1, base + 2); // G -> B
            add_edge(graph, rev_graph, base + 2, base + 1); // B -> G
        } else if (colors[i] == 'G') {
            add_edge(graph, rev_graph, base + 2, base + 0); // B -> R
            add_edge(graph, rev_graph, base + 0, base + 2); // R -> B
        } else if (colors[i] == 'B') {
            add_edge(graph, rev_graph, base + 0, base + 1); // R -> G
            add_edge(graph, rev_graph, base + 1, base + 0); // G -> R
        }

        // Each color should not conflict with itself
        add_edge(graph, rev_graph, -(base + 0), -(base + 1)); // R -> R
        add_edge(graph, rev_graph, -(base + 1), -(base + 2)); // G -> G
        add_edge(graph, rev_graph, -(base + 2), -(base + 0)); // B -> B
    }

    rep(i,edges.size()) {
        u = edges[i].first - 1; v = edges[i].second - 1;
        int base_u = 3 * u + 1, base_v = 3 * v + 1;
        for (int k = 0; k < 3; ++k) {
            add_edge(graph, rev_graph, -(base_u + k), -(base_v + k));
            add_edge(graph, rev_graph, -(base_v + k), -(base_u + k));
        }
    }

    // Step 2: Kosaraju's Algorithm to find SCCs
    stack<int> finish_stack;
    vector<bool> visited(2 * vars, false);

    // First pass: Order vertices
    for (int i = 0; i < 2 * vars; ++i) {
        if (!visited[i])
            dfs_post_order(graph, visited, finish_stack, i);
    }

    // Second pass: Assign SCCs
    fill(visited.begin(), visited.end(), false);
    vector<int> scc_label(2 * vars, -1);
    int scc_num = 0;

    while (!finish_stack.empty()) {
        int node = finish_stack.top();
        finish_stack.pop();
        if (!visited[node]) {
            dfs_assign_scc(rev_graph, visited, scc_label, node, scc_num);
            scc_num++;
        }
    }

    // Step 3: Check satisfiability
    for (int i = 0; i < vars; ++i) {
        if (scc_label[2 * i] == scc_label[2 * i + 1]) {
            cout << "Impossible\n";
            return;
        }
    }

    // Step 4: Assign values
    vector<int> assignment(vars, -1);
    vector<pair<int, int>> scc_order;
    for (int i = 0; i < 2 * vars; ++i)
        scc_order.emplace_back(scc_label[i], i);
    sort(scc_order.rbegin(), scc_order.rend());

    rep(i,scc_order.size()){
        int var = scc_order[i].second / 2;
        if (assignment[var] == -1) {
            assignment[var] = (scc_order[i].second % 2 == 0) ? 1 : 0;
        }
    }

    // Step 5: Output result
    for (int i = 0; i < n; ++i) {
        int base = 3 * i;
        if (assignment[base])
            cout << 'R';
        else if (assignment[base + 1])
            cout << 'G';
        else
            cout << 'B';
    }
    cout << "\n";
}

void solve() {
    int n, m;
    cin >> n >> m;
    string colors;
    cin >> colors;
    vector<pair<int, int>> edges(m);
    rep(i,m)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    solve_2sat(n, m, colors, edges);
}

int main() {
   cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(15) << fixed;
    Expresso
    solve();
    return 0;
}