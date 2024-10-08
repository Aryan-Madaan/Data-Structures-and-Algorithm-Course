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

int pppp = 1000000007;
long long xxxx = 7;

vector<int> polyhash(string s,vector<ll>&val)
{
    vector<int> final;
    long long temp = 0;
    final.push_back(0);
    for(int i =0;i<s.size();i++)
    {
        temp = (long long)(s[i] +  ((temp*(ll)xxxx)%pppp))%pppp;
        temp %= pppp;
        final.push_back(temp);
        // cout << "s[i] == " << s[i] << " ASCII = " << (long long)s[i] << " pow= " << (long long)pow(xxxx,i) << " temp == " << ((long long)s[i] * (long long)pow(xxxx,i)) % pppp << "\n";
    }
    return final;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<ll> val;
        val.push_back(1);
        rep(i,s.size()-1)
        {
            val.push_back((xxxx*val[val.size()-1])%pppp);
        }
        vector<int> hash = polyhash(s,val);
        int n,a,b,l;
        cin >> n;
        // string ss,ss1;
        // for(int i =1;i<=s.size();i++)
        // {
        //     ss.push_back(s[i-1]);
        //     // cout << ss << " : "<<  hash[i] << "\n";
        // } 

        // for(int i =1;i<=s.size();i++)
        // {
        //     ss = "";
        //     cout << "\ni == " << i << "\n";
        //     for(int j = i+1;j<=s.size();j++)
        //     {
        //         ss.push_back(s[j-1]);
        //         cout << ss << (hash[j] - (val[j-i]*hash[i])%pppp)%pppp << "\n";
        //     }
        // }     
        // cout << "\n";
        rep(i,n)
        {
            cin >> a >> b >> l;
            // rep(i,l)
            // {
            //     cout << s[a+i];
            // }
            // cout << "\n";
            // rep(i,l)
            // {
            //     cout << s[b+i];
            // }
            // cout << "\n";
            int hash1 = ((long long)hash[a+l] - (long long)(val[l]*hash[a])%pppp + pppp)%pppp;
            int hash2 = ((long long)hash[b+l] - (long long)(val[l]*hash[b])%pppp + pppp)%pppp;
            // cout << hash1 << " " << hash2 << "\n";
            // cout << 
            if(hash1 == hash2)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
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


