#include<bits/stdc++.h>
using namespace std;

const int M =  1e9 + 7 ;

/*

Precomputation in Competitive Programming (CP) refers to calculating and storing results before
the actual queries or computations take place
to optimize performance during execution.


1. Given T test cases and in each test case a number N . 
print its factorial for each test case % M
where M = 10^9 + 7 

contraints
1 <= T <= 10^5
1 <= N <= 10^5



*/

//normal approach , here same numbers can be repeatedly asked by user

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ; cin >> n;
        long long fact = 1;
        for(int i = 2 ; i <= n ; i++){
            fact = (fact*i) % M;  
        }
        cout << fact << endl;
    }


    // O(T*N) --> O(N^2) --> 10^10 
    // if timelimit is 1sec in the qs  then it will give error 
    //in 1sec we have 10^8 operations generally




    // we will precompute all the values from 0 to 10^5 

    const int N = 1e5 + 10;  // we take a value just above N 
    long long fact[N];

    //int main(){
        fact[0] = fact[1] = 1;
        for(int i = 2 ; i < N; i++){
            fact[i] = i * fact[i-1] % M ;
        }

        int t;
        cin >> t;
        while(t--){
            int n ; cin >> n;
            cout << fact[n] << endl;

        // }

        //O(N) + O(T) = O(N)

}
 

/*

2.Given array a of N integers. Given Q queries
and in each query given a number X
print count of that number in array.

Constraints
1 <= N <= 10^5
1 <= a[i] <= 10^7 

1 <= Q <= 10^5

*/


// normal approach

int n ; cin >> n ;
int a[n];
for(int i = 0 ; i < n ; i++){
    cin >> a[i];
}
int q; cin >> q;
while(q--){
    int x; cin >> x;
    int ct = 0;
    for(int i=0;i<n;i++){
        if(a[i]==x) ct++;
    }

cout << ct << endl;
}

// O(N) + O(Q*N) --> O(N^2 or Q^N)


/*


Hashing

Hash array --> the ith index will store the 
count of tht "i" in the array

max array size is 10^7 

*/


const int N = 1e7 + 10;
int hsh[N];

// global arrays are initialized to zero

int n ; cin >> n ;
int a[n];
for(int i = 0 ; i < n ; i++)
{
    cin >> a[i];
    hsh[a[i]]++;  
}
int q; cin >> q;
while(q--)
{
    int x; cin >> x;
    cout << hsh[x] << endl;
}

// O(N) + O(Q) = O(N)
// N & Q are of similar size(1e7)

/*

Prefix sum
 
Given array a of N integers. 
Given Q queries and in each query
given L and R print sum of array elements 
from index L to R(L, R included)

Constraints

1 <= N <= 10^5
1 <= a[i] <= 10^9
1 <= Q <= 10^5
1 < L, R <= N


*/



// Normal Approach

const int N = 1e5 + 10;
int a[N];

// try to use 1-based array in prefix sum and L,R type problems.
// no problem with L-- & R-- as L,R are given in 1-based itself

int n ; cin >> n ; 
for(int i = 1 ; i <= n ; i++)
{
    cin >> a[i];
    cout << a[i];
}

int q ; cin >> q;
while(q--)
{
    int l,r;
    cin >> l >> r;
    long long sum = 0 ;
    for(int i = l ; i<=r;i++)
    {
        sum += a[i];
    }

    cout << sum << endl;
}

// O(N) + O(Q*N)= 10^10;


/*
Prefix sum 

3 6 2 8 9 2 --> 3 9 11 19 28 30 

the ith index will store the sum of all the elements  from 1st index  to ith index 

*/

int pf[N];
int n ; cin >> n ; 
for(int i = 1 ; i <= n ; i++)
{
    cin >> a[i];
    pf[i] = pf[i-1] + a[i];
    // use 1-based indexing for prefix sum

}

int q ; cin >> q;
while(q--)
{
    int l,r;
    cin >> l >> r;
    cout << pf[r] - pf[l-1] << endl;    
    // pf[r] gives the sum from 1 to r
    // pf[l-1] gives the sum from 1 to l-1

}

//O(N) + O(Q) = 10^5  


/*


Prefix sum in 2D arrays 

Given 2d array a of N*N integers.
Given Q queries and in each query given a, b, c and d 
print sum of square represented by (a,b) as top left point
and (c,d) as top bottom right point

Constraints

1 <= N <= 10^3
1 < a[i][j] <= 10^9
1 <= Q <= 10^5
1 < a, b,c, d <= N

*/

const int N = 1e3 + 10;
int arr[N][N];
//int main(){
    int n ; cin >> n ; 
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1 ; j <=n ; j++){
            cin >> arr[i][j];
        }
    }
    int q ; cin >> q ;
    while(q--){
        int a , b , c,d ;
        cin >> a >> b >> c >> d;
        long long sum = 0;
        for(int i = a ; i <= c ;i++){
            for(int j = b ; j <= d; j++ ){
                sum += arr[i][j];
            }
        }
        cout << sum << endl;
    }
//}

// 2D array prefix sum

 












  







