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


// Multiple Recursion Calls - function is called multiple times

//fibonacci

// for harder problems we will use recursive trees

// tc - O(2^N) (approx) - exponential in nature - for fibonacci


/*

Print all Subsequences 


subsequences - a contiguous/non-contiguos sequence which follows the order 
[3,1,2] -> [1,2] , [3,1] , [3,2] , []  are subsequences , they shld follow order of array 
but 3,2,1 is not subsequences

subarray - just contiguous , a subarray can be a subsequence

take and not take
for every index we have 2 options , to take or to not take

Ex:
[3,1,2]

[3,2] - take , not take , take 
[1,2] - not take , take , take
[3,1]- take , take , not take 
[] - not take , not take , not take 

this structure/pattern is very important , used everywhere , remember it forever : 


arr - [3,1,2] (0,1,2 -  indexes)



f(index,[])
{ 
    if(index >= n )
    {   
        print(arr)
        return;
    }

    arr.add(arr[i]);
    f(index + 1,[]) ;       (take)

    arr.remove(arr[i]) ;
    f(index+1 ,[])          (not take)

}
int main()
{   

    arr - [3,1,2]
    f(0,[]);
}

*/

void subsequences(int index , vector<int>&v , int arr[] , int n)
{   

    if(index == n)
    {   
        for(auto &it : v) cout << it << " ";
        cout << endl;
        return;
         
    }
    
    v.push_back(arr[index]);
    subsequences(index+1,v,arr,n);

    v.pop_back();
    subsequences(index+1,v,arr,n);

}
int main()
{
    int arr[3] = {3,1,2};
    int n = 3 ; 
    vector<int>v;
    subsequences(0,v,arr,n);
    return 0;
 
    // TC - O(2^N * N) 
    // SC - O(N)

}


// Printing Subsequences whose Sum is K


void subsequences(int index , vector<int>&v , int arr[] , int n , int k , int sum)
{
    if(index == n)
    {  
        if(sum == k)
        {
            for(auto &it : v) cout << it << " ";
            cout << endl;
        }
        return;
    }
 
    v.push_back(arr[index]);
    sum += arr[index];
    subsequences(index+1,v,arr,n,k,sum);
    v.pop_back();
    sum -= arr[index];
    subsequences(index+1,v,arr,n,k,sum);

}
int main()
{
    int arr[3] = {1,2,1};
    int n = 3 ; 
    int k = 2 ;
    int sum = 0;
    vector<int>v;
    subsequences(0,v,arr,n,k,0);
    return 0;
}


//Print Only 1 Subsequence whose Sum is K

// Method 1 : Not Recommended Actually , here we use global Variables

// When a subsequence with sum equal to k is found, the condition if (sum == k && flag == false) becomes true. 
// So, the code prints this first matching subsequence and sets flag = true.
// After the first match, flag becomes true, so all future matches are ignored
// even if their sum equals k, because flag == false is now false.



bool flag = false;
void subsequences(int index , vector<int>&v , int arr[] , int n , int k , int sum)
{
    if(index == n)
    {  
        if(sum == k && flag == false)
        {   
            flag = true;
            for(auto &it : v) cout << it << " ";
            cout << endl;
        }
        return;
    }

    v.push_back(arr[index]);
    sum += arr[index];
    subsequences(index+1,v,arr,n,k,sum);
    v.pop_back();
    sum -= arr[index];
    subsequences(index+1,v,arr,n,k,sum);

}
int main()
{
    int arr[3] = {1,2,1};
    int n = 3 ; 
    int k = 2 ;
    int sum = 0;
    vector<int>v;
    subsequences(0,v,arr,n,k,0);
    return 0;

    

}

// this above method will work but it is not preferred 

// Method 2 : the functional Method

// the technique to always print only 1 answer   
// in the function  
// in the base condition if the condition is satisfied , we shld return a true , if the condition is not satisfied then return a false 
// now in the function call , will be inside if() like -->  " if(fxn()== true) return ; "  there is no need to go beyond and do another
// function call or else at the end return false




bool subsequences1(int index , vector<int>&v , int arr[] , int n , int k , int sum)
{
    if(index == n)
    {  
        if(sum == k)
        {
            for(auto &it : v) cout << it << " ";
            cout << endl;
            return true;
        }
        // condition is not satisfied 
        else return false;
    }

    v.push_back(arr[index]);
    sum += arr[index];

    if(subsequences1(index+1,v,arr,n,k,sum) == true) return true;
    
    v.pop_back();
    sum -= arr[index];

    if(subsequences1(index+1,v,arr,n,k,sum) == true) return true;

    return false;
    

}
int main()
{
    int arr[4] = {1,2,2,4};
    int n = 3 ; 
    int k = 4 ;
    int sum = 0;
    vector<int>v;
    subsequences(0,v,arr,n,k,0);
    return 0;

}
















































 
 




