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

long long pppp = 1000000007;
long long xxxx = 263;

int polyhash(string &s,int &m,vector<ll>&val)
{
    long long temp = 0;
    for(ll i =0;i<s.size();i++)
    {
        temp += ((long long)(s[i] * val[i]))%pppp;
        temp %= pppp;
        // cout << "s[i] == " << s[i] << " ASCII = " << (long long)s[i] << " pow= " << (long long)pow(xxxx,i) << " temp == " << ((long long)s[i] * (long long)pow(xxxx,i)) % pppp << "\n";
    }
    return (temp%(long long)m + m)%m;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,m;
        cin >> m >> n;
        string q,s;
        int temp = 0,hash = 0;
        vector<ll> val;
        val.push_back(1);
        rep(i,14)
        {
            val.push_back((xxxx*val[val.size()-1])%pppp);
        }
        vector<vector<string> > vv(m+1,vector<string>());
        rep(i,n)
        {
            cin >> q;
            if(q == "add")
            {
                cin >> s;
                hash = polyhash(s,m,val);
                // cout << "Hashing: " << s << "  Hash is " << hash << "\n";
                bool f = 0;
                rep(k,vv[hash].size())
                {
                    if(vv[hash][k] == s)
                    {
                        f = 1;
                        break;
                    }
                }
                if(!f)
                {
                    vv[hash].push_back(s);
                }
            }
            else if(q == "del")
            {
                cin >> s;
                hash = polyhash(s,m,val);
                rep(k,vv[hash].size())
                {
                    if(vv[hash][k] == s)
                    {
                        vv[hash].erase(vv[hash].begin()+k);
                        break;
                    }
                }
            }
            else if(q == "find")
            {
                cin >> s;
                hash = polyhash(s,m,val);
                bool f = 0;
                rep(k,vv[hash].size())
                {
                    if(vv[hash][k] == s)
                    {
                        f = 1;
                        break;
                    }
                }
                if(f)
                {
                    cout << "yes\n";
                }
                else
                {
                    cout << "no\n";
                }
            }
            else if(q == "check")
            {
                cin >> temp;
                for(int j = vv[temp].size()-1; temp<m&&j>=0; j--)
                {
                    cout << vv[temp][j] << " ";
                }
                cout << "\n";
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


