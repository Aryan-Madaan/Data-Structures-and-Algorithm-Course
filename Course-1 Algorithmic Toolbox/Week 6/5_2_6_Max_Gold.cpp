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


int trial(vector<vector<int> > &myVec,vector<int> &vv,int W,int n)
{
    if(n<0||W<0) return 0;
    int val = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=W;j++)
        {
            myVec[i][j] = myVec[i-1][j];
            // trial(myVec,vv,W,n-1);
            if (vv[i-1] <= j)
            {
                val = myVec[i-1][j-vv[i-1]] + vv[i-1]; //trial(myVec,vv,W-vv[i],n-1) + vv[i];
                if(myVec[i][j]<val)
                {
                    myVec[i][j]=val;
                }
            }
        }
    }
    return myVec[n][W];
}



void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int w,n;
        cin >> w >>n;
        vector<int> vv(n,0);
        vector<vector<int> > myVec(n+1,vector<int>(w+1,0));
        rep(i,n) myVec[i][0] = 0;
        rep(j,w) myVec[0][j] = 0;
        rep(i,n)
        {
            cin >> vv[i];
        }
        cout << trial(myVec,vv,w,n);
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


