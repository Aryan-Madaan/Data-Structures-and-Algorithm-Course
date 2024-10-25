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




void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string p,t,s;
        cin >> p >> t;
        s = p + '$' + t;
        vector<int> res,prefix(s.size(),0);
        int border = 0;
        for(int i =1;i< s.size();i++)
        {
            while(border>0 && s[i] != s[border])
            {
                border = prefix[border-1];
            }
            if(s[i]==s[border])
            {
               border++;
            }
            else
            {
                border = 0;
            }
            prefix[i] = border;
        }
        for(int i = p.size()+1;i<s.size();i++)
        {
            if(prefix[i] == p.size())
            {
                res.push_back(i - 2*p.size());
            }
        }
        rep(i,res.size())
        {
            cout << res[i] << " ";
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


