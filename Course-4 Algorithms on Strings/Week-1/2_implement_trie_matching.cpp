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
    bool leaf;
    vector<node*> children;
    node* parent;
};

void travel(node* tmp,map<int,bool> &matches,string &pattern,int idx,int &start)
{
    if(tmp == nullptr)
    {
        return;
    }
    // cout << "Value " << tmp->val << " : " << tmp->leaf << " " << idx << " " << pattern << "\n";
    if(tmp->leaf)
    {
        matches[start] = 1;
        return;
    }
    if(tmp->val == pattern[idx])
    {
        rep(i,tmp->children.size())
        {
            travel(tmp->children[i],matches,pattern,idx+1,start);
        }
    }
    else
    {
        return;
    }
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s;
        node * root = new node;
        root->idx = 0;
        root->parent = nullptr;
        int idx = 0;
        node* tmp,*nw_tmp;
        bool flag = true;
        cin >> s;
        map<int,bool> matches;
        int n;
        cin >> n;
        vector<string>pattern(n);
        rep(i,n)
        {
            cin >> pattern[i];
        }
        rep(i,n)
        {
            tmp = root;
            idx = 0;
            while(idx<pattern[i].size())
            {
                flag = true;
                rep(k,tmp->children.size())
                {
                    if(tmp->children[k]->val == pattern[i][idx])
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
                    nw_tmp->val = pattern[i][idx];
                    nw_tmp->leaf = false;
                    tmp->children.push_back(nw_tmp);
                    tmp = nw_tmp;
                    idx++;
                }
            }
            nw_tmp = new node;
            nw_tmp->parent = tmp;
            nw_tmp->leaf = true;
            nw_tmp->idx = i;
            tmp->children.push_back(nw_tmp);
        }
        rep(i,s.size())
        rep(j,root->children.size())
        {
            travel(root->children[j],matches,s,i,i);
        }
        for(auto mp:matches)
        {
            cout << mp.first << " ";
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


