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


struct vec{
    vector<double> val;
};


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vec*> value(n,nullptr);
        rep(i,n)
        {
            value[i] = new vec;
            value[i]->val.resize(n+1);
        }
        vector<double> ans(n,0);

        rep(i,n)
        {
            rep(j,n+1)
            {
                cin >> value[i]->val[j];
            }
        }

        double mul = 0;
        int pos = 0;

        rep(i,n)
        {

            // cout << "Start\n\n";
            // rep(zz,n)
            // {
            //     rep(qq,n+1)
            //     {
            //         cout << value[zz]->val[qq] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n\n\n";
            pos = n+3;
            rep(j,n+1)
            {
                if(round(value[i]->val[j]*1000)/1000!=0) {pos = j; break;}
            }
            // cout << "Pos " << pos << "\n"; 
            
            if(pos>n-1) continue;

            rep(j,n)
            {
                if(i==j) continue;
                if(value[j]->val[pos]==0) continue;

                mul = value[j]->val[pos]/value[i]->val[pos];

                rep(k,n+1)
                {
                    value[j]->val[k] -= mul*value[i]->val[k];
                }
            }

            // cout << "End\n\n";
            // rep(zz,n)
            // {
            //     rep(qq,n+1)
            //     {
            //         cout << value[zz]->val[qq] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n\n";
        }

        bool flag = false,flag1= false;

        rep(i,n)
        {
            flag = false,flag1= false;
            pos = n+3;
            rep(j,n)
            {
                if(round(value[i]->val[j]*1000.0)/1000.0!=0.0000) {
                    // cout << value[i]->val[j] << " Pos " << j <<"\n";
                    if(flag == true)
                    {
                        flag1 = true;
                        break;
                    }
                    pos = j;flag=true;}
            }
            if(flag1) break;
            if(pos>n-1) continue;

            {
                // cout << "Val " << value[i]->val[n] << " " << value[i]->val[pos] << " Pos " << pos  << " Ans ";
                ans[pos] = (value[i]->val[n])/value[i]->val[pos];
                ans[pos] = round(ans[pos]*100000.0)/100000.0;
                // cout << ans[pos] << "\n";
            }
                
        }

        if(flag1)
        {
            rep(i,n)
            {
                cout << 0.00000 << " ";
            }
        }
        else
        {
            rep(i,n)
            {
                if((ans[i])<=0.00001 && ans[i]>=-0.000001) ans[i] = 0.0;
                cout << ans[i] << " ";
            }

        }


    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(6) << fixed;
    Expresso
    solve();
    return 0;
}