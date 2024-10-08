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



ll pppp = 1e9 + 7,xxxx = 107,pppp1 = 1000000009;

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
    string s,t;
    int k;
    vector<ll> val;
    val.push_back(1);
    rep(i,200002)
    {
        val.push_back((xxxx*val[val.size()-1])%pppp);
    }
    while(cin >> k >> s >> t)
    {
        vector<int> ans;
        vector<ll> hash1 = polyhash(s,pppp), hash2 = polyhash(t,pppp);
        // string ss;
        // for(int i =1;i<hash1.size();i++)
        // {
        //     ss.push_back(s[i-1]);
            // cout << i << " " << ss << " " << hash1[i] << "\n";
        // }
        // cout << "------------\n";
        // ss = "";
        // for(int i =1;i<hash2.size();i++)
        // {
        //     ss.push_back(t[i-1]);
        //     cout << i << " " <<  ss << " " << hash2[i] << "\n";
        // }
        // cout << "------------\n";
        int val1 = 0, r = 0, l =0, mid =0;
        ll fin_hash = 0, fin_hash1 = 0, good = 0;
        for(int i = 0; i<=s.size()-t.size();i++)
        {
            val1 = k;
            l = i;
            r = i + t.size()-1;
            good = i-1;
            while(val1>0)
            {
                while(l<=r)
                {
                    mid = (l+r)/2;
                    fin_hash = (hash1[mid + 1] - (val[mid-l+1]*hash1[l])%pppp + pppp)%pppp;
                    fin_hash1 = (hash2[mid - i + 1] - (val[mid-l+1]*hash2[l-i])%pppp + pppp)%pppp;
                    // fin_hash = (hash1[])
                    // cout << i << ":" << l << ":" << mid << ":" << r << ":  " << fin_hash << ":" << fin_hash1 << "\n";
                    if(fin_hash1 == fin_hash)
                    {
                        l = mid+1;
                        good = mid;
                        // cout << "good = " << good << "\n";
                    }
                    else
                    {
                        r = mid-1;
                    }
                }
                if(r==i+t.size()-1)
                {
                    break;
                }
                else
                {
                    val1--;
                    if(l==good)
                    {
                        good++;
                    }
                    else
                    {
                        good+=2;
                    }
                    l = good;
                    r = i + t.size()-1;
                }
            }
            if(k>0)
            {
                // l = good+1;
                if(l<=r)
                {
                    fin_hash = (hash1[r + 1] - (val[r-l+1]*hash1[l])%pppp + pppp)%pppp;
                    fin_hash1 = (hash2[r - i + 1] - (val[r-l+1]*hash2[l-i])%pppp + pppp)%pppp;
                    // cout << "\n-----\n" << i << ":" << l << ":" << mid << ":" << r << ":  " << fin_hash << ":" << fin_hash1 << "\n---\n";
                    if(fin_hash == fin_hash1)
                    {
                        ans.push_back(i);
                    } 
                }
                else
                {
                    ans.push_back(i);
                }
            }
            else
            {
                fin_hash = (hash1[i+t.size()] - (val[t.size()]*hash1[i])%pppp + pppp)%pppp;
                fin_hash1 = hash2[t.size()];
                if(fin_hash == fin_hash1)
                {
                    ans.push_back(i);
                }
            }
        }
        cout << ans.size() << " ";
        rep(i,ans.size()) cout << ans[i] << " ";
        cout << "\n";
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


