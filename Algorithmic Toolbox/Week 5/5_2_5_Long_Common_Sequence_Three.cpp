//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
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

int findans(vector<int> &v1,vector<int> &v2)
{
    int n =v1.size(),m = v2.size();
    vector<vector<int> > vv(n+1,vector<int>(m+1,0));

    int ins = 0,dele =0, rep = 0, eq = 0;

    for(int i =1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            ins = vv[i][j-1];
            dele = vv[i-1][j];
            eq = vv[i-1][j-1]+1;
            rep = vv[i-1][j-1];
            if(v1[i-1]==v2[j-1])
            {
                vv[i][j] = max(max(ins,dele),eq);
            }
            else
            {
                vv[i][j] = max(max(ins,dele),rep);
            }
        }
    }
    return vv[n][m];
}

vector<int> findseq(vector<int> &v1,vector<int> &v2)
{
    int n =v1.size(),m = v2.size();
    vector<vector<int> > vv(n+1,vector<int>(m+1,0));
    vector< vector<vector<int> > >seq(n+1,vector<vector<int> >(m+1));

    int ins = 0,dele =0, rep = 0, eq = 0;

    for(int i =1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            ins = vv[i][j-1];
            dele = vv[i-1][j];
            eq = vv[i-1][j-1]+1;
            rep = vv[i-1][j-1];
            if(v1[i-1]==v2[j-1])
            {
                if(eq>=ins&&eq>=dele)
                {
                    seq[i][j] = seq[i-1][j-1];
                    seq[i][j].push_back(v1[i-1]);
                }
                else if(ins>=eq&&ins>=dele)
                {
                    seq[i][j] = seq[i][j-1];
                }
                else if(dele>=ins&&dele>=eq)
                {
                    seq[i][j] = seq[i-1][j];
                }
                vv[i][j] = max(max(ins,dele),eq);
            }
            else
            {
                if(rep>=ins&&rep>=dele)
                {
                    seq[i][j] = seq[i-1][j-1];
                }
                else if(ins>=rep&&ins>=dele)
                {
                    seq[i][j] = seq[i][j-1];
                }
                else if(dele>=ins&&dele>=rep)
                {
                    seq[i][j] = seq[i-1][j];
                }
                vv[i][j] = max(max(ins,dele),rep);
            }
        }
    }
    return seq[n][m];
}




void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n;
        vector<int>v1(n,0);
        rep(i,n) cin >> v1[i];
        cin >> m;
        vector<int>v2(m,0);
        rep(i,m) cin >> v2[i];
        cin >> k;
        vector<int>v3(k,0);
        rep(i,k) cin >> v3[i];

        vector<int> ans1 = findseq(v1,v2);
        vector<int> ans2 = findseq(v2,v3);
        vector<int> ans3 = findseq(v1,v3);

        int result = max(max(findans(ans1,v3),findans(ans2,v1)),findans(ans3,v2));
        // vector< vector<int> > vv1(seq[n][m].size()+1,vector<int>(k+1,0));

        // for(int i =1;i<=n;i++)
        // {
        //     for(int j = 1;j<=m;j++)
        //     {
        //         ins = vv1[i][j-1];
        //         dele = vv1[i-1][j];
        //         eq = vv1[i-1][j-1]+1;
        //         rep = vv1[i-1][j-1];
        //         if(seq[n][m][i-1]==v3[j-1])
        //         {
        //             vv1[i][j] = max(max(ins,dele),eq);
        //         }
        //         else
        //         {
        //             vv1[i][j] = max(max(ins,dele),rep);
        //         }
        //     }
        // }

        cout << result;
        // <<"\n";
        // rep(i,seq[n][m].size()) cout << seq[n][m][i] << " ";
        // cout << "\n";
        // cout << vv1[seq[n][m].size()][m];
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


