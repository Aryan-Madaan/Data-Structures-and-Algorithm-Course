#include <bits/stdc++.h>
using namespace std;
 
bool own(int a, int b)
{
    int temp1 = a, temp2 = b;
    int temp3 = a, temp4 = b;
    int ca = 0, cb = 0;
    while (temp1 > 0)
    {
        ca++;
        temp1 /= 10;
    }
    while (temp2 > 0)
    {
        cb++;
        temp2 /= 10;
    }
    for (int i = 0; i < ca; i++)
        temp4 *= 10;
    for (int i = 0; i < cb; i++)
        temp3 *= 10;
    temp3 = temp3 + b;
    temp4 = temp4 + a;
    return temp3 > temp4;
}
 
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),own);
    for(int i=0;i<n;i++)
    cout<<arr[i];
}