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
    vector< pair< int,float>  > qq;
    int l,r,parent,min_idx;
    int tmp;
    pair< int,float> temp,temp1;
    int instance;

    int getparent(int i)
    {
        return (i-1)/2;
    }

    int leftchild(int i)
    {
        return 2*i + 1;
    }

    int rightchild(int i)
    {
        return 2*i + 2;
    }

    void swap(int i, int j)
    {
        temp = qq[j];
        qq[j] = qq[i];
        qq[i] = temp;
    }

    void siftup(int curr)
    {
        parent = getparent(curr);

        while (curr > 0 && qq[curr].second < qq[parent].second) {
            swap(curr, parent);
            curr = parent;
            parent = getparent(curr);
        }
    }

    void siftdown(int curr)
    {
        min_idx = curr;
        l = leftchild(curr),r =rightchild(curr);
        if(l<qq.size()&&qq[l].second<qq[min_idx].second)
        {
            min_idx = l;
        }
        if(r<qq.size()&&qq[r].second<qq[min_idx].second)
        {
            min_idx = r;
        }
        if(curr!=min_idx)
        {
            swap(curr,min_idx);
            siftdown(min_idx);
        }
    }

    public:
    priqueue(int inst)
    {
        instance = inst;
    }

    void push(pair<int,float> inp)
    {
        qq.push_back(inp);
        siftup(qq.size()-1);
    }

    pair<int,float> pop()
    {
        temp1 = qq[0];
        swap(0,qq.size()-1);
        qq.pop_back();
        siftdown(0);
        return temp1;
    }

    int size()
    {
        return qq.size();
    }

    void print()
    {
        cout<<"\nPrinting Queue" << "\n";
        rep(i,qq.size())
        {
            cout << qq[i].first << ":" << qq[i].second << " ";
        }
        cout << endl;
    }

    void clear(int vert1)
    {
        // qq.resize(n);
        qq.resize(0);
        qq.push_back(mp(vert1,0));

        // cout << "\n\n";
        // print();
        
        // cout << "\nAllocation for " << instance << " " << vert << " "; 
        // if(qq.size()!=0)
        // {
        //     qq[0] = mp(vert1,astar[vert1]);
        // }
        // else
        // {
        //     qq.push_back(mp(vert,0));
        // }
        // int sz = 1;
        // for(int i =0;i<n;i++)
        // {
        //     if(i==vert1)
        //     {

        //     }
        //     else
        //     {
        //         qq[sz] = mp(i,astar[i]);
        //         // cout << i << " ";
        //         sz++;
        //     }
        // }
        // cout << "\n\n";
        // print();
        // cout << "\n\n";
    }
};

float compute_dist(pair<int,int> p1, pair<int,int>p2)
{
    return sqrt((float)(p1.first-p2.first)*(float)(p1.first-p2.first) + (float)(p1.second - p2.second)*(float)(p1.second - p2.second));
}



void solve()
{
    
    int n,m;
    cin >> n >> m;
    vector< vector< pair<int,int> > > graph(n,vector< pair<int,int> >()), rgraph(n,vector< pair<int,int> >());

    // vector<vector<double> > distance1(n,vector<double>(n,0));

    vii points(n);

    rep(i,n)
    {
        cin >> points[i].first >> points[i].second;
    }

    // rep(i,n)
    // {
    //     for(int j = i+1;j<n;j++)
    //     {
    //         distance1[i][j] = compute_dist(points[i],points[j]);
    //         distance1[j][i] = distance1[i][j];
    //     }
    // }

    int vert1,vert2,len;

    rep(i,m)
    {
        cin >> vert1 >> vert2 >> len;
        --vert1; --vert2;
        graph[vert1].push_back(mp(vert2,len));
        rgraph[vert2].push_back(mp(vert1,len));
    }

    int q=1;
    cin >> q;

    pair<int,long> vert;
    long fin_dist;

    priqueue myq = priqueue(1);
    priqueue myq1 = priqueue(2);

    vector<bool>vis(n,0),vis1(n,0);

    vector<long> dist(n,1e14),rdist(n,1e14);
    vector<int> visted;
    vector<float> astar(n,0);

    while(q--)
    {

        // vis = vector<bool>(n,0);
        // vis1 = vector<bool>(n,0);
        // dist = vector<long>(n,1e14);
        // rdist =  vector<long>(n,1e14);
        // astar = vector<double>(n,0);

        visted.clear();
        visted.reserve(n);

        cin >> vert1 >> vert2;
        --vert1; --vert2;

        fin_dist = 1e14;


        rep(i,n)
        {
            // astar[i] = (distance1[i][vert2] - distance1[vert1][i])/2;
            astar[i] = (compute_dist(points[i],points[vert2]) - compute_dist(points[vert1],points[i]))/2;
            vis[i] =0;
            vis1[i] = 0;
            dist[i] = 1e14;
            rdist[i] = 1e14;
        }

        dist[vert1] = 0;
        rdist[vert2] = 0;
        

        myq.clear(vert1);

        myq1.clear(vert2);


        while(myq.size()>0&&myq1.size()>0)
        {
            do{
                vert = myq.pop();
            }
            while(myq.size()>0&&vis[vert.first]);

            if(vis[vert.first])
            {
                break;
            }
            

            // cout << "Q1: " << vert.first << " " << vert.second << "\n";

            // myq.print();

            rep(i,graph[vert.first].size())
            {
                if(dist[graph[vert.first][i].first] > dist[vert.first] + graph[vert.first][i].second)
                {
                    dist[graph[vert.first][i].first] = dist[vert.first] + graph[vert.first][i].second;
                    // cout << "Dist1: "<< graph[vert.first][i].first << " " <<  dist[graph[vert.first][i].first] << "\n";
                    myq.push(mp(graph[vert.first][i].first,dist[graph[vert.first][i].first] + astar[graph[vert.first][i].first]));
                }
            }

            // myq.print();

            vis[vert.first] = 1;
            if(vis1[vert.first])
            {
                rep(j,visted.size())
                {
                    if(fin_dist>dist[visted[j]] + rdist[visted[j]])
                    {
                        fin_dist = dist[visted[j]] + rdist[visted[j]];
                    }
                }
                break;
            }

            visted.push_back(vert.first);

            do{
                vert = myq1.pop();
            }
            while(myq1.size()>0&&vis1[vert.first]);
            
            if(vis1[vert.first])
            {
                break;
            }
            // vert = myq1.pop();

            // cout << "Q2: " << vert.first << " " << vert.second << "\n";

            // myq1.print();

            rep(i,rgraph[vert.first].size())
            {
                if(rdist[rgraph[vert.first][i].first] > rdist[vert.first] + rgraph[vert.first][i].second)
                {
                    rdist[rgraph[vert.first][i].first] = rdist[vert.first] + rgraph[vert.first][i].second;
                    // cout << "Dist2: "<< rgraph[vert.first][i].first << " " <<  rdist[rgraph[vert.first][i].first] << "\n";
                    myq1.push(mp(rgraph[vert.first][i].first,rdist[rgraph[vert.first][i].first] - astar[rgraph[vert.first][i].first]));
                }
            }

            // myq1.print();
            vis1[vert.first] = 1;

            if(vis[vert.first])
            {
                rep(j,visted.size())
                {
                    if(fin_dist>dist[visted[j]] + rdist[visted[j]])
                    {
                        fin_dist = dist[visted[j]] + rdist[visted[j]];
                    }
                }
                break;
            }

            visted.push_back(vert.first);
        }
        

        if(fin_dist>=1e14)
        {
            cout << "-1\n";
        }
        else
        {
            cout << fin_dist << "\n";
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


