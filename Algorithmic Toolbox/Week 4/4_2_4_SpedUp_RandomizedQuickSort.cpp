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

pair<int,int> partition(vector <int> & arr,int left,int right)
{
    int i = left;
    int m = left;
    int k = left;
    for (int j = left+1;j<=right;j++)
    {
        if(arr[j]<arr[left])
        {
            i++;
            swap(arr,i,j);
            m++;
            if(m!=i)
            swap(arr,m,j);
            k++;
        }
        else if(arr[j]==arr[left])
        {
            m++;
            swap(arr,m,j);
            k++;
        }
        else
        {
            k++;
        }
        // cout << "j = "<<j << "\n\n";
        // cout << "i = "<<i << "\n";
        // cout << "m = "<<m << "\n";
        // cout << "k = "<<k << "\n";
        // for(int start = left;start<=right;start++)
        // cout << arr[start] << " ";
        // cout <<"\n";
    }
    swap(arr,left,i);
    i--;
    // cout << "i = "<<i << "\n";
    // cout << "m = "<<m << "\n";
    // cout << "k = "<<k << "\n";
    // for(int start = left;start<=right;start++)
    // cout << arr[start] << " ";
    // cout << "\n";
    return mp(i,m);
}

void QuickSort(vector <int> & arr, int left, int right)
{
    if (left >= right)
    return;
    int pivot = left + rand() % (right-left);
    swap(arr,pivot,left);
    // for(int start = left;start<=right;start++)
    // cout << arr[start] << " ";
    pair<int,int> mypp = partition(arr,left,right);
    QuickSort(arr,left,mypp.first);
    QuickSort(arr,mypp.second+1,right);
}


void solve()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n,0);
        rep(i,n) cin >> arr[i];
        QuickSort(arr,0,n-1);
        rep(i,n) cout << arr[i] << " ";
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


