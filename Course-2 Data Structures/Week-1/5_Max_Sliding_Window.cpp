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

struct node
{
    int key;
    int max_val;
    int pos;
    node* next;
};

class myqueue
{
    private:
    node* head;
    node* temp;

    public:
    myqueue()
    {
        head = nullptr;
        temp = nullptr;
    }
    void push(int &val,int &pos1)
    {
        if(head == nullptr)
        {
            head = new node();
            head->key = val;
            head->max_val = val;
            head->pos = pos1;
        }
        else
        {
            temp = new node();
            temp->key = val;
            temp->pos = pos1;
            temp->max_val = max(val,head->max_val);
            temp->next = head;
            head = temp;
        }
    }
    void pop()
    {
        if(head!=nullptr)
        {
            head = head->next;
        }
    }
    node* currhead()
    {
        return head;
    }
    void print_max()
    {
        if(head!=nullptr)
        {
            cout << head->max_val << " ";
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
        cin >> n;
        vector<int>vv(n,0);
        rep(i,n) cin >> vv[i];
        cin >> m;
        // vector<int>
        deque<pair<int,int> > myq;
        rep(i,n)
        {
            if(myq.empty())
                myq.push_back(mp(vv[i],i));
            else
            {
                while(!myq.empty()&&myq.front().second<=i-m)
                {
                    myq.pop_front();
                }
                while(!myq.empty()&&myq.back().second<=i-m)
                {
                    myq.pop_back();
                }
                if(myq.front().first<=vv[i])
                {
                    while(!myq.empty())
                    {
                         myq.pop_back();
                    }
                    myq.push_front(mp(vv[i],i));
                }
                else
                {
                    while(!myq.empty()&&myq.back().first<=vv[i])
                    {
                         myq.pop_back();
                    }
                    myq.push_back(mp(vv[i],i));
                }
            }
            if(i>=m-1)
            {
                cout << myq.front().first << " ";
            }
        }

        
        // myqueue q1,q2;
        // int inx = 0;
        // node* temp = nullptr;
        // for(int i = n-1;i>=0;i--)
        // {
        //     q1.push(vv[i],i);
        // }
        // while(inx<=n-m)
        // {
        //     for(int i = inx;i-inx<m&&i<n;i++)
        //     {
        //         temp = q1.currhead();
        //         q2.push(temp->key,temp->pos);
        //         q1.pop();
        //     }
        //     q2.print_max();
        //     for(int i = inx;i-inx<m-1&&i<n;i++)
        //     {
        //         temp = q2.currhead();
        //         q1.push(temp->key,temp->pos);
        //         q2.pop();
        //     }
        //     q2.pop();
        //     inx++;
        // }
        // vector<int> v1;
        // for(int i =0;i<n;i+=m)
        // {
        //     int maxi = INT_MIN;
        //     for(int j = i;j-i<m&&j<n;j++)
        //     {
        //         maxi = max(maxi,vv[j]);
        //     }
        //     cout << maxi << " ";
        // }
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


