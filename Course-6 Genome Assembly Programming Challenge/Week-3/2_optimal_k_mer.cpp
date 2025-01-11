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
int get_overlap(vector<string>& reads){

    int min_overlap = INT_MAX;

    rep(i, reads.size())
     rep(j, reads.size()){
        if(i != j)
            rep(curr_read_idx_start, 100){
                int read_idx = curr_read_idx_start;

                for(int idx=0; read_idx < 100; read_idx++, idx++)
                {

                    if(reads[i][read_idx] != reads[j][idx]) 
                    {
                        break;
                    }
                }

                if(read_idx == 100)
                {
                    min_overlap = min(min_overlap, 100 - curr_read_idx_start);
                }
            }
     }

    return min_overlap;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        vector<string> reads;
        set<string> uni_reads;
        string read;

        rep(i, 400){
            cin >> read;
            uni_reads.insert(read);
        }

        for(auto r : uni_reads)
            reads.pb(r);

        cout<< get_overlap(reads);
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


