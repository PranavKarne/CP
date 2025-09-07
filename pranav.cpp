#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int k , x;
        cin >> k >> x;

        for(long long s = 1 ; s < 1000 ; s++)
        {
            long long y = s;
            for(long long  i = 0 ; i < k ; i++)
            {
                if(y%2==0) y = y / 2;
                else y = 3*y +1;
            }

            if(y==x)
            {
                cout << s << endl;
                break;
            }
        
        }
        
    }

    
}
