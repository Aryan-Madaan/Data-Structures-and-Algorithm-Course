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

ll pppp = 1000000007,xxxx = 107,pppp1 = 1000000009;

vector<ll> polyhash(string &s,ll &pp)
{
    ll temp = 0;
    vector<ll> fnl;
    fnl.push_back(0);
    rep(i,s.size())
    {
        temp = (s[i] + xxxx*fnl[fnl.size()-1])%pp;
        fnl.push_back(temp);
    }
    return fnl;
}

void solve()
{
    string ss,tt;
    vector<ll> val,val1;
    val.push_back(1);
    rep(i,100001)
    {
        val.push_back((xxxx*val[val.size()-1])%pppp);
    }
    val1.push_back(1);
    rep(i,100001)
    {
        val1.push_back((xxxx*val1[val1.size()-1])%pppp1);
    }
    while(cin >> ss >> tt)
    {
        vector<ll> hash11 = polyhash(ss,pppp), hash12 = polyhash(ss,pppp1), hash21 = polyhash(tt,pppp), hash22 = polyhash(tt,pppp1);
        int l = 1, r = min(ss.size(),tt.size()), mid = 0;
        int out1 = 0, out2 =0, out3 = 0;
        ll fin_hash = 0, fin_hash1 = 0;
        while(l<=r)
        {
            mid = (l+r)/2;
            unordered_map<ll,int> mpp,mpp1;
            for(int i = 0;i+mid<=ss.size();i++)
            {
                fin_hash = (hash11[i+mid] - (val[mid]*hash11[i])%pppp + pppp)%pppp;
                fin_hash1 = (hash12[i+mid] - (val1[mid]*hash12[i])%pppp1 + pppp1)%pppp1;
                mpp[fin_hash] = i;
                mpp1[fin_hash1] = i;
            }
            bool flag = 0;
            for(int i = 0;i+mid<=tt.size();i++)
            {
                fin_hash = (hash21[i+mid] - (val[mid]*hash21[i])%pppp + pppp)%pppp;
                fin_hash1 = (hash22[i+mid] - (val1[mid]*hash22[i])%pppp1 + pppp1)%pppp1;
                if(mpp.find(fin_hash)!=mpp.end() && mpp1.find(fin_hash1) != mpp1.end())
                {
                    flag = 1;
                    out1 = mpp[fin_hash];
                    out2 = i;
                    out3 = mid;
                    break;
                }
            }
            if(flag)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        cout << out1 << " " << out2 << " " << out3 << "\n"; 
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


 