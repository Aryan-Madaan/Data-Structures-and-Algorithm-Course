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


void printEulerianPath(vector<vector<int>>& adjList) {
    stack<int> currPath;
    vector<int> eulerPath;

    int startVertex = 0;
    currPath.push(startVertex);

    while (!currPath.empty()) {
        int curr = currPath.top();

        if (!adjList[curr].empty()) {
            int next = adjList[curr].back();
            currPath.push(next);

            // Remove the edge
            adjList[curr].pop_back();
        } else {
            eulerPath.push_back(curr);
            currPath.pop();
        }
    }

    for (int i = eulerPath.size() - 1; i >= 1; --i) {
        cout << eulerPath[i] + 1 << " ";
    }
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int> > graph(n,vector<int>()),graph1(n,vector<int>(n,0));
        int v,u;

        rep(i,m){
            cin >> v >> u;
            --u; -- v;
            graph[v].pb(u);
            graph1[v][u]++;
        }

        vector<int> sum(n,0);

        rep(i,n)
        {
            rep(j,n)
            {
                sum[i]+=graph1[i][j];
                sum[i] += graph1[j][i];
            }
        }


        bool flag = 1;

        rep(i,n)
        {
            // cout << sum[i] << " ";
            if(sum[i]%2!=0)
            {
                flag = 0;
                break;
            }
        }
        // cout << "\n";
        if(!flag)
        {
            cout << 0;
        }
        else
        {
            cout << 1 << "\n";
            printEulerianPath(graph);
        }
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


