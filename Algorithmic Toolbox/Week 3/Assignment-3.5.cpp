#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< pair<int,int> > v(n);
    vector<int> ans,ne;
    for(int i =0;i<n;i++)
    {
        cin >> v[i].second >> v[i].first;
        // v[i].first = v[i].second - v[i].first;
    }
    sort(v.begin(),v.end());
        for(int i =0;i<n;i++)
        {
            bool chk = 0;
            for(int k=0;k<ans.size();k++)
            {
                if(v[i].first>=ans[k]&&v[i].second<=ans[k])
                {
                    chk = 1;
                    break;
                }
            }
            if(!chk){
                ans.push_back(v[i].first);
            }
        }
    cout << ans.size() <<"\n";
    for(int i =0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}