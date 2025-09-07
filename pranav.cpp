#include<bits/stdc++.h>
using namespace std;

int digitsum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        int ld = n % 10;
        sum += ld;
        n = n / 10; 
    }
    return sum;
}


int main()
{
    int n; cin >> n;
    int target = 2 * digitsum(n);

    int x = n + 1;
    while(true)
    {
        if(digitsum(x) == target)
        {
            cout << x << endl;
            break;
        }
        x++;
        

    }
    
    
}
