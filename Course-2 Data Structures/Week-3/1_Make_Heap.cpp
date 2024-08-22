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


void swap(vector<int> &vv,int i,int j)
{
    int temp = vv[i];
    vv[i] = vv[j];
    vv[j] = temp;
}

void siftdown(vector<int> &vv,vector<pair<int,int> > &myvec,int j)
{
    // cout << j << "\n\n";
    int j2 = 2*j + 1,j3 = 2*j + 2;
    if(j3<vv.size() && vv[j]>vv[j2]&&vv[j]>vv[j3])
    {
        if(vv[j2] < vv[j3])
        {
            swap(vv,j,j2);
            myvec.push_back(mp(j,j2));
            siftdown(vv,myvec,j2);
        }
        else
        {
            swap(vv,j,j3);
            myvec.push_back(mp(j,j3));
            siftdown(vv,myvec,j3);
        }
    }
    else if(j2<vv.size() && vv[j]>vv[j2])
    {
        swap(vv,j,j2);
        myvec.push_back(mp(j,j2));
        siftdown(vv,myvec,j2);
    }
    else if(j3<vv.size() && vv[j]>vv[j3])
    {
        swap(vv,j,j3);
        myvec.push_back(mp(j,j3));
        siftdown(vv,myvec,j3);
    }
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> vv(n,0);
        vector<pair<int,int> > myvec;
        rep(i,n) cin >> vv[i];
        for(int i =n/2;i>=0;i--)
        {
            siftdown(vv,myvec,i);
        }
        // rep(i,n) cout << vv[i] << " ";
        // cout << "\n\n";
        cout << myvec.size() << "\n";
        rep(i,myvec.size())
        {
            cout << myvec[i].first << " " << myvec[i].second << "\n";
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


