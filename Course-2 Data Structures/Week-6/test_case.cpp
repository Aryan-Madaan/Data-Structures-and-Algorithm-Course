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
        rep(i,300000)
        {cout << (char)(rand()%26 + 97);}
        cout << "\n" << 100000 << "\n";
        rep(i,100000)
        {
            int r1 = rand()%200000 - 1 ;
            int r2 = rand()%200000 + r1 -1 ;
            r2 = min(r2,200000-1);
            int r3 = rand()%(200000-(r2-r1));
            cout << r1  << " " << r2 << " " << r3;
            if(i!=(100000-1))
            {
                cout <<"\n";
            }
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


