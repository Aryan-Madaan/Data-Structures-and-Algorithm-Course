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


int calc(vector<int>&vv,int i,int W1,int W2,int W3)
{
    if (W1 ==0 && W2==0 && W3 ==0 && i==vv.size())
    {
        return 1;
    }
    else if(i>=vv.size())
    {
        return 0;
    }
    else
    {
        int ans1=0,ans2=0,ans3=0;
        if(W1>=vv[i])
        {
            ans1 = calc(vv,i+1,W1-vv[i],W2,W3);
        }
        if(W2>=vv[i])
        {
            ans2 = calc(vv,i+1,W1,W2-vv[i],W3);
        }
        if(W3>=vv[i])
        {
            ans3 = calc(vv,i+1,W1,W2,W3-vv[i]);
        }

        return max(max(ans1,ans2),ans3);
    }
}



void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n = 0,sum = 0;
        cin >> n;
        vector<int>vv(n,0);
        rep(i,n) 
        {
            cin >> vv[i];
            sum += vv[i];
        }
        if(sum%3!=0)
        {
            cout << 0;
        }
        else
        {
            cout << calc(vv,0,sum/3,sum/3,sum/3);
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


