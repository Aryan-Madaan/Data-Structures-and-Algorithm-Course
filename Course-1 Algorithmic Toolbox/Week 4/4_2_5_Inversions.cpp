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

void swap(vector <int> & arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int merge(vector<int> & final, vector<int> & a, vector<int> & b)
{
    int ptr1 = 0,ptr2 = 0;
    int inversions = 0;
    // cout << "Starting Merge\n";
    // cout << a.size() << " " << b.size() << " " << final.size() << "\n";
    // rep(i,a.size()) cout << a[i] << " ";
    // cout << "\n";
    // rep(i,b.size()) cout << b[i] << " ";
    // cout << "\n\n";
    bool flag11 = false;
    while (flag11 == false)
    {
        if (ptr1>=a.size() && ptr2>=b.size()) {
            flag11 = true;
            break;
        }
        if (ptr1>=a.size())
        {
            final[ptr1+ptr2] = b[ptr2];
            ptr2++;
        }
        else if (ptr2 >= b.size())
        {
            final[ptr1+ptr2] = a[ptr1];
            ptr1++;
        }
        else if(a[ptr1] <= b[ptr2])
        {
            final[ptr1+ptr2] = a[ptr1];
            ptr1++;
        }
        else
        {
            inversions += a.size() - ptr1;
            final[ptr1+ptr2] = b[ptr2];
            ptr2++;
        }
    }
    // rep(i,final.size()) cout << final[i] << " ";
    // cout << "\n";
    return inversions;
}

int mergesort(vector<int> &arr)
{
    if (arr.size()==1)
    return 0;
    // if (arr.size()==2)
    // {
    //     // if(arr[0]>arr[1])
    //     // {
    //     //     swap(arr,0,1);
    //     // }
    //     return merge(arr,arr[0],arr[]);
    // }
    int mid = (arr.size()/2);
    vector<int> v1,v2;
    // vector<int> final(arr.size(),0);
    // v1.insert(v1.begin(), 
    //                 arr.begin(), arr.begin()+mid);
    rep(i,mid)
    {
        v1.push_back(arr[i]);
    }
    for(int i =mid;i<arr.size();i++)
    {
        v2.push_back(arr[i]);
    }
    // v2.insert(v2.begin(),arr.begin()+mid, arr.end());
    // rep(i,v1.size()) cout << v1[i] << " ";
    // cout << "\n";
    // rep(i,v2.size()) cout << v2[i] << " ";
    // cout << "\n\n\n";
    int ans1 = mergesort(v1);
    int ans2 = mergesort(v2);
    int ans3 = merge(arr,v1,v2);
    // rep(i,arr.size()) cout << arr[i] << " ";
    // cout << "ggg\n\n\n";
    return ans3+ans1+ans2;
}

void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> arr(n,0);
        rep(i,n) cin >> arr[i];
        cout << mergesort(arr);
        // cout << "\n";
        // rep(i,n) cout << arr[i] << " ";
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


