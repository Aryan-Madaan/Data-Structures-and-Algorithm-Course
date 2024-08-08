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
        int n;
        cin >> n;
        vector<int> calc(n+1,INT_MAX);
        vector<vector<int> >myvec(n+1,vector<int>());
        calc[1] = 0;
        calc[2] = 1;
        calc[3] = 1;
        myvec[1].push_back(1);
        myvec[3].push_back(1);
        myvec[3].push_back(3);
        myvec[2].push_back(1);
        myvec[2].push_back(2);
        for (int i =1;i<=n;i++)
        {
            if(i+1>n&&i+3>n&&i+4>n)
            {
                break;
            }
            if(i+1<=n)
            {
                if(calc[i]+1 < calc[i+1])
                {
                    myvec[i+1] = myvec[i];
                    myvec[i+1].push_back(i+1);
                }
                calc[i+1] = min(calc[i+1],calc[i]+1);
            }
            if(i*2<=n)
            {
                if(calc[i]+1 < calc[i*2])
                {
                    myvec[i*2] = myvec[i];
                    myvec[i*2].push_back(i*2);
                }
                calc[i*2] = min(calc[i*2],calc[i]+1);

            }
            if(i*3<=n)
            {
                if(calc[i]+1 < calc[i*3])
                {
                    myvec[i*3] = myvec[i];
                    myvec[i*3].push_back(i*3);
                }
                calc[i*3] = min(calc[i*3],calc[i]+1);
            }
        }
        cout << calc[n] << "\n";
        rep(i,myvec[n].size()) cout << myvec[n][i] << " ";
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


