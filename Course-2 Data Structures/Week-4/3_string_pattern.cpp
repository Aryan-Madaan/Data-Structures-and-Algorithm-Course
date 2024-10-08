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
long long xxxx = 1;


int polyhash(string s,vector<ll>&val)
{
    long long temp = 0;
    for(ll i =0;i<s.size();i++)
    {
        temp += ((long long)(s[i] * val[i]))%pppp;
        temp %= pppp;
        // cout << "s[i] == " << s[i] << " ASCII = " << (long long)s[i] << " pow= " << (long long)pow(xxxx,i) << " temp == " << ((long long)s[i] * (long long)pow(xxxx,i)) % pppp << "\n";
    }
    return temp;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s,p;
        cin >> p >> s;
        vector<ll> vv(s.size()-p.size()+1,0);
        vector<ll> val;
        vector<int> mine;
        val.push_back(1);
        rep(i,p.size()-1)
        {
            val.push_back((xxxx*val[val.size()-1])%pppp);
        }
        ll myhash = polyhash(p,val);
        vv[s.size()-p.size()] = polyhash(s.substr(s.size()-p.size(),p.size()),val);

// cout << "My Hash = " << myhash << " j: " << s.size()-p.size() << " vv[j] = " << vv[s.size()-p.size()] << "\n";
        if(myhash == vv[s.size()-p.size()])
            {
                bool f = 1;
                for(int k = 0;k<p.size();k++)
                {
                    if(p[k] != s[k+s.size()-p.size()])
                    {
                        f = 0;
                        break;
                    }
                }
                if(f)
                mine.push_back(s.size()-p.size());
            }
        for(int j = s.size()-p.size()-1;j>=0;j--)
        {
            vv[j] =( (xxxx*vv[j+1] + (long long)s[j]  - val[val.size()-1]*((long long)s[j+p.size()]) )%pppp + pppp )%pppp;
            // cout << "My Hash = " << myhash << " j: " << j << " vv[j] = " << vv[j] << "\n";
            if(myhash == vv[j])
            {
                bool f = 1;
                for(int k = 0;k<p.size();k++)
                {
                    if(p[k] != s[k+j])
                    {
                        f = 0;
                        break;
                    }
                }
                if(f)
                mine.push_back(j);
            }
        }
        for(int i =mine.size()-1;i>=0;i--)
        {
            cout << mine[i] << " ";
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


