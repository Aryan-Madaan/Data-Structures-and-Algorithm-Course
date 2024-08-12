#include <iostream>
#define mod 10

using namespace std;

long long cal_fib(long long n)
{
    long long a[2][2] = {{0,1},{1,1}},res[2][2]={{0,0},{0,0}},ans[2][2]={{1,0},{0,1}};
    if(n<=1)
    return n%mod;
    else
    {
        n+=2;
        while(n)
        {
            if(n%2==1)
            {
                res[0][0] = (ans[0][0]*a[0][0])%mod + (ans[0][1]*a[1][0])%mod;
                res[0][1] = (ans[0][0]*a[0][1])%mod + (ans[0][1]*a[1][1])%mod;
                res[1][0] = (ans[1][0]*a[0][0])%mod + (ans[1][1]*a[1][0])%mod;
                res[1][1] = (ans[1][0]*a[0][1])%mod + (ans[1][1]*a[1][1])%mod;
                ans[0][0] = res[0][0];
                ans[0][1] = res[0][1];
                ans[1][0] = res[1][0];
                ans[1][1] = res[1][1];
            }
            res[0][0] = (a[0][0]*a[0][0])%mod + (a[0][1]*a[1][0])%mod;
            res[0][1] = (a[0][0]*a[0][1])%mod + (a[0][1]*a[1][1])%mod;
            res[1][0] = (a[1][0]*a[0][0])%mod + (a[1][1]*a[1][0])%mod;
            res[1][1] = (a[1][0]*a[0][1])%mod + (a[1][1]*a[1][1])%mod;
            a[0][0] = res[0][0];
            a[0][1] = res[0][1];
            a[1][0] = res[1][0];
            a[1][1] = res[1][1];
            n/=2;
        }
    }
    // for(int i =0;i<2;i++)
    // {
    //     for(int j = 0;j<2;j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return (ans[0][1]-1)%mod;
}

int main(){
    // while(1){
    long long n;
    cin >> n;
    cout << cal_fib(n) << endl;
    // }
    return 0;
}