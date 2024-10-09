//                                               Created by Aryan Madaan.
//---------------------------------------------------------------------------------------------------
#pragma optimize("O3",on)
#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
using namespace std::chrono;
#define Expresso std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define rep(i,n) for(int i =0;i<n;i++)
#define endl '\n'

//---------------------------------------------------------------------------------------------------

struct node {
    int idx;
    char val;
    int size;
    node *left;
    node *right;
    node *parent;
};

class RopeStructure
{
    node* root;

    public:

    RopeStructure(string s)
    {
        root = nullptr;
        for(int i = 0;i<s.size();i++)
        {
            node* temp = new node;
            temp->idx = i+1;
            temp->val = s[i];
            temp->size = 1;
            temp->left = nullptr;
            temp->right = nullptr;
            temp->parent = nullptr;
            root = merge(root, temp);
        }
    }

    void result_order_find(node* temp,string &result)
    {
        if(temp == nullptr)
        {
            return;
        }
        result_order_find(temp->left,result);

        // cout << temp->val;
        result.push_back(temp->val);

        result_order_find(temp->right,result);
    }

    string result_func()
    {
        string result = "";
        // node* root1 = root;
        result_order_find(root,result);
        return result;
    }

    int get_size(node* temp)
    {
        if (temp==nullptr)
        {
            return 0;
        }
        return temp->size;
    }

    void update_parent(node* temp)
    {
        if (temp->left != nullptr){
            temp->left->parent = temp;
        }
        if(temp->right != nullptr)
        {
            temp->right->parent = temp;
        }
    }

    void update(node* temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        temp->size = get_size(temp->left) + get_size(temp->right) + 1;
        update_parent(temp);
    }

    void small_rotation(node* temp)
    {
        // cout << "Rot1 " << result_func() << " \n";
        node* prnt = temp->parent;
        if(prnt == nullptr) return;

        node* grandparent = temp->parent->parent;
        node* tmp = nullptr;

        if(prnt->left == temp)
        {
            tmp = temp->right;
            temp->right = prnt;
            prnt->left = tmp;
            // cout << "Rot11 " << result_func() << " \n";
        }
        else
        {
            tmp = temp->left;
            temp->left = prnt;
            prnt->right = tmp;
            // cout << "Rot12 " << result_func() << " \n";
        }

        update(prnt);
        update(temp);

        temp->parent = grandparent;

        if(grandparent != nullptr)
        {
            if(grandparent->left == prnt)
            {
                grandparent->left = temp;
            }
            else
            {
                grandparent->right = temp;
            }
        }
        // update(grandparent);
        // cout << "Rot13 " << result_func() << " \n";
        // cout << "Rot14 " << result_func() << " \n";
    }

    void  big_rotation(node* temp)
    {
        if (temp->parent->left == temp && temp->parent->parent->left == temp->parent)
        {
            small_rotation(temp->parent);
            small_rotation(temp);
        }
        else if (temp->parent->right == temp && temp->parent->parent->right == temp->parent)
        {
            small_rotation(temp->parent);
            small_rotation(temp);
        }
        else
        {
            small_rotation(temp);
            small_rotation(temp);
        }
    }

    node* splay(node* temp)
    {
        if (temp == nullptr)
        {
            return nullptr;
        }

        while (temp->parent != nullptr)
        {
            if(temp->parent->parent==nullptr)
            {
                small_rotation(temp);
                break;
            }
            else
            {
                big_rotation(temp);
            }
        }

        root = temp;
        return temp;
    }

    node* find(node* root1, int index)
    {
        int val = 0;
        node* temp = root1;
        if (temp == nullptr)
        {
            return nullptr;
        }
        if(temp->left == nullptr)
        {
            val = 0;
        }
        else
        {
            val = get_size(temp->left);
        }
        node* ans = nullptr;

        if(index == val+1)
        {
            return temp;
        }
        else if (index < val + 1)
        {
            return find(temp->left,index);
        }
        else
        {
            return find(temp->right, index - val - 1);
        }
    }

    pair<node*, node*> split(node* root1)
    {
        node* left = nullptr;
        node* right = nullptr;
        pair<node*, node*> res;
        if (root1==nullptr)
        {
            left = root1;
            right = nullptr;
            res.first = left;
            res.second = right;
            return res;
        }

        right = root1;

        left = right->left;

        right->left = nullptr;

        if (left != nullptr)
        {
            left->parent = nullptr;
        }
        right -> parent = nullptr;

        update(left);
        update(right);

        res.first = left;
        res.second = right;
        return res;
    }

    node* merge(node* left, node* right)
    {
        if(left == nullptr)
        {
            return right;
        }
        else if(right == nullptr)
        {
            return left;
        }
        
        while (right->left != nullptr)
        {
            right = right->left;
        }

        right = splay(right);

        right->left = left;
        
        left->parent = right;

        update(right);

        return right;

    }

    void process(int &nnn)
    {
        int i,j,k;
        node* left = nullptr;
        node* right = nullptr;
        node* mid = nullptr;
        node* mid1 = nullptr;
        node* temp = nullptr;
        node* temp2 = nullptr;
        node* res = nullptr;
        pair<node*,node*> vv;

        for(int kkk =0;kkk<nnn;kkk++)
        {
            // auto ms2 = duration_cast< chrono::milliseconds >(system_clock::now().time_since_epoch()).count();
            cin >> i >> j >> k;
            // cout << i << " " << j << " " << k<< "\n";
            ++i;++j;++k;

                res = splay(find(root,j+1));
                if (res != nullptr)
                {
                    vv = split(res);
                    left = vv.first;
                    right = vv.second;
                    // cout << " 7 " <<result_func() << "\n";
                    if(i!=1)
                    temp = splay(find(left,i));
                    else
                    temp = nullptr;
                    // cout << " 8 " <<result_func() << "\n";
                    if(temp==nullptr)
                    {
                        temp2 = splay(find(right,k));
                        // cout << " 9 " <<result_func() << "\n";
                        if(temp2!=nullptr)
                        {
                            vv = split(temp2);
                            mid= vv.first;
                            right = vv.second;
                            // cout << " 10 " <<result_func() << "\n";
                            left = merge(mid,left);
                            // cout << " 11 " <<result_func() << "\n";
                            root = merge(left,right);
                            // cout << " 12 " <<result_func() << "\n";
                        }
                        else
                        {
                            root = merge(right,left);
                            // cout << " 13 " <<result_func() << "\n";
                        }
                    }
                    else
                    {
                        vv = split(temp);
                        left= vv.first;
                        mid = vv.second;
                        // cout << " 15 " <<result_func() << "\n";
                        left = merge(left,right);
                        temp2 = splay(find(left,k));
                        // cout << " 16 " <<result_func() << "\n";
                        if(temp2!=nullptr)
                        {
                            vv = split(temp2);
                            // cout << " 17 " <<result_func() << "\n";
                            left = vv.first;
                            right = vv.second;
                            left = merge(left,mid);
                            // cout << " 18 " <<result_func() << "\n";
                            root = merge(left,right);
                            // cout << " 19 " <<result_func() << "\n";
                        }
                        else
                        {
                            root = merge(left,mid);
                            // cout << " 20 " <<result_func() << "\n";
                        }
                    }
                }
                else
                {
                    // root = merge(left,right);
                    // cout << " 17 " <<result_func() << "\n";
                    if(i!=1)
                    {
                        temp = splay(find(root,i));
                        // cout << " 18 " <<result_func() << "\n";
                        vv = split(temp);
                        left = vv.first;
                        right = vv.second;
                        // cout << " 19 " <<result_func() << "\n";
                        temp2 = splay(find(left,k));
                        // cout << " 20 " <<result_func() << "\n";
                        if(temp2!=nullptr)
                        {
                            // cout << " 21 " <<result_func() << "\n";
                            // split(temp2,left,mid);
                            vv = split(temp2);
                            left = vv.first;
                            mid = vv.second;
                            // cout << " 22 " <<result_func() << "\n";
                            left = merge(left,right);
                            // cout << " 23 " <<result_func() << "\n";
                            root = merge(left,mid);
                            // cout << " 24 " <<result_func() << "\n";
                        }
                        else
                        {
                            root = merge(left,right);
                            // cout << " 25 " <<result_func() << "\n";
                        }
                    }
                }
                // auto ms1 = duration_cast< chrono::milliseconds >(system_clock::now().time_since_epoch()).count();
                // if(ms1-ms2 > 10)
                // cout << "time " << kkk << " " << ms1-ms2 << "\n";
                                   
            // }

//End of for loop
        }
        // cout << result_func() << "\n";
    }
};

 

void solve()
{
    string s;
    // auto ms1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();
    cin >> s;
    // auto ms2 = duration_cast< chrono::milliseconds >(system_clock::now().time_since_epoch()).count();
    // cout << " time " << ms2 - ms1 << "\n";
    int n;
    cin >> n;
    RopeStructure rope = RopeStructure(s);
    rope.process(n);
    cout << rope.result_func();
}
/*
*/





//---------------------------------------------------------------------------------------------------
int main() {
    Expresso
    solve();
    return 0;
}