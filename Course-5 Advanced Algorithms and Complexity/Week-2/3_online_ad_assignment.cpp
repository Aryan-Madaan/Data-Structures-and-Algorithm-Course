//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
#pragma optimize("O3",on)
#include <bits/stdc++.h>
#include <limits.h>
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
// #define INF 2e9
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
const double doubleEPS = 1e-3;
const double TOL = 1e-7;
const int PRECISION = 20;
bool bland_rule = false;
typedef struct{int x, y;} Pivot;

typedef vector<double> Row;
typedef vector<Row> SimplexTablau;
typedef vector<bool> BoolV;
typedef vector<set<int> > SubSets;
enum {NSOL, SOL, INF} ;
int n, m;

struct Var{
            char v; int i;
            Var(char c): v(c)
            {}
};



void initLabels(vector<int>& col_label, vector<int>& row_label){
    for(int x=0; x<m; x++)
        col_label[x] = x;

    for(int y=m, j=0; y<n+m; y++, j++)
        row_label[j] = y;
}

bool findNegative_b(SimplexTablau& simplexTable, double& i){
    static int last_negative_b = 0;
    while(last_negative_b < n && simplexTable[last_negative_b][m] >= 0)
        last_negative_b++;

    i=last_negative_b;
    return (last_negative_b == n)? false : true;
}

bool findNegative_c(SimplexTablau& simplexTable, double& j, vector<int>& last_row){
    int c = INT_MAX;
    for(int i=0; i<m; i++)
        if(simplexTable[n][i] < 0){
            if(!bland_rule){
                c = i;
                break;
            }else if(last_row[i] < c)
                c = i;
        }

    j=c;
    return (c == INT_MAX)? false : true;
}

bool findPivot_With_b(SimplexTablau & simplexTable, int b, Pivot & pivot){
    double Aj = -1;
    for(int i=0; i<m; i++)
      if(simplexTable[b][i] < 0){
        Aj = i;
        break;
      }

    if(Aj == -1) return false;

    pivot.x = Aj;
    pivot.y = b;
    double Ratio = simplexTable[b][m] / simplexTable[b][Aj];

    for(int i=0; i<n; i++){
        if(simplexTable[i][m] >= 0 && simplexTable[i][Aj] > 0){
            double tratio = simplexTable[i][m] / simplexTable[i][Aj];
            bool cond = (tratio - Ratio) <= TOL;
            if(cond){
                pivot.y = i;
                Ratio = tratio;
            }
        }
    }
    return true;
}

bool findPivot_With_c(SimplexTablau & simplexTable, int c, Pivot & pivot, vector<int> row_index){
    pivot.x = c;
    pivot.y = INT_MAX;
    double Ratio = DBL_MAX;

    for(int i=0; i<n; i++)
        if(simplexTable[i][c] > 0){
            double tratio = simplexTable[i][m] / simplexTable[i][c];
            bool cond;
            if(bland_rule){
                bool approxEqual = ((tratio - Ratio) <= TOL && (tratio - Ratio) >= 0);
                cond =  approxEqual? (row_index[i] < pivot.y) : (tratio < Ratio);
            }else
                cond = (tratio - Ratio) <= TOL;

            if(cond){
                pivot.y = i;
                Ratio = tratio;
            }
        }
    return (pivot.y == INT_MAX)? false : true;
}

void updateSimplexTablau(SimplexTablau & simplexTable, Pivot & pivot){
    int x = pivot.x, y = pivot.y;
    double p = simplexTable[y][x];

    for(int i=0; i<=n; i++)
        if(i != y)
            for(int j=0; j<=m; j++)
                if(j != x)
                    simplexTable[i][j] -= ((simplexTable[i][x] * simplexTable[y][j]) / p);
    for(int i=0; i<=m; i++)
        if(i!=x)
            simplexTable[y][i] /= p;

    for(int i=0; i<=n; i++)
        if(i!=y)
            simplexTable[i][x] /= -1 * p;

    simplexTable[y][x] = 1 / p;
}

void getSolution(SimplexTablau & simplexTable, vector<int>& rowLabel, Row & solution){
    for(int i=0; i<n; i++)
        solution[rowLabel[i]] = simplexTable[i][m];
}

pair<int, Row> solve_addAlloc_problem(SimplexTablau & simplexTable){
    Row solution(m+n, 0);
    vector<int> col_label(m);
    vector<int> row_label(n);
    bool b_under_zeros = true;
    bool c_under_zeros = true;
    double negative_b;
    double negative_c;
    Pivot pivot;
    int solType = NSOL;
    int picked_pivots = 0;

    initLabels(col_label, row_label);

    while(b_under_zeros || c_under_zeros){
        bool found;
        if(b_under_zeros && (b_under_zeros = findNegative_b(simplexTable, negative_b))){
            if((found = findPivot_With_b(simplexTable, negative_b, pivot))){
                swap(col_label[pivot.x], row_label[pivot.y]);

                updateSimplexTablau(simplexTable, pivot);

            }else{
                break;
            }
        }else if(c_under_zeros && (c_under_zeros = findNegative_c(simplexTable, negative_c, col_label))){
            if((found = findPivot_With_c(simplexTable, negative_c, pivot, row_label))){
                swap(col_label[pivot.x], row_label[pivot.y]);

                updateSimplexTablau(simplexTable, pivot);

            }else{
                solType = INF;
                break;
            }
        }else{
            solType = SOL;
        }
        if(!bland_rule && ++picked_pivots==10)
            bland_rule = true;
    }
    if(solType == SOL)
        getSolution(simplexTable, row_label, solution);
    return {solType, solution};
}

SimplexTablau ReadEquation() {
    cin >> n >> m;
    SimplexTablau simplexTable(n+1, Row(m+1, 0));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>simplexTable[i][j];

    for(int i=0; i<n; i++)
        cin>>simplexTable[i][m];

    for(int i=0; i<m; i++){
        int c;
        cin>>c;
        simplexTable[n][i] = -c;
    }
    return simplexTable;
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
          SimplexTablau simplexTable = ReadEquation();
  pair<int, vector<double>> ans = solve_addAlloc_problem(simplexTable);

  switch (ans.first) {
    case NSOL:
      printf("No solution\n");
      break;
    case SOL:
      printf("Bounded solution\n");
      for (int i = 0; i < m; i++) {
        // cout.precision();
        cout<<ans.second[i]<< " \n"[i + 1 == m];
      }
      break;
    case INF:
      printf("Infinity\n");
      break;
  }
    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
//    cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(PRECISION) << fixed;
    // Expresso
    solve();
    return 0;
}


