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

class priqueue
{
    vector<pair<int,long> > qq;
    pair<int,long> temp;
    int temp_idx1, temp_idx2, mx_idx;
    long temp_pri;

    int get_parent(int i)
    {
        return (i-1)/2;
    }

    int left_child(int i)
    {
        return 2*i + 1;
    }

    int right_child(int i)
    {
        return 2*i + 2;
    }

    void swap(int i, int j)
    {
        temp = qq[i];
        qq[i] = qq[j];
        qq[j] = temp;
    }

    void sift_up(int i)
    {
        while(i>0 && qq[get_parent(i)].second > qq[i].second)
        {
            swap(get_parent(i),i);
            i = get_parent(i);
        }
    }

    void sift_down(int i)
    {
        mx_idx = i;
        temp_idx2 = right_child(i);
        if(temp_idx2<=size()-1 && qq[temp_idx2].second<qq[mx_idx].second)
        {
            mx_idx = temp_idx2;
        }
        temp_idx1 = left_child(i);
        if(temp_idx1<=size()-1 && qq[temp_idx1].second<qq[mx_idx].second)
        {
            mx_idx = temp_idx1;
        }
        if(i!=mx_idx)
        {
            swap(i,mx_idx);
            sift_down(mx_idx);
        }
    }


    public:

    void print()
    {
        cout << "\n----Start----\n";
        rep(i,qq.size())
        {
            cout << qq[i].first << ":" << qq[i].second << " ";
        }
        cout << "\n----End----\n";
    }

    void change_priority(int i, long pri)
    {
        temp_pri = qq[i].second;
        qq[i].second = pri;
        
        if(pri>temp_pri)
        {
            sift_down(i);
        }
        else
        {
            sift_up(i);
        }
    }

    void push(pair<int,long> val)
    {
        qq.push_back(val);
        sift_up(size()-1);
    }

    int size()
    {
        return qq.size();
    }

    pair<int,long> front()
    {
        return qq[0];
    }

    void pop()
    {
        temp = qq[0];
        qq[0] = qq[size()-1];
        qq.pop_back();
        sift_down(0);
    }
    
};



void solve()
{
    int t=1;
    while(t--)
    {
        int n,edges,vert1,vert2,weight;

        cin >> n >> edges;

        vector< vector<pair<int,long> > > graph(n,vector< pair<int,long> >(0));
        vector<ll> dis(n,1e16);
        vector<bool> vis(n,0);
        rep(i,edges)
        {
            cin >> vert1 >> vert2 >> weight;
            --vert2;--vert1;
            graph[vert1].push_back(mp(vert2, weight));
        }

        cin >> vert1 >> vert2;
        --vert2;--vert1;



        priqueue flights = priqueue();
        dis[vert1] = 0;

        rep(i,n)
        {
            if(i == vert1)
            {
                flights.push(mp(i,0));
            }
            else
            {
                flights.push(mp(i,1e16));
            }
        }


        

        pair<int,long> vert;


        while(flights.size()>0)
        {
            vert = flights.front();
            flights.pop();

            if(vis[vert.first]) continue;

            vis[vert.first] = 1;

            rep(i,graph[vert.first].size())
            {
                if(dis[graph[vert.first][i].first] > vert.second + graph[vert.first][i].second)
                {
                    dis[graph[vert.first][i].first] = vert.second + graph[vert.first][i].second;
                    flights.push(mp(graph[vert.first][i].first,vert.second + graph[vert.first][i].second));
                }
            }

        }
        if(dis[vert2]==1e16)
        {
            cout << -1;
        }
        else
        {
            cout << dis[vert2];
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


