// Recursion = when a function calls itself untill a specified condition is met

// stack overflow = function calls wait in the stack after calling , this keeps on going , all these fxn calls will be waiting in memory 

// segmentation fault = stack overflow ( when there is numerous fxn calls waiting due to recursion )

// base condition = the condition to stop recursion calls 

// return statement inside a function will terminate the function then and there

#include<bits/stdc++.h>
using namespace std;
/*

Problems : 
1.print name N times 
2.print linearly from 1 to N
3.print from N to 1
4.print linearly from 1 to N (backtracking)
5.print from N to 1 (backtracking)

*/


//print from 1 to N (without using F(i+n) recursion call)

// so its obvious we'll use F(i-1,n)

/*
F(i,n)
{   
    if(i<1)
    {   
        return;
    }
    
    f(i-1,n);
    print(i);

    // by doing this you're making sure tht the last guy is executed 1st (i.e. in reverse way) 
}
main()
{   
    input(n=3);
    F(N,N); //(3,3)
}

*/
/*


Sum of 1st N numbers using recursion

// parameterized way

f(i,sum)
{   
    if(i<1)
    {   
        print(sum)
        return
    }
    f(i-1,sum+i)
} 
    main()
    {   
        input n
        f(n,0)

    }

    f(3,0) - f(2,3) - f(1,5) - f(0,6) -> i < 1 -> prints sum = 6 


// functional recursion - fxn will return the answer , not print it 

f(n) 
{
    if(n==0) return 0;
    else
    {    
        return n + f(n-1);
    }
    main()
    {   
        input 3
        cout << f(3);
    }
}
*/
/*


Reverse an array(using 2 pointers)

f(l,r)
{
    if(l>=r) return;
    swap(a[l],a[r])
    f(l+1,r-1);
}
main()
{
    int arr[n] , take input of arr
    f(0,n-1);
    cout << arr;
}
*/

/*


Using single pointer 

f(i)
{
    if(i>=n/2) return;
    swap(a[i],a[n-i-1])
    f(i+1);
}
main()
{
    int arr[n] , take input of arr
    f(0)
    cout << arr 

}

*/
void reverse(int i , int arr[] , int n)
{
    if(i >= n/2) return;
    swap(arr[i] , arr[n-i-1]);
    reverse(i+1 , arr , n);

}
int main() 
{   
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    reverse(0,arr,n);
    for(int i = 0 ; i < n; i++) cout << arr[i] << " " ; 
    return 0 ;
	
}

// palindrome

bool palindrome(int i ,  string &s)
{
    if(i >= s.size() / 2) return true;
    if(s[i] != s[s.size()-i-1]) return false;
    return palindrome(i+1 , s);
}
int main()
{
    string s ; cin >> s ;
    cout << palindrome(0,s);
    return 0;
}













 
 




