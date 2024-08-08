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


int binsearch(vector <int> & arr,int left,int right,int x)
{
    if (left < 0 || right > arr.size() || left > right) return -1;
    int mid = (left + right)/2;
    if (arr[mid]== x)
    {
        int result = binsearch(arr,left,mid-1,x);
        return mid>result && result!=-1 ? result:mid;
    }
    else if (arr[mid] >x)
    {
        return binsearch(arr,left,mid-1,x);
    }
    else if (arr[mid]<x)
    {
        return binsearch(arr,mid+1,right,x);
    }
    return -1;
}



void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> arr (n,0);
        rep(i,n) cin >> arr[i];
        int m;
        cin >> m;
        vector <int> findarr(m,0);
        rep(i,m) cin >> findarr[i];
        unordered_map<int,int> mpp;
        rep(i,m) 
        {
            if (mpp.find(findarr[i])==mpp.end())
            {
                mpp[findarr[i]] = binsearch(arr,0,n-1,findarr[i]);
            }
            cout << mpp[findarr[i]] << " ";
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


