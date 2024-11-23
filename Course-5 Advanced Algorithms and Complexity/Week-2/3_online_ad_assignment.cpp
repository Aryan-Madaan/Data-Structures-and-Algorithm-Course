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

void print(vector<vector<ld> > &matrix,vector<ld> &zobj,vector<int> &curr_basic,int &p,int &q)
{
    cout <<"\n\nMatrix\n";
    rep(i,p)
    {
        rep(j,p+q+1)
        {
            cout << matrix[i][j] <<  " ";
        }
        cout << "\n";
    }

    cout <<"\nObjectives\n";


    rep(i,p+q+1) cout << zobj[i] << " ";
    cout << "\n";

    cout << "\nCurrent Basis\n";
    rep(i,p) cout << curr_basic[i] << " ";
    cout << "\n\n";
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int p,q;
        cin >> p >> q;

        vector<ld> objective(q,0),zobj(p+q+1,0),ans(q,0);
        vector<vector<ld> > matrix(p,vector<ld>(p+q+1,0));

        vector<int> curr_basic(p,0);

        rep(i,p)
        {
            rep(j,q)
            {
                cin >> matrix[i][j];
            }
            matrix[i][q+i] = 1;
        }

        rep(i,p)
        {
            cin >> matrix[i][p+q];
        }

        rep(i,q)
        {
            cin >> objective[i];
            zobj[i] = -objective[i];
        }

        rep(i,p)
        {
            curr_basic[i] = q+i;
        }


        rep(i,p)
        {
            if(matrix[i][p+q]<0)
            {
                rep(j,p+q+1)
                {
                    matrix[i][j] *= -1.0;
                }
            }
        }

        print(matrix,zobj,curr_basic,p,q);

        bool flag = true,inf_flag = false;

        int min_col = -1,min_row=-1;
        ld min_value=0,min_ratio = LLONG_MAX,mul_factor;

        int curr_itr = 0;

        while(flag&& curr_itr < 10)
        {
            curr_itr++;

            min_value=0;
            min_ratio = LLONG_MAX;
            min_col = -1;


            rep(i,p+q)
            {
                if(min_value>zobj[i])
                {
                    min_value = zobj[i];
                    min_col = i;
                }
            }

            if(min_col==-1)
            {
                flag = false;
                break;
            }

            rep(i,p)
            {
                if(min_ratio>(matrix[i][p+q]/matrix[i][min_col]) && (matrix[i][p+q]/matrix[i][min_col])>0)
                {
                    min_ratio =matrix[i][p+q]/matrix[i][min_col];
                    min_row = i;
                }   
            }

            if(min_row==-1)
            {
                flag = false;
                inf_flag = true;
                break;
            }

            cout << "\nMin Row: " << min_row << " Min Col: " << min_col << "\n";

            curr_basic[min_row] = min_col;

            rep(i,p)
            {
                mul_factor = matrix[i][min_col]/matrix[min_row][min_col];
                if(i==min_row)
                {
                    mul_factor =  1.0/matrix[min_row][min_col];
                    rep(j,p+q+1)
                    {
                        matrix[i][j] *= mul_factor;
                    }
                }
                else
                {
                    rep(j,p+q+1)
                    {
                        matrix[i][j] -= mul_factor*matrix[min_row][j];
                    }
                }
            }

            mul_factor = zobj[min_col]/matrix[min_row][min_col];

            rep(j,p+q+1)
            {
                zobj[j] -= mul_factor*matrix[min_row][j];
            }


            print(matrix,zobj,curr_basic,p,q);
        }

        if(inf_flag){
            cout <<"Infinity";
            return;
        }

        bool no_sol_flag = false;

        rep(i,curr_basic.size())
        {
            if(curr_basic[i]>=2*q && matrix[i][p+q]!=0)
            {
                no_sol_flag = true;
                break;
            }
        }

        if(no_sol_flag)
        {
            cout << "No solution";
            return;
        }

        rep(i,curr_basic.size())
        {
            if(curr_basic[i]<q)
            ans[curr_basic[i]] = matrix[i][p+q];
        }

        cout <<"Bounded solution\n";

        rep(i,ans.size())
        {
            cout << ans[i] << " ";
        }

    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<ld>::max_digits10);
       cout << setprecision(1) << fixed;
    Expresso
    solve();
    return 0;
}


