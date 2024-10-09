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

ll mod_prime = 1000000001;

struct node {
  int key;
  ll sum = 0;
 
  node *left = NULL;
  node *right = NULL;
  node *parent = NULL;
  node(int key, ll sum, node *left, node *right, node *parent): 
    key(key), sum(sum), left(left), right(right), parent(parent) {}
};
class SplayTree{
private:
 
  ll get_sum(node *n){
    if (n == NULL) return 0ll;
    return n->sum;
  }
  void set_parent(node *n, node *p){
    if (n != NULL) n->parent = p;
  }
  void update(node *n){
    if (n == NULL) return;
    n->sum = n->key + get_sum(n->left) + get_sum(n->right);
    set_parent(n->left, n);
    set_parent(n->right, n);
  }
  bool has_parent(node *n){
    if (n == NULL) return false;
    if (n->parent == NULL) return false;
    return true;
  }
  bool has_grand_parent(node *n){
    if (n == NULL) return false;
    if (n->parent == NULL) return false;
    if (n->parent->parent == NULL) return false;
    return true;
  }
  bool is_left_child(node *n){
    if (!has_parent(n)) return false;
    node *p = n->parent;
    return p->left == n;
  }
  bool is_right_child(node *n){
    if (!has_parent(n)) return false;
    node *p = n->parent;
    return p->right == n;
  }

 
  node *root = NULL;
  void small_rotation(node *n){
    /* just pushes node one level up */
    if (!has_parent(n)) return;
    node *parent = n->parent;
    node *grand_parent = parent->parent;
    if (is_left_child(n)){
      node *nr = n->right;
      n->right = parent;
      parent->left = nr;
    } else {
      node *nl = n->left;
      n->left = parent;
      parent->right = nl;
    }
    update(parent);
    update(n);
    n->parent = grand_parent;
    if (grand_parent != NULL){
      if (grand_parent->left == parent) grand_parent->left = n;
      else grand_parent->right = n;
    }
  }
  void big_rotation(node *n){
    if (!has_grand_parent(n)) return;
    if (is_left_child(n) && is_left_child(n->parent)){
      small_rotation(n->parent);
      small_rotation(n);
    }
    else if (is_right_child(n) && is_right_child(n->parent)){
      small_rotation(n->parent);
      small_rotation(n);
    }
    else {
      small_rotation(n);
      small_rotation(n);
    }
  }
  void splay(node *n){
    if (n == NULL) return;
    while(has_parent(n)){
      if (has_grand_parent(n)){
        big_rotation(n);
      }
      else {
        small_rotation(n);
        break;
      }
    }
    root = n;
  }


public:

  SplayTree(){}

  SplayTree(node *root): root(root) {}

  node* find(int key){
    node *v = root;
    node *last = root;
    node *next = NULL;
    while(v != NULL){
      if (v->key >= key && (next == NULL || v->key < next->key)){
        next = v;
      }
      last = v;
      if (v->key == key) break;
      else if (v->key > key) v = v->left;
      else v=v->right;
    }
    splay(last);
    return next;
  }

  bool exists(int key){
    node *c = find(key);
    return (c != NULL && c->key == key);
  }

  void split(int key, node* &left, node* &right){
    if (root == NULL){
      left = NULL;
      right = NULL;
      return;
    }
    right = find(key);
    splay(right);
    if (right == NULL){
      left = root;
      return;
    }
    left = right->left;
    right->left = NULL;
    set_parent(left, NULL);
    update(left);
    update(right);
  }

  static node* merge(node* left, node* right){
    if (left == NULL) return right;
    if (right == NULL) return left;
 
    SplayTree rtree(right);
    node *minr = right;
    while(minr->left != NULL){
      minr = minr->left;
    }
    rtree.splay(minr);
    minr->left = left;
    rtree.update(minr);
    return minr;
  }

  void insert(int key){
    node *left, *right;
    split(key, left, right);
    node *nn = NULL;
    if (right == NULL || right->key != key){
      nn = new node(key, (ll)key, NULL, NULL, NULL);
    }
    root = SplayTree::merge(SplayTree::merge(left, nn), right);
  }

  void erase(int key){
    node *n = find(key);
    if (n != NULL && n->key == key){
      node *next = find(key+1);
      if (next != NULL){
        splay(next);
        splay(n);
        node *nl = n->left;
        next->left = nl;
        set_parent(next, NULL);
        set_parent(nl, next);
        root = next;
        update(root);
      }
      else {
        splay(n);
        node *nl = n->left;
        root = nl;
        set_parent(nl, NULL);
        splay(root);
      }
    }
  }

  ll sum(int l, int r){
    if (l > r) return 0;
    node *left, *middle, *right;
    split(l, left, middle);
    SplayTree mt(middle);
    mt.split(r+1, middle, right);
    ll ans = 0;
    if (middle != NULL) ans += (ll)middle->sum;
    node *nmiddle = SplayTree::merge(left, middle);
    root = SplayTree::merge(nmiddle, right);
    return ans;
  }
  void print(){
    inorder(root);
  }
  void inorder(node *cur){
    if (cur == NULL) return;
    inorder(cur->left);
    inorder(cur->right);
  }
};
 

void solve()
{
    ll sum = 0, input1 = 0, input2 = 0;
    char s;
    SplayTree t;
    int num = 0;
    cin >> num;
    while(cin >> s)
    {
        cin >> input1;
        input1 = (input1 + sum)%mod_prime;
        if(s=='+')
        {
            t.insert(input1);
        }
        else if(s == '-')
        {
            t.erase(input1);
        }
        else if(s == '?')
        {
            node* n = t.find(input1);
            if(n!=nullptr&&n->key == input1)
            {
                cout << "Found\n";
            }
            else
            {
                cout << "Not Found\n";
            }
        }
        else
        {
            cin >> input2;
            input2 = (sum+input2)%mod_prime;
            sum  = t.sum(input1,input2);
            cout << sum << "\n";
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


