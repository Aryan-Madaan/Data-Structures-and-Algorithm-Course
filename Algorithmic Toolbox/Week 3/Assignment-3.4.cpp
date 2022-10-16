#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long price[n],click[n];
    for(int i =0;i<n;i++)
    {
        cin >> price[i];
    }
    for(int i =0;i<n;i++)
    {
        cin >> click[i];
    }
    sort(price,price+n);
    sort(click,click+n);
    long val = 0;
    for(int i = 0;i<n;i++)
    {
        val += price[i]*click[i];
    }
    cout << val;
    return 0;
}