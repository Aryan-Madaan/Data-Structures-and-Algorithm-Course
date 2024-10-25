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


int start, cur,mid,prev1,midPrev;

int dict(char s)
{
    switch (s)
    {
        case '$':
            return 0;
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return -1;
    }
}

vector<int> sortdoubled(string &s, int &l, vector<int> &order, vector<int> &cls, vector<int>& tmporder)
{
    
    vector<int> cnt(s.size(),0);
    rep(i,s.size())
    {
        ++cnt[cls[i]];
    }
    for(int j = 1; j<s.size(); j++)
    {
        cnt[j] += cnt[j-1];
    }
    for(int i =s.size()-1;i>=0;i--)
    {
        start = (order[i] + s.size() - l)%(s.size());
        --cnt[cls[start]];
        tmporder[cnt[cls[start]]] = start;
    }
    return tmporder;
}

vector<int> updatecls(vector<int> &order, vector<int> &cls, int &l, vector<int>& tmpcls)
{
    tmpcls[order[0]] = 0;
    for(int i =1;i<order.size();i++)
    {
        cur = order[i];
        prev1 = order[i-1];
        mid = cur + l;
        midPrev = (prev1 + l)%(order.size());
        if(cls[cur]!=cls[prev1] || cls[mid]!=cls[midPrev])
        {
            tmpcls[cur] = tmpcls[prev1] + 1;
        }
        else
        {
            tmpcls[cur] = tmpcls[prev1];
        }
    }
    return tmpcls;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<int> order(s.size(),0),cls(s.size(),0), tmporder(s.size(),0),tmpcls(s.size(),0), count(5,0);
        rep(i,s.size())
        {
            ++count[dict(s[i])];
        }
        for(int i = 1;i<5;i++)
        {
            count[i] += count[i-1];
        }
        for(int i = s.size()-1; i>=0;i--)
        {
            --count[dict(s[i])];
            order[count[dict(s[i])]] = i;
        }

        cls[order[0]] = 0;
        for(int i =1;i<s.size();i++)
        {
            if (s[order[i]]!=s[order[i-1]])
            {
                cls[order[i]] = cls[order[i-1]] + 1;
            }
            else
            {
                cls[order[i]] = cls[order[i-1]];
            }
        }

        int l = 1;
        while(l<s.size())
        {
            order = sortdoubled(s,l,order,cls,tmporder);
            cls = updatecls(order,cls,l,tmpcls);
            l *= 2;
        }
        
        rep(i,order.size())
        {
            cout << order[i] << " ";
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


