#include<iostream>
using namespace std;

int main(){
    int d,m,n;
    cin >> d >> m >> n;
    int arr[n+1];
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    arr[n] = d;
    bool f = 1;
    int count = 0,curr = m;
    for(int i =0;i<n&&f;i++)
    {
        if(curr< arr[i+1])
        {
            curr= arr[i]+m;
            // cout << curr << " " << arr[i] << " " << i <<endl;
            if(curr<arr[i+1])
            {
                f = 0;
                break;
            }
            count++;
        }
    }
    if(f)
    {
        cout << count;
    }
    else
    {
        cout << -1;
    }
    return 0;
}