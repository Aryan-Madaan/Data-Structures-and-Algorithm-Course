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
// #define int long long;
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

void sep_into_num_op(vector<ll>&num,vector<int>&op,string &s)
{
    rep(i,s.size())
    {
        if(i%2==0)
        {
            num.push_back(s[i] - '0');
        }
        else
        {
            if(s[i]=='+')
            {
                op.push_back(1);
            }
            else if(s[i]=='-')
            {
                op.push_back(2);
            }
            else
            {
                op.push_back(3);
            }
        }
    }
}


pair<ll,ll> min_and_max(vector<vector<ll> > &mmin,vector<vector<ll> > &mmax,int i, int j,vector<int>&op)
{
    ll a=0,b=0,c=0,d=0,min1=LLONG_MAX,max1=LLONG_MIN;
    for(int k = i;k<=j-1;k++)
    {
        if(op[k]==1){
            a = mmax[i][k] + mmax[k+1][j];
            b = mmax[i][k] + mmin[k+1][j];
            c = mmin[i][k] + mmax[k+1][j];
            d = mmin[i][k] + mmin[k+1][j];
        }
        else if(op[k]==3)
        {
            a = mmax[i][k] * mmax[k+1][j];
            b = mmax[i][k] * mmin[k+1][j];
            c = mmin[i][k] * mmax[k+1][j];
            d = mmin[i][k] * mmin[k+1][j];
        }
        else
        {
            a = mmax[i][k] - mmax[k+1][j];
            b = mmax[i][k] - mmin[k+1][j];
            c = mmin[i][k] - mmax[k+1][j];
            d = mmin[i][k] - mmin[k+1][j];
        }
        min1 = min(min(min(a,b),min(c,d)),min1);
        max1 = max(max(max(a,b),max(c,d)),max1);
    }
    return mp(min1,max1);
}

ll my_func(vector<ll> &num,vector<int> &op,vector<vector<ll> > &mmin,vector<vector<ll> > &mmax)
{
    rep(i,num.size())
    {
        mmin[i][i] = num[i];
        mmax[i][i] = num[i];
    }
    pair<ll,ll> temp;
    for (int i= 1;i<=num.size()-1;i++)
    {
        for(int j= 0;j<num.size()-i;j++)
        {
            int k = i+j;
            temp = min_and_max(mmin,mmax,j,k,op);
            mmin[j][k] = temp.first;
            mmax[j][k] = temp.second;
        }
    }
    // cout << "\n\nMAX\n\n";
    // rep(i,num.size())
    // {
    //     rep(j,num.size())
    //     {
    //         cout << mmax[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "\n\nMIN\n\n";
    // rep(i,num.size())
    // {
    //     rep(j,num.size())
    //     {
    //         cout << mmin[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return mmax[0][num.size()-1];
}



void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<ll> num;
        vector<int> op;
        sep_into_num_op(num,op,s);
        int n = (s.size() + 1)/2;
        vector<vector<ll> > mmin(n,vector<ll>(n,0)),mmax(n,vector<ll>(n,0));
        cout << my_func(num,op,mmin,mmax);
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


