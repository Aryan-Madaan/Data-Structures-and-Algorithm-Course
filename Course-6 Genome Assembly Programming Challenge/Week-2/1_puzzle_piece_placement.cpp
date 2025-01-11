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


const int NUM_ROWS = 5;
const int TOP = 0;
const int LEFT = 1;
const int BOTTOM = 2;
const int RIGHT = 3;
//(up,left,down,right)

const string SIDE_COLOUR = "black";

// bool check_all(vector<int>&v1,vector<int>&v2,bool top, bool left, bool bottom, bool right)
// {
//     bool val = 1;
//     if(top)
//     {
bool check_top(vector<int>&v1,vector<int>&v2){
    return (v1.size()==0 || v1[BOTTOM] == v2[TOP]);
}
bool check_left(vector<int>&v1,vector<int>&v2)
{
    return (v1.size()==0 || v1[RIGHT] == v2[LEFT]);
}
bool check_bottom(vector<int>&v1,vector<int>&v2)
{
    return (v1.size()==0 || v1[TOP] == v2[BOTTOM]);
}
bool check_right(vector<int>&v1,vector<int>&v2)
{
    return (v1.size()==0 || v1[LEFT] == v2[RIGHT]);
}


bool sort_col(vector<vector< vector<int> > > &final_vector,int i ,int j,vector< vector<int>> middle,vector< vector<int>> left, vector< vector<int>> right,vector< vector<int>> top,vector< vector<int>> bottom)
{
    if(j>=NUM_ROWS)
    {
        ++i;j=0;
    }
    // cout << "IN " << i << " : " << j <<"\n";
    if(i>=NUM_ROWS || j>=NUM_ROWS)
    {
        return 1;
    }
    else if(final_vector[i][j].size()!=0)
    {
        return sort_col(final_vector,i,j+1,middle,left,right,top,bottom);
    }
    else if(i == 0)
    {
        for(int k = 0;k<top.size();k++)
        {
            if(check_right(final_vector[i][j+1],top[k])&&check_left(final_vector[i][j-1],top[k])&&check_bottom(final_vector[i+1][j],top[k])){
                vector<vector<int>> temp1 = top;
                temp1.erase(temp1.begin()+k);
                final_vector[i][j] = top[k];
                if(sort_col(final_vector,i,j+1,middle,left,right,temp1,bottom))
                {
                    return 1;
                }
                                else
                {
                    final_vector[i][j] = vector<int>();
                }
            }
        }
    }
    else if(j == 0)
    {
        for(int k = 0;k<left.size();k++)
        {
            if(check_right(final_vector[i][j+1],left[k])&&check_top(final_vector[i-1][j],left[k])&&check_bottom(final_vector[i+1][j],left[k])){
                vector<vector<int>> temp1 = left;
                temp1.erase(temp1.begin()+k);
                final_vector[i][j] = left[k];
                if(sort_col(final_vector,i,j+1,middle,temp1,right,top,bottom))
                {
                    return 1;
                }
                                else
                {
                    final_vector[i][j] = vector<int>();
                }
            }
        }
    }
    else if(j == NUM_ROWS-1)
    {
        for(int k = 0;k<right.size();k++)
        {
            if(check_left(final_vector[i][j-1],right[k])&&check_top(final_vector[i-1][j],right[k])&&check_bottom(final_vector[i+1][j],right[k])){
                vector<vector<int>> temp1 = right;
                temp1.erase(temp1.begin()+k);
                final_vector[i][j] = right[k];
                if(sort_col(final_vector,i,j+1,middle,left,temp1,top,bottom))
                {
                    return 1;
                }
                                else
                {
                    final_vector[i][j] = vector<int>();
                }
            }
        }
    }
    else if(i == NUM_ROWS-1)
    {
        for(int k = 0;k<bottom.size();k++)
        {
            // rep(gg,bottom[k].size())
            // {
            //     cout << bottom[k][gg] << ":";
            // }
            // cout <<"\n";

            // cout << "Checking... Right:" << (check_right(final_vector[i][j+1],bottom[k]));
            // cout << " Left: "<<  check_left(final_vector[i][j-1],bottom[k]);
            // cout << " Top: " << check_top(final_vector[i-1][j],bottom[k]) << "\n";
            if(check_left(final_vector[i][j-1],bottom[k])&&check_top(final_vector[i-1][j],bottom[k])&&check_right(final_vector[i][j+1],bottom[k])){
                vector<vector<int>> temp1 = bottom;
                temp1.erase(temp1.begin()+k);
                final_vector[i][j] = bottom[k];
                if(sort_col(final_vector,i,j+1,middle,left,right,top,temp1))
                {
                    return 1;
                }
                                else
                {
                    final_vector[i][j] = vector<int>();
                }
            }
        }
    }
    else
    {
        for(int k = 0;k<middle.size();k++)
        {
            if(check_left(final_vector[i][j-1],middle[k])&&check_top(final_vector[i-1][j],middle[k])&&check_right(final_vector[i][j+1],middle[k])&&check_bottom(final_vector[i][j+1],middle[k])){
                vector<vector<int>> temp1 = middle;
                temp1.erase(temp1.begin()+k);
                final_vector[i][j] = middle[k];
                if(sort_col(final_vector,i,j+1,temp1,left,right,top,bottom))
                {
                    return 1;
                }
                else
                {
                    final_vector[i][j] = vector<int>();
                }
            }
        }
    }

    return 0;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        vector< vector<int>> middle,left,right,top,bottom;
        vector<int> temp(4,0);
        string s;
        string word;

        vector<vector< vector<int> > > final_vector(NUM_ROWS,vector< vector<int> >(NUM_ROWS));

        unordered_map<string,int> col;
        unordered_map<int,string> col_to_int;
        col[SIDE_COLOUR] = 1;
        col_to_int[1] = SIDE_COLOUR;

        vector<bool> used(NUM_ROWS*NUM_ROWS,0);

        rep(i,NUM_ROWS*NUM_ROWS)
        {
            cin >> s;
            stringstream ss(s);
            int word_len = 0;
            while (!ss.eof()) {
                getline(ss, word, ',');
                if(word[0]=='(')
                {
                    word = word.substr(1,word.size()-1);
                }
                if(word[word.size()-1]==')')
                {
                    word = word.substr(0,word.size()-1);
                }
                // cout << word << endl;
                if(col.find(word) == col.end())
                {
                    col[word] = col.size() + 1;
                    col_to_int[col[word]] = word;
                }
                temp[word_len] = col[word];
                word_len++;
                // cout << word << ":" << col[word] <<endl;
            }

            if(temp[TOP]==col[SIDE_COLOUR]&&temp[LEFT]==col[SIDE_COLOUR])
            {
                final_vector[0][0] = temp;   
            }

            else if(temp[TOP]==col[SIDE_COLOUR]&&temp[RIGHT]==col[SIDE_COLOUR])
            {
                final_vector[0][NUM_ROWS-1] = temp;
            }

            else if(temp[LEFT]==col[SIDE_COLOUR]&&temp[BOTTOM]==col[SIDE_COLOUR])
            {
                final_vector[NUM_ROWS-1][0] = temp;
            }

            else if(temp[BOTTOM]==col[SIDE_COLOUR]&&temp[RIGHT]==col[SIDE_COLOUR])
            {
                final_vector[NUM_ROWS-1][NUM_ROWS-1] = temp;
            }
            

            else if(temp[TOP] == col[SIDE_COLOUR])
            {
                top.push_back(temp);
            }

            else if(temp[LEFT] == col[SIDE_COLOUR])
            {
                left.push_back(temp);
            }

            else if(temp[BOTTOM] == col[SIDE_COLOUR])
            {
                bottom.push_back(temp);
            }

            else if(temp[RIGHT] == col[SIDE_COLOUR])
            {
                right.push_back(temp);
            }

            else
            {
                middle.push_back(temp);
            }
            // top.pb(s);
        }

        // cout << "Printing Top...\n";
        // rep(i,top.size())
        // {
        //     rep(k,4)
        //     {
        //         cout << top[i][k] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "Print Top END\n";

        sort_col(final_vector,0,0,middle,left,right,top,bottom);
        sort_col(final_vector,1,0,middle,left,right,top,bottom);
        sort_col(final_vector,2,0,middle,left,right,top,bottom);
        sort_col(final_vector,3,0,middle,left,right,top,bottom);

        rep(i,NUM_ROWS)
        {
            rep(j,NUM_ROWS)
            {
                cout << '(';
                if(final_vector[i][j].size()!=0){
                rep(k,4)
                {
                    cout << col_to_int[final_vector[i][j][k]];
                    if(k!=3)
                    {
                        cout << ',';
                    }
                }}
                else{
                    cout << "None";
                }
                cout << ')';
                if (j!=NUM_ROWS-1)
                {
                    cout << ';';
                }
            }
            cout << '\n';
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


