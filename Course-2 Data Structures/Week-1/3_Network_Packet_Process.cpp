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
    node *next;
};

class list_1
{
    private:
    int size;
    int allowed_size;
    node *head;
    node *tail;

    public:
    list_1(int &a_size)
    {
        allowed_size = a_size;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    int insert(pair<int,int> &mypp)
    {
        node *temp = head;
        while(temp!=nullptr)
        {
            if(temp->key<=mypp.first)
            {
                head = head->next;
                size--;
            }
            else
            {
                break;
            }
            temp=temp->next;
        }
        if(head == nullptr)
        {
            head = new node();
            tail = head;
            head->key = mypp.first+mypp.second;
            head->next = nullptr;
            size++;
            return mypp.first;
        }
        else
        {
            if(size < allowed_size)
            {
                int result = 0;
                tail->next = new node();
                tail->next->key = tail->key + mypp.second;
                result = tail->key;
                tail= tail->next;
                size++;
                return result;
            }
            else
            {
                return -1;
            }
        }
    }
};



void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int s,n;
        cin>>s>>n;
        vector< pair<int,int> > vv(n,mp(0,0));
        rep(i,n)
        {
            cin >> vv[i].first >> vv[i].second;
        }
        list_1 mylist(s);
        rep(i,n)
        {
            cout << mylist.insert(vv[i]) << "\n";
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


