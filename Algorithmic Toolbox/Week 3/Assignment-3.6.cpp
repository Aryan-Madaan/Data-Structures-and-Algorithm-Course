#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    int count = 0,curr=1;
    while(curr<=n)
    {
        n-=curr;
        count++;
        curr++;
    }
    cout << count<<"\n";
    for(int i =0;i<count-1;i++)
    {
        cout << i+1 <<" ";
    }
    cout << count + n;
    return 0;
}