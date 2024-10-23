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
    vector< pair< int,long>  > qq;
    // vector<int> loc;
    int l,r,parent,min_idx;
    int tmp;
    pair< int,long> temp,temp1;
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
        // tmp = loc[qq[j].first];
        // loc[qq[j].first] = loc[qq[i].first];
        // loc[qq[i].first] = tmp;
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
    //     // loc = vector<int>(m,-1);
    //     // loc.resize(n);
    //     // rep(i,loc.size())
    //     // {
    //     //     loc[i] = -1;
    //     // }
        instance = inst;
    }

    // void changepri(int i, long pri)
    // {
    //     if(loc[i]==-1 || qq[loc[i]].second <= pri) return;

    //     qq[loc[i]].second = pri;
    //     siftup(loc[i]);
    // }

    void push(pair<int,long> inp)
    {
        // loc[inp.first] = qq.size();
        qq.push_back(inp);
        siftup(qq.size()-1);
    }

    pair<int,long> pop()
    {
        temp1 = qq[0];
        swap(0,qq.size()-1);
        // loc[temp1.first] = -1;
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
        // cout << "\n\nPrinting Loc\n";
        // rep(i,loc.size())
        // {
        //     cout << loc[i] << " ";
        // }
        cout << endl;
    }

    void clear(int vert,int n)
    {
        qq.resize(n);

        // cout << "\n\n";
        // print();
        
        // cout << "\nAllocation for " << instance << " " << vert << " "; 
        if(qq.size()!=0)
        {
            qq[0] = mp(vert,0);
        }
        // else
        // {
        //     qq.push_back(mp(vert,0));
        // }
        int sz = 1;
        for(int i =0;i<n;i++)
        {
            if(i==vert)
            {

            }
            // else if(sz>=qq.size())
            // {
            //     qq.push_back(mp(i,1e14));
            //     sz++;
            //     // cout << i << " ";
            // }
            else
            {
                qq[sz] = mp(i,1e14);
                // cout << i << " ";
                sz++;
            }
        }
        // cout << "\n\n";
        // print();
        // cout << "\n\n";
    }
};



void solve()
{
    
    int n,m;
    // scanf("%d %d", &n, &m);
    cin >> n >> m;
    vector< vector< pair<int,int> > > graph(n,vector< pair<int,int> >()), rgraph(n,vector< pair<int,int> >());

    int vert1,vert2,len;

    rep(i,m)
    {
        // scanf("%d %d %d", &vert1, &vert2, &len);
        cin >> vert1 >> vert2 >> len;
        --vert1; --vert2;
        graph[vert1].push_back(mp(vert2,len));
        rgraph[vert2].push_back(mp(vert1,len));
    }

    int q=1;
    // scanf("%d", &q);
    cin >> q;

    pair<int,long> vert;
    long fin_dist;

    priqueue myq = priqueue(1);
    priqueue myq1 = priqueue(2);

    vector<bool>vis(n,0),vis1(n,0);

    vector<long> dist(n,1e14),rdist(n,1e14);
    vector<int> visted;

    while(q--)
    {
        // while(myq.size()>0)
        // {
        //     myq.pop();
        // }
        // while(myq1.size()>0)
        // {
        //     myq1.pop();
        // }



        // rep(i,n)
        // {
        //     vis[i]= vis1[i] = 0;
        //     dist[i] = rdist[i] = 1e14;
        // }

        vis = vector<bool>(n,0);
        vis1 = vector<bool>(n,0);
        dist = vector<long>(n,1e14);
        rdist =  vector<long>(n,1e14);

        visted.clear();
        visted.reserve(n);

        // scanf("%d %d", &vert1, &vert2);
        cin >> vert1 >> vert2;
        --vert1; --vert2;

        fin_dist = 1e14;

        dist[vert1] = 0;
        rdist[vert2] = 0;

        myq.clear(vert1,n);

        myq1.clear(vert2,n);

        // myq.print();

        // myq.push(mp(vert1,0));

        // rep(i,n)
        // {
        //     if(i!=vert1)
        //     {
        //         myq.push(mp(i,1e14));
        //     }
        // }

        // myq1.push(mp(vert2,0));

        // rep(i,n)
        // {
        //     if(i!=vert2)
        //     {
        //         myq1.push(mp(i,1e14));
        //     }
        // }

        // vector<bool> vis(n,0),rvis(n,0);


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
                    myq.push(mp(graph[vert.first][i].first,dist[graph[vert.first][i].first]));
                    // myq.changepri(graph[vert.first][i].first,dist[graph[vert.first][i].first]);
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
                    myq1.push(mp(rgraph[vert.first][i].first,rdist[rgraph[vert.first][i].first]));
                    // myq1.changepri(rgraph[vert.first][i].first,rdist[rgraph[vert.first][i].first]);
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
            // printf("-1\n");
            cout << "-1\n";
        }
        else
        {
            // printf("%lu\n",fin_dist);
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


