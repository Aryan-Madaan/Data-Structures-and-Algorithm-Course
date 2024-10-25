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
        string s,t;
        cin >> s;
        t = s;
        sort(t.begin(),t.end());
        vector<string>f;
        unordered_map<string,int> bck; // fnt
        unordered_map<char,int> cnt_fnt,cnt_bck;
        string final;
        f.reserve(2*s.size());
        rep(i,s.size())
        {
            if(cnt_fnt.find(t[i])!=cnt_fnt.end())
            {
                cnt_fnt[t[i]]++;
            }
            else
            {
                cnt_fnt[t[i]] = 1;
            }
            // fnt[t[i] + to_string(cnt_fnt[t[i]])] = i;
            f.push_back(t[i] + to_string(cnt_fnt[t[i]]));
            if(cnt_bck.find(s[i])!=cnt_bck.end())
            {
                cnt_bck[s[i]]++;
            }
            else
            {
                cnt_bck[s[i]]=1;
            }
            bck[s[i] + to_string(cnt_bck[s[i]])] = i;
            // b.push_back(s[i] + to_string(cnt_bck[s[i]]));
        }
        int start = 0;
        while(final.size()<s.size())
        {
            start = bck[f[start]];
            final.push_back(t[start]);
        }
        cout << final;
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


