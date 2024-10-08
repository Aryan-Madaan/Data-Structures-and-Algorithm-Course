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

struct treenode 
{
    // treenode* parent = nullptr;
    treenode* left = nullptr;
    treenode* right = nullptr;
    int key;
};

void order1(treenode* node)
{ 
    if(node->left!=nullptr)
    {
        order1(node->left);
    }
    cout << node->key << " ";
    if(node->right!=nullptr)
    {
        order1(node->right);
    }
}

void order2(treenode* node)
{
    cout << node->key << " ";
    if(node->left!=nullptr)
    {
        order2(node->left);
    }
    if(node->right!=nullptr)
    {
        order2(node->right);
    }
}


void order3(treenode* node)
{ 
    if(node->left!=nullptr)
    {
        order3(node->left);
    }
    if(node->right!=nullptr)
    {
        order3(node->right);
    }
    cout << node->key << " ";
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vii pp(n);
        vector<int> key(n);
        rep(i,n)
        {
            cin >> key[i] >> pp[i].first >> pp[i].second;
        }
        vector<treenode*> vv;
        rep(i,n)
        {
            treenode* node = new treenode;
            node->key = key[i];
            vv.push_back(node);
        }
        rep(i,n)
        {
            vv[i]->left = pp[i].first!=-1?vv[pp[i].first]:nullptr;
            vv[i]->right = pp[i].second!=-1?vv[pp[i].second]:nullptr;
            // if(pp[i].first!=-1)
            // {
            //     vv[pp[i].first]->parent = vv[i];
            // }
            // if(pp[i].second!=-1)
            // {
            //     vv[pp[i].second]->parent = vv[i];
            // }
        }
        order1(vv[0]);
        cout << "\n";
        order2(vv[0]);
        cout << "\n";
        order3(vv[0]);
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


