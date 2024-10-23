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


struct node
{
    int idx;
    char val;
    vector<node*> children;
    node* parent;
};

int idx_val = 0;

void travel(node* tmp)
{
    if(tmp == nullptr)
    {
        return;
    }
    tmp->idx = idx_val;
    ++idx_val;
    if(tmp->parent!=nullptr)
    {
        cout << tmp->parent->idx << "->" << tmp->idx << ':' << tmp->val << '\n';
    }
    rep(i,tmp->children.size())
    {
        travel(tmp->children[i]);
    }
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        node * root = new node;
        root->idx = 0;
        root->parent = nullptr;
        int idx = 0;
        node* tmp,*nw_tmp;
        bool flag = true;
        rep(i,n)
        {
            cin >> s;
            tmp = root;
            idx = 0;
            while(idx<s.size())
            {
                flag = true;
                rep(k,tmp->children.size())
                {
                    if(tmp->children[k]->val == s[idx])
                    {
                        flag = false;
                        tmp = tmp->children[k];
                        idx++;
                        break;
                    }
                }
                if(flag)
                {
                    nw_tmp = new node;
                    nw_tmp->parent = tmp;
                    nw_tmp->val = s[idx];
                    tmp->children.push_back(nw_tmp);
                    tmp = nw_tmp;
                    idx++;
                }
            }
        }
        travel(root);
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


