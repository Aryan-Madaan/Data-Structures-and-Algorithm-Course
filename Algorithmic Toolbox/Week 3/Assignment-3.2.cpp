#include<iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout.precision(numeric_limits<double>::max_digits10);
       cout << setprecision(15) << fixed;
    int n;
    double w,value = 0;
    cin >> n >> w;
    vector< pair<double,double> > v(n);
    for(int i =0;i<n;i++)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first = v[i].first/v[i].second;
    }
    sort(v.begin(),v.end());
    for(int i =n-1;i>=0;i--)
    {
        value += (min(w,v[i].second)*v[i].first);
        w -= min(w,v[i].second);
    }
    cout << value;
    return 0;
}