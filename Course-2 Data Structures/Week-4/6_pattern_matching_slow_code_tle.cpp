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

void fin(string &s,vector<ll> &val,vector<ll> &hash,unordered_map<ll,vector<int> > &mpp,int start,int k,int size,ll curr_hash,int start_val)
{
    if((size == 0 && k!=0) || size<0 || k<0 || start+size >s.size())
    {
        return;
    }
    if(k==0 && start+size <=s.size())
    {
        ll fin_hash = 0;
        if (size>0)
        {
            fin_hash = (hash[start+size] - (val[size]*hash[start])%pppp + pppp)%pppp;
            fin_hash = (fin_hash + val[size]*curr_hash)%pppp;
        }
        else
        {
            fin_hash = curr_hash;
        }
        // cout <<"\nFinal---\n" << start_val  << ":" << start+size << ":" << k <<":" << 0 << ":" << fin_hash%pppp << "\nEnd------\n";
        mpp[fin_hash].push_back(start_val);
        return;
    }
    for(int i = start; i <= start+size-(k-1);i++)
    {
        ll fin_hash = '|';
        if(i!=start)
        {
            fin_hash += (((hash[i] - (val[i-start]*hash[start])%pppp + pppp)%pppp)*xxxx)%pppp;
        }
        fin_hash += (curr_hash*val[i-start+1])%pppp;
        // cout << start_val  << ":" << start << ":" << i << ":" << k <<":" << size << ":" << fin_hash%pppp << "\n";
        fin(s,val,hash,mpp,i+1,k-1,size-(i-start+1),fin_hash%pppp,start_val);
    }
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
        unordered_map<ll,vector<int> > mpp,mpp1;
        unordered_map<ll,bool> mpp_fin;
        ll fin_hash = 0;
        for(int i = 0; i + t.size() <= s.size(); i++)
        {
            fin_hash = (hash1[i+t.size()] - (val[t.size()]*hash1[i])%pppp + pppp)%pppp;
            mpp[fin_hash].push_back(i);
        }
        // for(int i = 1; i<=k;i++)
        // { 
            rep(j,s.size()-t.size()+1)
            {
                fin(s,val,hash1,mpp,j,k,t.size(),0,j);
            }
        // }
        // cout << "\n-----------\n";
        fin_hash = (hash2[t.size()] - (val[t.size()]*hash2[0])%pppp + pppp)%pppp;
        mpp1[fin_hash].push_back(0);
        // for(int i = 1; i<=k; i++) 
        fin(t,val,hash2,mpp1,0,k,t.size(),0,0);
        // cout << "\n-----------\n"; 
        for(auto key:mpp1)
        {
            if(mpp.find(key.first)!=mpp.end())
            {
                // cout << "key: " << key.first << "\n";
                rep(i,mpp[key.first].size())
                {
                    mpp_fin[mpp[key.first][i]] = 0;
                }
            }
        }
        for(auto key:mpp_fin)
        {
            ans.push_back(key.first);
        }
        sort(ans.begin(),ans.end());
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


