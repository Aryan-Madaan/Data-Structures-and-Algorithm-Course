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

struct node {
    int start;
    int end;
    int stringDepth;
    map<char,node*> children;
    // map<int,node*> children;
    node* parent;
};

// int nodeid = 0;

void travel(string &s,node*temp)
{
    if(temp == nullptr) return;
    // rep(i,temp->end - temp->start + 1) cout << s[i+temp->start];
    // cout << " ";
    cout << temp->start << " " << temp->end +1 <<"\n";
    for(auto i : temp->children)
    {
        travel(s,i.second);
    }
}

node* createNewLeaf(node* currNode,string &s, int suffix)
{
    // cout << "\nCreating New Leaf " << suffix << " Curr node " << currNode->stringDepth << "\n";
    node* leaf = new node;
    leaf->parent = currNode;
    leaf->stringDepth = s.size() - suffix;
    leaf->start = suffix + currNode->stringDepth;
    leaf->end = s.size()-1;
    currNode->children[s[leaf->start]] = leaf;
    // currNode->children[leaf->start] = leaf;
    return leaf;
}

node* breakEdge(node* currNode,string &s,int start, int offset)
{
    char startChar = s[start];
    char midChar = s[start + offset];
    // int startChar = start;
    // int midChar = start + offset;
    // cout << "Breaking Edge : " << start << " " << offset << " " <<  currNode->stringDepth << "\n";
    node* midNode = new node;
    midNode-> parent = currNode;
    midNode->stringDepth = currNode->stringDepth + offset;
    midNode->start = start;
    midNode->end = start + offset - 1;
    midNode->children[midChar] = currNode->children[startChar];
    currNode->children[startChar]->parent = midNode;
    currNode->children[startChar]->start +=offset;
    currNode->children[startChar] = midNode;
    return midNode;
}

node* createSuffixTree(string &s, vector<int> &order, vector<int> &lcpArray)
{
    node* root = new node;
    root->parent = nullptr;
    root->start = 0;
    root->end = 0;
    root->stringDepth = 0;
    node* currNode = root;
    node* midNode = nullptr;
    int lcpPrev = 0,suffix = 0,edgeStart = 0, offset = 0;

    rep(i,s.size())
    {

        suffix = order[i];

        while (currNode!=root&&currNode->stringDepth >lcpPrev)
        {
            currNode = currNode->parent;
        }
        // cout << "String Depth: " << currNode->stringDepth << " " << lcpPrev << "\n";

        if (currNode->stringDepth == lcpPrev)
        {
            currNode = createNewLeaf(currNode,s,suffix);
        }
        else
        {
            edgeStart = order[i-1] + currNode->stringDepth;
            offset = lcpPrev - currNode->stringDepth;
            // cout << edgeStart << " " << offset << "\n";
            midNode = breakEdge(currNode,s,edgeStart,offset);
            currNode = createNewLeaf(midNode,s,suffix);
        }

        if (i<s.size()-1)
        {
            lcpPrev = lcpArray[i];
        }

        // for(auto k : root->children)
        // {
        //     travel(s,k.second);
        // }
    }
    return root;
}



void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s;

        cin >> s;

        vector<int> suffix(s.size(),0),lcp(s.size()-1,0);

        rep(i,s.size())
        {
            cin >> suffix[i];
        }

        rep(i,s.size()-1)
        {
            cin >> lcp[i];
        }

        node* root =  createSuffixTree(s,suffix,lcp);

        cout << s << "\n";

        // cout << root->children.size() << " \n";

        for(auto i : root->children)
        {
            travel(s,i.second);
        }

        // map<int, vector<Edge> >

        // vector<pair<int, int> > stack(1, make_pair(0, 0));    
        // while (!stack.empty()) {
        //     pair<int, int> p = stack.back();
        //     stack.pop_back();
        //     int node = p.first;
        //     int edge_index = p.second;
        //     if (!tree.count(node)) {
        //     continue;
        //     }
        //     const vector<Edge>& edges = tree[node];
        //     if (edge_index + 1 < edges.size()) {
        //     stack.push_back(make_pair(node, edge_index + 1));
        //     }
        //     printf("%d %d\n", edges[edge_index].start, edges[edge_index].end);
        //     stack.push_back(make_pair(edges[edge_index].node, 0));
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
