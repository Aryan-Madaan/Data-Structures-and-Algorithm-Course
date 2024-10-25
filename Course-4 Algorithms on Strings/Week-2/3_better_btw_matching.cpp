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

int btw_matching(string &s,string &pattern,vector<int> &first,vector<vector<int> > &cnt)
{
    bool flag = false;
    int top = 0, bottom = s.size()-1;
    char sym;
    while (top <=bottom)
    {
        if(!pattern.empty())
        {
            sym = pattern[pattern.size()-1];
            pattern.pop_back();

            
            for(int i = top;i<bottom;i++)
            {
                if(sym == s[i])
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag)
            {
                // cout << "\n" << sym << " " << dict(sym) << " " << first[dict(sym)] <<  " top " << top << " " << cnt[top][dict(sym)] << " bot " << bottom << " " << cnt[bottom+1][dict(sym)] <<" ";
                top = first[dict(sym)] + cnt[top][dict(sym)];
                bottom = first[dict(sym)] + cnt[bottom+1][dict(sym)] - 1;
                if(bottom>=s.size()&&!pattern.empty())
                {
                    bottom = s.size()-1;
                }
                // cout << "final = " << top <<  "  " << bottom <<" \n";
            }
            else
            {
                return 0;
            }

            if(top>bottom) return 0;

            // if(top<0 || bottom>=s.size())
            // {
            //     cout << "\nError " << top << " " << bottom << " " << pattern << "\n";
            //     return 0;
            // }
        }
        else
        {
            return bottom - top + 1;
        }
    }
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        vector<int> cnt(5,0), first(5,0);

        vector< vector<int> > count(s.size()+1,vector<int>(5,0));

        // cout << "Printing Count \n";

        rep(i,5)
        {
            cnt[i] = 0;
        }

        rep(i,s.size()+1)
        {
            rep(j,5)
            count[i][dict(j)] = 0;
        }

        rep(i,s.size())
        {
            count[i+1]= count[i];
            count[i+1][dict(s[i])]++;
            cnt[dict(s[i])]++;
        }

        // cout << "Printing Count \n";

        // rep(i,s.size()+1)
        // {
        //     rep(j,5)
        //     cout << count[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n\n";

        // cout << "Printing Count 1 \n";

        // rep(i,5)
        // {
        //     cout << cnt[i] << " ";
        // }
        
        // cout << "\n\n";

        first[0] = 0;
        for(int i =1; i<5;i++)
        {
            first[i] = first[i-1] + cnt[i-1];
        }

        // cout << "\n Printing Queue\n";

        // rep(i,5)
        // {
        //     cout << first[i] << " ";
        // }
        // cout << "\n\n";

        int n;
        cin >> n;
        string pattern;
        rep(i,n)
        {
            cin >> pattern;
            cout << btw_matching(s,pattern,first,count) << " ";
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


