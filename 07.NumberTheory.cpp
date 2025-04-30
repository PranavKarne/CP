/*
Modular Arithmetic

M = 1e9 + 7

Significance of 1e9 + 7 =  very close to int max value 
In Multiplicative inverse cannot be calculated for all numbers , 1e9 + 7 is prime number actually so  multiplicative inverse can be calculated easily.

In A % M , the result of this operation is always lesser than M 

(a+b) % M = ((a % M) + (b % M)) % M
(a*b) % M = ((a % M) * (b % M)) % M
(a-b) % M = ((a % M) - (b % M) + M) % M 
(a/b) % M = ((a % M) * (b^-1 % M)) % M

--> In the above equation, we add M to ensure that the result is non-negative. 
This is important because the modulo operation can yield negative results in some programming languages when the dividend is negative.
By adding M, we ensure that the result falls within the range of 0 to M-1.

*/


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n ;
    long long fact = 1;
    for(int i = 2 ; i <=n ;i++){
        fact = fact * i ;

    }

    cout << fact << endl;


     // when we take input as 21 , it gives -ve output , it overflows , long long also cannot store fact of 21.
     // qs when answer is very big , we use modulo 




/*
Problem : 
Given a number N. Print its factorial.
Constraints
1 <= N <= 100

print answer modulo M 
where M = 1e9 + 7;

*/
int n; cin >> n ;
    long long fact = 1;
    int M = 1e9 + 7;
    for(int i = 2 ; i <=n ;i++){
        fact = (fact * i) % M;
    }

    cout << fact << endl;
}



/*

GCD = greatest common divisor (hcf) , maximum divisor value for 2 numbers

4,12 --> 4
12,18 --> 6

gcd and lcm calculation in school

4 - 2^2 * 3^0
12 - 2^2 * 3^1

extract the minimum of the powers for gcd -> 2^2 * 3^0 -> 4

LCM of 4 , 12 : 
we extract the maximum of the powers for lcm 
2^2 * 3^1  -> 12 


GCD of 12,18

12 - 2^2 * 3
18 - 2 * 3^2

GCD -> 2 * 3 -> 6
LCM -> 2^2 * 3^2 -> 36

relationship b/w gcd and lcm

LCM(a,b) = a*b / GCD(a,b)

Euclid's Algorithm :
(long division method)
*/

int gcd(int a , int b){
    if(a%b==0) return b;
    // or if(b==0) return a;
    return gcd(b,a%b);

    //TC = O(log n) // depends on numbers , its generalized TC
    //gcd(a,b) = gcd(b,a%b) // only if b is not zero , if b is 0 then a%b will become not defined.

    // to find the simplest fraction form of a/b 
    // a/b = a/gcd(a,b) / b/gcd(a,b)
     

}

int main(){

    cout << gcd(12,18) << endl;
    cout << gcd(18,12) << endl;
    //doesnt matter if the bigger number if 1st or not , as in long division method
    //the reminder(a%b)(non-zero) becomes the divisor and the divisor(previous)(b) becomes the dividend 


    //in-built fxn 
    cout << __gcd(20,10) << endl;

}

/*
Binary Exponentiation =  power fxn algo (a^b)


 we can use inbuilt pow() fxn but it has precision errors
 the pow() returns in double data type
 double is not accurate , not exact sometimes

*/
// Calculating power in O(N)

const int M = 1e9 + 7;
int a = 2 ;
int b = 3;
int ans = 1;
/* for(int i = 0 ;i < b;i++){
    ans *= a; 
    ans %= M;
}
*/






