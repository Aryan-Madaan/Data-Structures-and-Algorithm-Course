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

void swap(vector<pair<ll,int> > &vv,int i,int j)
{
    pair<ll,int> temp = vv[i];
    vv[i] = vv[j];
    vv[j] = temp;
}

class myqueue
{
    private:
    vector< pair<ll,int> > vv1;

    public:
    myqueue(int &n)
    {
        rep(i,n)
        {
            vv1.push_back(mp(0,i));
        }
    }

    void siftdown(vector< pair<ll,int> >& vv,int j)
    {
        int j2 = 2*j + 1,j3 = 2*j + 2;
        if(j3<vv.size() && vv[j]>vv[j2]&&vv[j]>vv[j3])
        {
            if(vv[j2] < vv[j3])
            {
                swap(vv,j,j2);
                siftdown(vv,j2);
            }
            else
            {
                swap(vv,j,j3);
                siftdown(vv,j3);
            }
        }
        else if(j2<vv.size() && vv[j]>vv[j2])
        {
            swap(vv,j,j2);
            siftdown(vv,j2);
        }
        else if(j3<vv.size() && vv[j]>vv[j3])
        {
            swap(vv,j,j3);
            siftdown(vv,j3);
        }
    }

    void siftup(vector< pair<ll,int> >& vv,int j)
    {
        int j2 = ((j+1)/2) - 1;
        if(j2 >=0&&vv[j2] > vv[j])
        {
            swap(vv,j2,j);
            siftup(vv,j2);
        }
    }

    void changepriority(vector< pair<ll,int> >& vv,ll pri,int j)
    {
        if(vv[j].first>pri)
        {
            vv[j].first = pri;
            siftup(vv,j);
        }
        else if(vv[j].first<pri)
        {
            vv[j].first = pri;
            siftdown(vv,j);
        }
    }
    
    void process(vector<ll> &v)
    {
        rep(i,v.size())
        {
            cout << vv1[0].second << " " << vv1[0].first << "\n";
            changepriority(vv1,vv1[0].first+v[i],0);
        }
    }
};


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<ll>v(m,0);
        rep(i,m) cin >> v[i];
        myqueue q1(n);
        q1.process(v);
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


