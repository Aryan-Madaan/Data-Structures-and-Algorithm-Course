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

void findSubsets(int m, int n,vector<vector<bool> > &bits) {
    int total = m + n + 1;

    // Use bitset to represent inclusion/exclusion

    // Prepare a bit pattern where exactly m bits are set
    vector<bool> bitPattern(total, false);
    fill(bitPattern.begin(), bitPattern.begin() + m, true);

    do {
        bits.pb(bitPattern);
    } while (prev_permutation(bitPattern.begin(), bitPattern.end()));
}

pair<int,vector<double> > find_ans(vector<vector<double> > value,int m)
{
        // int n = 10;
        // rep(i,n)
        // {
        //     value[i] = new vec;
        //     value[i]->val.resize(n+1);
        // }
        vector<double> ans(m,0);

        // rep(i,n)
        // {
        //     rep(j,n+1)
        //     {
        //         cin >> value[i][j];
        //     }
        // }

        double mul = 0;
        int pos = 0;

        rep(i,m)
        {

            // cout << "Start\n\n";
            // rep(zz,m)
            // {
            //     rep(qq,m+1)
            //     {
            //         cout << value[zz][qq] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n\n\n";
            pos = m+3;
            rep(j,m+1)
            {
                if(round(value[i][j]*1000)/1000!=0) {pos = j; break;}
            }
            // cout << "Pos " << pos << "\n"; 
            
            if(pos>m-1) continue;

            rep(j,m)
            {
                if(i==j) continue;
                if(value[j][pos]==0) continue;

                mul = value[j][pos]/value[i][pos];

                rep(k,m+1)
                {
                    value[j][k] -= mul*value[i][k];
                }
            }

            // cout << "End\n\n";
            // rep(zz,m)
            // {
            //     rep(qq,m+1)
            //     {
            //         cout << value[zz][qq] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n\n";
        }

        bool flag = false,flag1= false;

        rep(i,m)
        {
            flag = false,flag1= false;
            pos = m+3;
            rep(j,m)
            {
                if(round(value[i][j]*100000.0)/100000.0!=0.000000) {
                    // cout << value[i]->val[j] << " Pos " << j <<"\n";
                    if(flag == true)
                    {
                        flag1 = true;
                        break;
                    }
                    pos = j;flag=true;}
            }
            if(flag1) break;
            if(pos>m-1) continue;

            {
                // cout << "Val " << value[i]->val[n] << " " << value[i]->val[pos] << " Pos " << pos  << " Ans ";
                ans[pos] = (value[i][m])/value[i][pos];
                ans[pos] = round(ans[pos]*100000.0)/100000.0;
                // cout << ans[pos] << "\n";
            }
                
        }


        // if(flag1)
        // {
        //     rep(i,m)
        //     {
        //         cout << 0.00000 << " ";
        //     }
        // }
        // else
        // {
        //     rep(i,m)
        //     {
        //         if((ans[i])<=0.00001 && ans[i]>=-0.000001) ans[i] = 0.0;
        //         cout << ans[i] << " ";
        //     }

        // }
        // cout<< "\n";

        if(flag1)
        {
            return mp(0,vector<double>(m,0));
        }
        else
        {
            // bool flag2 = false;
            rep(i,m)
            {
                // if(ans[i]>=1e10) {
                //     flag2 = 1;
                //     break;
                // }
                if((ans[i])<=0.00001 && ans[i]>=-0.00001) ans[i] = 0.0;
            }
            // if(flag2)
            // {
            //     return mp(2,ans);
            // }
            // else
            // {
                // cout << "Solution Found\n";
                return mp(1,ans);
            // }
        }

        // return mp(0,vector<double>(m,0));
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {

        int n,m;
        cin >> n >> m;
        vector<int> pleasure(m,0);
        vector<vector<double> > matrix(m+n,vector<double>(m+1,0));

        rep(i,n)
        {
            rep(j,m)
            {
                cin >> matrix[i][j];
            }
        }

        rep(i,m)
        {
            matrix[n+i][i]=-1;
        }

        rep(i,n)
        {
            cin >> matrix[i][m];
        }

        rep(i,m)
        {
            cin >> pleasure[i];
        }

        // rep(zz,m+n)
        // {
        //     rep(qq,m+1)
        //     {
        //         cout << matrix[zz][qq] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n";

        vector<vector<bool> > bits;

        findSubsets(m,n,bits);

        pair<int,vector<double> > myp,curr;

        bool flag = true;
        double val = 0,max_val = -LLONG_MIN;
        curr.first = -1;
        myp.first=0;

        // cout << "Bits size: " << bits.size() << " "  << bits[0].size() << "\n";

        vector<double> vall(m+1,1);
        vall[m] =  1e10;

        matrix.push_back(vall);

        rep(i,bits.size())
        {
            vector<vector<double> >  matrix_cp;
            // cout << "Bits " << i << " Value\n";
            rep(j,bits[i].size())
            {
                // cout << bits[i][j] << " ";
                if(bits[i][j])
                {
                    matrix_cp.push_back(matrix[j]);
                }
            }
            // if(bits[i][m+n])
            // {
            //     matrix_cp.push_back(vall);
            // }
            // cout << "\n";

            // rep(zz,m)
            // {
            //     rep(qq,m+1)
            //     {
            //         cout << matrix_cp[zz][qq] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n\n";

            myp = find_ans(matrix_cp,m);

            flag = true;
            val = 0;
            rep(j,bits[i].size())
            {
                val = 0;
                // if(!bits[i][j])
                // {
                    rep(k,m)
                    {
                        val += matrix[j][k]*myp.second[k];
                    }
                    // cout << "Comparing Values: " << val << " " << matrix[j][m] << "\n";
                    if(val > matrix[j][m] + 0.001)
                    {
                        flag = false;
                        break;
                    }
                // }
            }
            val = 0;
            rep(k,m)
            {
                val+=myp.second[k]*pleasure[k];
            }
            // cout << "Comparing Pleasure Values: " << val << " " << max_val  << " " << flag << " " << myp.first <<  "\n";

            // cout << "Values\n";
            // rep(i,myp.second.size())
            // {
            //     cout << myp.second[i] << " ";
            // }
            // cout << "\n";
            if(myp.first==1&&flag&&max_val<=val)
            {
                
                if(bits[i][m+n]&&max_val<val)
                {
                    // cout<< "Solution found and passed on equalities " << flag << "\n"; 

                    curr = myp;
                    curr.first=2;
                    max_val = val;
                }
                else if(!bits[i][m+n])
                {
                    // cout<< "Solution found and passed on equalities " << flag << "\n"; 

                    curr = myp;
                    max_val = val;
                }
                
            }
            // else if(myp.first == 2&&flag&&max_val<=val)
            // {
            //     max_val = val;
            //     curr = myp;
            // }
            // else if(curr.first==-1)
            // {
            //     curr = myp;
            // }
        }


        // vector<double> inf_values(m,1e10);
        // rep(i,n)
        // {
        //     val = 0;
        //     flag = true;
        //     rep(k,m)
        //     {
        //         // cout <<"Val: " << val  << " " <<  val + matrix[i][k]*inf_values[k]  << " " << matrix[i][m] << "\n";
        //         if(val + matrix[i][k]*inf_values[k] < matrix[i][m])
        //         {
        //             val += matrix[i][k]*inf_values[k];
        //         }
        //         else
        //         {
        //             inf_values[k] = 0;
        //         }
        //     }
        //     // cout << "Comparing Values: " << val << " " << matrix[j][m] << "\n";
        //     if(val > matrix[i][m])
        //     {
        //         flag = false;
        //         break;
        //     }
        // }

        // val = 0;
        // rep(k,m)
        // {
        //     val+=inf_values[k]*pleasure[k];
        // }

        // cout << "Comparing Pleasure Values: " << val << " " << max_val  << " " << flag  <<  "\n";



        if(curr.first==2)
        {
            cout << "Infinity";
        }
        else if(curr.first == 1)
        {
            cout << "Bounded solution\n";
            rep(i,curr.second.size())
            {
                cout << curr.second[i] << " ";
            }
        }
        else
        {
            cout << "No solution";
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


