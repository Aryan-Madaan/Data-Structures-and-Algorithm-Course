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

struct Index{
    int coef, var;
    Index(int c, int v): coef(c), var(v){}
};

class AllocateBudget {
    private:
        int m, n, nclauses;
        vector<int> b_values;
        vector<vector<Index>> coeffients;
        vector<vector<int> >  clauses;
        int noSolution;


    public:
        int mapint(int i){
            if(i==0) return 1;
            if(i==1) return -1;
        }
        bool handleOneVars(int con){
            int breakAssignments = 0;
            int coef = coeffients[con][0].coef;
            int var = coeffients[con][0].var;

            for(int boolv = 0; boolv<2; boolv++)
              if(boolv* coef > b_values[con]){
                clauses.push_back(vector<int>());
                clauses[nclauses++].push_back(mapint(boolv)*var);
                breakAssignments++;
              }

            if(breakAssignments == 2) return true;
            return false;
        }

        bool handleTwoVars(int con){
            int breakAssignments = 0;
            int coeffs[2] = {coeffients[con][0].coef, coeffients[con][1].coef};
            int vars[2] =   {coeffients[con][0].var, coeffients[con][1].var};

            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++){
                    int val = i*coeffs[0] + j*coeffs[1];
                    if(val > b_values[con]){
                        clauses.push_back(vector<int>());
                        clauses[nclauses].push_back(mapint(i)*vars[0]);
                        clauses[nclauses++].push_back(mapint(j)*vars[1]);
                        breakAssignments++;
                    }
                }
            if(breakAssignments == 4) return true;
            return false;
        }

        bool handleThereVars(int con){
            int breakAssignments = 0;
            int coeffs[3] = {coeffients[con][0].coef, coeffients[con][1].coef, coeffients[con][2].coef};
            int vars[3] =   {coeffients[con][0].var, coeffients[con][1].var, coeffients[con][2].var};

            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    for(int k=0; k<2; k++){
                    int val = i*coeffs[0] + j*coeffs[1] + k*coeffs[2];
                    if(val > b_values[con]){
                        clauses.push_back(vector<int>());
                        clauses[nclauses].push_back(mapint(i)*vars[0]);
                        clauses[nclauses].push_back(mapint(j)*vars[1]);
                        clauses[nclauses++].push_back(mapint(k)*vars[2]);
                        breakAssignments++;
                    }
                }
            if(breakAssignments == 8) return true;
            return false;
        }

        int addConstraints(){
            nclauses = 0;
            noSolution = false;
            int sz;
            for(int i=0; i<m; i++){
                sz = coeffients[i].size();

                if(sz == 0 && b_values[i]<0){
                    noSolution = true;
                    break;

                }else if(sz == 1){
                    if((noSolution = handleOneVars(i)))
                        break;

                }else if(sz == 2){
                    if((noSolution=handleTwoVars(i)))
                        break;
                }else if(sz==3){
                    if((noSolution=handleThereVars(i)))
                        break;
                }
            }
            if(noSolution)
                return -1;
            return nclauses;
        }
        void printEquisatisfiableSatFormula(){
            int res = addConstraints();
            if(res == -1){
                cout<<2<<" "<<1<<endl;
                cout<<1<<" "<<0<<endl;
                cout<<-1<<" "<<0<<endl;
            }else if(nclauses == 0){
                cout<<1<<" "<<1<<endl;
                cout<<1<<" "<<-1<<" "<<0<<endl;
            }else{
                cout<<clauses.size()<<" "<<n<<endl;
                for(int i=0; i<clauses.size(); i++){
                    for(int j=0; j<clauses[i].size(); j++)
                        cout<<clauses[i][j]<<" ";
                    cout<<0<<endl;
                }

            }
        }


        void readConstraints(){
            int b, co;
            cin>>m>>n;
            for(int i=0; i<m; i++)
                coeffients.push_back(vector<Index>());

            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++){
                    cin>>co;
                    if(co!=0)
                        coeffients[i].push_back(Index(co, j+1));
                }

            for(int i=0; i<m; i++){
               cin>>b;
               b_values.push_back(b);
            }
        }
};


void solve()
{
    int t=1;
    while(t--)
    {
        AllocateBudget mybudget;
        mybudget.readConstraints();
        mybudget.printEquisatisfiableSatFormula();
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


