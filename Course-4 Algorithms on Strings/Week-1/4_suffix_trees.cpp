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
    int start;
    int length;
    vector<node*>children;
    node* parent;
};

node* new_node;

void travel(node* tmp,string &s,int idx)
{
    if(tmp==nullptr)
    {
        return;
    }
    rep(i,tmp->length)
    {
        cout << s[i+tmp->start];
    }
    // cout << " " <<idx;
    cout <<"\n";
    rep(i,tmp->children.size())
    {
        travel(tmp->children[i],s,idx + 1);
    }
}

void fill(node* tmp,string&s,int idx,int parent_idx)
{
    if(tmp == nullptr|| idx>=s.size())
    {
        return;
    }
    // cout << "String Output : ";
    // for(int i =idx;i<s.size();i++)
    // {
    //     cout << s[i];
    // }
    // cout << "\n";
    if(tmp->idx == -1)
    {
        rep(i,tmp->children.size())
        {
            if(s[tmp->children[i]->start] == s[idx])
            {
                fill(tmp->children[i],s,idx,i);
                return;
            }
        }
        new_node = new node;
        new_node->idx = 0;
        new_node->start = idx;
        new_node->length = s.size() - idx;
        new_node->parent = tmp;
        tmp->children.push_back(new_node);
    }
    else
    {
        rep(i,tmp->length)
        {
            // cout << s[i+tmp->start] << " " << s[idx+i] << "\n";
            if(s[i+tmp->start]!=s[idx+i])
            {
                if(i==0)
                {
                    new_node = new node;
                    new_node->idx=0;
                    new_node->start = idx;
                    new_node->length = s.size() - idx;
                    new_node->parent = tmp->parent;
                    tmp->parent->children.push_back(new_node);
                }
                else
                {
                    new_node = new node;
                    new_node->idx=0;
                    new_node->start = tmp->start;
                    new_node->length = i;
                    new_node->parent = tmp->parent;
                    tmp->length = tmp->length - new_node->length;
                    tmp->start = tmp->start + i;
                    tmp->parent->children[parent_idx] = new_node;
                    tmp->parent = new_node;
                    new_node->children.push_back(tmp);
                    tmp = new_node;

                    new_node = new node;
                    new_node->idx=0;
                    new_node->start = idx + i;
                    new_node->length = s.size() - idx - i;
                    new_node->parent = tmp;
                    tmp->children.push_back(new_node);
                }
                return;
            }
        }


        rep(i,tmp->children.size())
        {
            if(idx+tmp->length<s.size()&&s[tmp->children[i]->start] == s[idx+tmp->length])
            {
                fill(tmp->children[i],s,idx+tmp->length,i);
                return;
            }
        }
        if(idx+tmp->length<s.size())
        new_node = new node;
        new_node->idx = 0;
        new_node->start = idx+tmp->length;
        new_node->length = s.size() - idx - tmp->length;
        new_node->parent = tmp;
        tmp->children.push_back(new_node);
    }
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        // s = s+'$';
        int idx = 0;
        node* root = new node;
        root->parent = nullptr;
        root->start = root->length = -1;
        root->idx = -1;
        // node* tmp,*add_child;
        rep(i,s.size())
        {
            fill(root,s,i,0);
        }
        rep(i,root->children.size())
        {
            travel(root->children[i],s,0);
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


