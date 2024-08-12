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
const ld eps = 1e-6, pi = acos(-1);
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

ld finddist(pair<int,int>&pp1,pair<int,int>&pp2)
{
    return sqrt((long double)((long double)pp1.first-(long double)pp2.first)*(long double)((long double)pp1.first-(long double)pp2.first) + (long double)((long double)pp1.second-(long double)pp2.second)*(long double)((long double)pp1.second-(long double)pp2.second));
}

bool cmp(pair<int,int> &pp1,pair<int,int> &pp2)
{
    if(pp1.second>pp2.second)
    {
        return false;
    }
    if(pp1.second<pp2.second)
    {
        return true;
    }
    else
    {
        return pp1.first<=pp2.first;
    }
}

// ld finddi(vector<pair<int,int> > & mypp, ld &dist,ld &mid_val)
// {

//     return temp;
// }

ld findd(vector< pair<int,int> > &mypp,vector< pair<int,int> > &mypp1)
{
    // cout << "Starting\n\n";
    // rep(i,mypp.size())
    // {
    //     cout << mypp[i].first << " " << mypp[i].second << " | ";
    // }
    // cout << "\n";
    // rep(i,mypp1.size())
    // {
    //     cout << mypp1[i].first << " " << mypp1[i].second << " | ";
    // }
    // cout << "\n" << mypp1.size() << "\n\n";
    if(mypp.size()<=1 || mypp1.size()<=1) return LONG_MAX;
    if(mypp.size()==2)
    {
        return finddist(mypp[0],mypp[1]);
    }
    if(mypp.size()==3)
    {
        return min(finddist(mypp[0],mypp[1]),min(finddist(mypp[0],mypp[2]),finddist(mypp[1],mypp[2])));
    }
    int mid = mypp.size()/2;
    ld mid_val = mypp[mid].first,dist = LLONG_MAX;
    vector<pair<int,int> > v1,v2,v3,v4;
    for (int i =0;i<mypp.size();i++)
    {
        if(mypp[i].first<mid_val)
        {
            v1.push_back(mypp[i]);
        }
        else
        {
            v2.push_back(mypp[i]);
        }
        if(mypp1[i].first<mid_val)
        {
            v3.push_back(mypp1[i]);
        }
        else
        {
            v4.push_back(mypp1[i]);
        }
    }
    //     rep(i,v4.size())
    // {
    //     cout << v4[i].first << " " << v4[i].second << " | ";
    // }
    // return dist;
    if(v1.size()!=0 && v2.size()!=0){
       // if(v1.size()>=2&&v3.size()>=2)
    ld ans1 = findd(v1,v3);
    // if(v2.size()>=2&&v4.size()>=2)
    ld ans2 = findd(v2,v4);
    dist = min(ans1,ans2);
    }

    ld temp = dist;
    vector<pair<int,int> >pp1;
    rep(i,mypp1.size())
    {
        if (abs(mypp[i].first-mid_val)<dist)
        {
            pp1.push_back(mypp[i]);
        }
    }
    rep(i,pp1.size())
    {
        for(int j = 1;j+i<pp1.size()&&j<=1000;j++)
        {
            temp = min(temp,finddist(pp1[i],pp1[j+i]));
        }
    }
    // ld final = finddi(mypp1,dist,mid_val);
    return temp;
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector< pair<int,int> > mypp(n,mp(0,0)),mypp1(n,mp(0,0));
        rep(i,n) 
        {
            cin >> mypp[i].first >> mypp[i].second;
            mypp1[i] = mypp[i];
        }
        sort(mypp.begin(),mypp.end());
        sort(mypp1.begin(),mypp1.end(),cmp);
        ld min_dist_1 = findd(mypp,mypp1);
        cout<<min_dist_1;
    }
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
   cout.precision(numeric_limits<ld>::max_digits10);
       cout << setprecision(14) << fixed;
    Expresso
    solve();
    return 0;
}


