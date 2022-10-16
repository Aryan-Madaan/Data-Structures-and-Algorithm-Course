#include <iostream>

using namespace std;

int main()
{
    int mon;
    cin >> mon;
    cout <<  (  (mon/10) + ((mon%10)/5)  + mon%5);
    return 0;
}