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


int binsearchmin(vector<int> &points,int left,int right,int &find)
{
    if(left<0 || right> points.size() || left>right)
    {
        return INT_MAX;
    }
    int mid = (left + right)/2;
    if(points[mid]==find)
    {
        return min(mid,binsearchmin(points,left,mid-1,find));
    }
    if(points[mid]>find)
    {
        return min(mid,binsearchmin(points,left,mid-1,find));
    }
    if(points[mid]<find)
    {
        return binsearchmin(points,mid+1,right,find);
    }
}

int binsearchmax(vector<int> &points,int left,int right,int &find)
{
    if(left<0 || right> points.size() || left>right)
    {
        return points.size()-1;
    }
    int mid = (left + right)/2;
    if(points[mid]==find)
    {
        return max(mid,binsearchmin(points,mid+1,right,find));
    }
    if(points[mid]>find)
    {
        return binsearchmin(points,left,mid-1,find);
    }
    if(points[mid]<find)
    {
        return max(mid,binsearchmin(points,mid+1,right,find));
    }
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector < pair<int,int> > mypp(n,mp(0,0));
        rep(i,n)
        {
            cin >> mypp[i].first >> mypp[i].second;
        }
        sort(mypp.begin(),mypp.end());
        vector< pair<int,int> > points(m,mp(0,0));
        vector<int> value(m,0);
        rep(i,m) {cin >> points[i].first; points[i].second = i;}
        sort(points.begin(),points.end());

        rep(i,n)
        {
            // binsearchmax(points,0,points.size(),mypp[i].first);
            // value
            rep(j,m)
            {
                // cout << points[i] << " " << mypp[j].first << " " <<
                // if(points[j]<mypp[i].first)
                // {
                //     break;
                // }
                if(points[j].first>=mypp[i].first && points[j].first<=mypp[i].second)
                {
                    value[points[j].second]++;
                }
                else if (points[j].first>=mypp[i].first && points[j].first>=mypp[i].second)
                {
                    break;
                }
            }
        }
        rep(i,m) cout << value[i] << " ";
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


