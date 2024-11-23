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



void post_dfs(vector<vector<int> > &graph,vector<bool> &vis,vector<int>&post_order,int i)
{
    vis[i] = 1;

    rep(j,graph[i].size())
    {
        if(!vis[graph[i][j]])
        {
            post_dfs(graph,vis,post_order,graph[i][j]);
        }
    }

    post_order.pb(i);
}

void label_ssc(vector<vector<int> > &graph,vector<bool> &vis,int num,int i,vector<int>&label)
{
    vis[i] = 1;

    rep(j,graph[i].size())
    {
        if(!vis[graph[i][j]])
        {
            label_ssc(graph,vis,num,graph[i][j],label);
        }
    }
    label[i] = num;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int v,c;
        cin >> v >> c;

        vector<int> ans(2*v,-1);
        vector<vector<int> > graph(2*v),rgraph(2*v);

        bool flag = true;

        int vert1 = 0,vert2 = 0, vert_neg1 = 0, vert_neg2 = 0;

        rep(i,c)
        {
            cin >> vert1 >> vert2;

            if(vert1<0){
                vert_neg1 = 2*(abs(vert1)-1);
                vert1 = 2*(abs(vert1)-1) + 1;
            }
            else
            {
                vert_neg1 = 2*(abs(vert1)-1) + 1;
                vert1 = 2*(abs(vert1)-1);
            }
            if(vert2<0)
            {
                vert_neg2 = 2*(abs(vert2)-1);
                vert2 = 2*(abs(vert2)-1) + 1;
            }
            else
            {
                vert_neg2 = 2*(abs(vert2)-1) + 1;
                vert2 = 2*(abs(vert2)-1);
            }

            graph[vert_neg1].pb(vert2);
            graph[vert_neg2].pb(vert1) ;

            rgraph[vert2].pb(vert_neg1);
            rgraph[vert1].pb(vert_neg2);
        }

        vector<int>post_order,label(2*v,0);
        vector<bool>vis(2*v,0),vis1(2*v,0);

        rep(i,2*v)
        {
            if(!vis[i])
            post_dfs(rgraph,vis,post_order,i);
        }
        
        int l_num = 1;
        int index = post_order.size()-1;

        while(index>=0)
        {
            vert1 = post_order[index];
            if(!vis1[vert1])
            {
                label_ssc(graph,vis1,l_num,vert1,label);
                l_num++;
            }
            index--;
        }

        for(int i =0;i<2*v;i+=2)
        {
            if(label[i]==label[i+1])
            {
                flag = false;
                break;
            }
        }

        index = post_order.size()-1;

        while(index>=0)
        {
            if(ans[post_order[index]]==-1)
            {
                ans[post_order[index]] = 1;
                if(post_order[index]%2==1)
                {
                    ans[post_order[index]-1] = 0;
                }
                else
                {
                    ans[post_order[index]+1] = 0;
                }
            }        
            index--;   
        }

        if(flag)
        {
            cout << "SATISFIABLE\n";
            rep(i,2*v)
            {
                cout << (ans[i]?1:-1) * ((i/2)+1) << " ";
                i++;
            }
        }
        else
        {
            cout << "UNSATISFIABLE";
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


