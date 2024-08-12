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




void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s1,s2;
        cin >> s1>>s2;
        vector<vector<int> > vv(s1.size()+1,vector<int>(s2.size()+1,0));

        for(int i =1;i<=s1.size();i++) vv[i][0] = i;
        for(int i =1;i<=s2.size();i++) vv[0][i] = i;

        int ins = 0,dele =0, rep = 0, eq = 0;

        for(int i =1;i<=s1.size();i++)
        {
            for(int j = 1;j<=s2.size();j++)
            {
                ins = vv[i][j-1] + 1;
                dele = vv[i-1][j] + 1;
                eq = vv[i-1][j-1];
                rep = vv[i-1][j-1]+1;
                if(s1[i-1]==s2[j-1])
                {
                    vv[i][j] = min(min(ins,dele),eq);
                }
                else
                {
                    vv[i][j] = min(min(ins,dele),rep);
                }
            }
        }
        // rep(i,s1.size()+1)
        // {
        //     rep(j,s2.size()+1)
        //     {
        //         cout << vv[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << vv[s1.size()][s2.size()];
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


