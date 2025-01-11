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
const int NUM_BUCKETS = 1000,NUM_HASHES = 11;

const int multipliers[NUM_HASHES] = {17, 19, 31, 43, 59, 67, 73, 89, 97, 101, 113};
const int offsets[NUM_HASHES] = {3, 5, 7, 11, 13, 19, 23, 29, 37, 41, 43};
const int shifts[NUM_HASHES] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void hash_function(vector<ll> &curr_hashes,ll &input)
{
    for (int i = 0; i < NUM_HASHES; ++i) 
    {
        curr_hashes[i] = ((input * multipliers[i] + offsets[i]) ^ (input >> shifts[i])) % NUM_BUCKETS;
    }
}

int prob_func(ll&i)
{
    if(i%2==0) return 1;
    return -1;
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        ll n = 0 ,thres = 0, id = 0, value = 0, prob = 0;
        cin >> n >> thres;

        vector< vector<long long> > my_good_vec(NUM_HASHES,vector<ll>(NUM_BUCKETS,0)),my_bad_vec(NUM_HASHES,vector<ll>(NUM_BUCKETS,0));

        vector<long long> curr_hashes(NUM_HASHES,0),good_value(NUM_HASHES,0),bad_value(NUM_HASHES,0);

        rep(i,n)
        {
            cin >> id >> value;   
            hash_function(curr_hashes,id);
            prob = prob_func(id);
            rep(i,NUM_HASHES)
            {
                my_good_vec[i][curr_hashes[i]]+= value*prob;
            }
        }

        rep(i,n)
        {
            cin >> id >> value; 
            hash_function(curr_hashes,id);  
            prob = prob_func(id);
            rep(i,NUM_HASHES)
            {
                my_bad_vec[i][curr_hashes[i]]+= value*prob;
            }
        }

        int query = 0;
        cin >> query;

        rep(i,query)
        {
            cin >> id;
            hash_function(curr_hashes,id);
            prob = prob_func(id);
            rep(i,NUM_HASHES)
            {
                good_value[i] = my_good_vec[i][curr_hashes[i]]*prob;
            }

            rep(i,NUM_HASHES)
            {
                bad_value[i] = my_bad_vec[i][curr_hashes[i]]*prob;
            }

            sort(good_value.begin(),good_value.end());
            sort(bad_value.begin(),bad_value.end());

            if(good_value[NUM_HASHES/2] - bad_value[NUM_HASHES/2] >= thres)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
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


