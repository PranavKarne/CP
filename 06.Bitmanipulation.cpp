/* 

1. Binary Number Conversion - 1's and 2's compliment 

base 10 - number is in decimal format

base 2 - number is in binary format

7(10) = 111(2)

*/

#include <bits/stdc++.h>
using namespace std;



// this function will convert decimal to binary 
string dec2bin(int n)
{
    string res = " ";
    while(n!=0)
    {
        if(n%2==1) res += "1";
        else res += "0";
        n = n / 2 ;
    }
    reverse(res.begin(),res.end());
    return res;
}
// O(log n base 2) - TC & SC 



// this function will convert binary to decimal

int bin2dec(string x)
{
    int len = x.length();
    int pow2 = 1;
    int num = 0;
    for(int i = len - 1 ; i >= 0 ; i--)
    {
        if(x[i] == '1')
        {   
            num = num + pow2;
        }
        pow2 = pow2 * 2;
    }

    return num;
}

// O(len) - TC
// O(1) - SC

/* 

1's Compliment = flip all the bits(toggle all of them)
2's compliment = add a plus one to the 1's compliment


AND operator - all true means true , one false means false

13 & 7 = 5
1 1 0 1 
0 1 1 1 
= 
0 1 0 1 - 5


OR - one true means true , all false means false

13 | 7 
1 1 0 1 
0 1 1 1 
= 
1 1 1 1 - 15


XOR - count of 1's is odd = 1 
    - count of 1's is even = 0

13 ^ 7

1 1 0 1
0 1 1 1
=
1 0 1 0 - 10 

Right Shift Operator (>>)

13 >> 1

13 - 1 1 0 1

13 >> 1 -> 1 1 0 = 6 

the righmost 1 is gone

13 >> 2 
1 1 0 1 -> 1 1 = 3 

13 >> 4
1 1 0 1 -> 0 = 0

x >> k means x / 2^k

13/2^1 = 6
13/2^2 = 3
13/2^4 = 0 


for -ve numbers 
the left most bit is for the sign 

0 = +ve
1 = -ve
to store -ve numbers : 

the computer converts it to 2's Compliment
for 2's compliment
1. do 1's compliment
2. add a +1 to 1's compliment

the leftmost bit is "1" means it is -ve num

INT_MIN = -2^31
INT_MAX = 2^31


Left Shift (<<)

the leftmost bit will be removed

num << k = num * 2^k 

13 << 1 = 13 * 2^1 = 26 

there can be overflow in leftshift 



NOT operator(~)


1.flip 
2.checks if it is a -ve , if yes then
it stores 2's compliment or else it stops

for -ve numbers , the leftmost bit is "1"
for -ve number operations always remember to convert -ve number to its 2 compliment 
computer always stores its 2 compliment


*/

/* 

Swap 2 numbers using XOR

XOR - count of 1's is odd = 1 
    - count of 1's is even = 0

    
*/

int a , b ;

int a = a ^ b ;
int b = a ^ b ;
int a = a ^ b ;


/* 

check if ith bit is set or not

(0 based indexing)

N = 13 -> 1 1 0 1 in binary
i = 2

1 << 2 = 1 0 0 

1 << 1 = 1 0 

using the left shift operator 

if((n & (1<<i))!= 0) 

using right shift operator

if(((n>>i)&1)!= 0) 

tc = O(1)

*/


/*  


set the ith bit 

N = 9 , i = 2 

9 = 1 0 0 1     [O based indexing from right to left]

N | (1 << i)


toggle the ith bit
















*/










