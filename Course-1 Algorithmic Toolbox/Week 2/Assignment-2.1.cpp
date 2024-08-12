#include <iostream>

using namespace std;

long long cal_fib(int n)
{
    long long a[2][2] = {{0,1},{1,1}},res[2][2]={{0,0},{0,0}},ans[2][2]={{1,0},{0,1}};
    if(n<=1)
    return n;
    else
    {
        while(n)
        {
            if(n%2==1)
            {
            res[0][0] = ans[0][0]*a[0][0] + ans[0][1]*a[1][0];
            res[0][1] = ans[0][0]*a[0][1] + ans[0][1]*a[1][1];
            res[1][0] = ans[1][0]*a[0][0] + ans[1][1]*a[1][0];
            res[1][1] = ans[1][0]*a[0][1] + ans[1][1]*a[1][1];
            ans[0][0] = res[0][0];
            ans[0][1] = res[0][1];
            ans[1][0] = res[1][0];
            ans[1][1] = res[1][1];
            }
            res[0][0] = a[0][0]*a[0][0] + a[0][1]*a[1][0];
            res[0][1] = a[0][0]*a[0][1] + a[0][1]*a[1][1];
            res[1][0] = a[1][0]*a[0][0] + a[1][1]*a[1][0];
            res[1][1] = a[1][0]*a[0][1] + a[1][1]*a[1][1];
            a[0][0] = res[0][0];
            a[0][1] = res[0][1];
            a[1][0] = res[1][0];
            a[1][1] = res[1][1];
            n/=2;
        }
    }
    return ans[0][1];
}

int main(){
    long long n;
    cin >> n;
    cout << cal_fib(n);
    return 0;
}