/*

3rd oct


1.. Best Time to Buy and Sell Stock - minprice , maxprofit 
2.. Strobogrammatic Number - 0,1,3,6,9
3.. minimum product subset of an array - bitmasking 
4.. Class room attendance tracker - simple unor_map problem
5.. encrypted staircase problem 
6.. lemonade change
7.. find smallest common element in all rows - unor_map 
8.. roman to integer - unor_map and one condition 



*/ 

// 1.Best Time to Buy and Sell Stock


You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104



class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int maxprofit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] > prices[i]) {
                    maxprofit = max(prices[j] - prices[i], maxprofit);
                }
            }
        }
        return maxprofit;
    }
};

// or 

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {   
        int max_profit = 0 ;
        int n = prices.size();
        int min_price = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            min_price = min(min_price,prices[i]);
            max_profit = max(max_profit , prices[i] - min_price);
        }
        return max_profit;

        
    }
};


// 2. strobogrammatic number 




#include <bits/stdc++.h>
using namespace std;

bool isStrobogrammatic(string &num) {
    string rotated = "";
    for (int i = num.size() - 1; i >= 0; i--) {
        char c = num[i];
        if (c == '0' || c == '1' || c == '8') 
            rotated += c;
        else if (c == '6') 
            rotated += '9';
        else if (c == '9') 
            rotated += '6';
        else 
            return false; // invalid digit
    }
    return rotated == num;
}

int main() 
{
    string num; cin >> num;
    cout << boolalpha; // print true/false instead of 1/0
    
    cout << isStrobogrammatic(num) << endl;
    
}

// 3. minimum product subset of an array 



Problem: Minimum Product Subset of an Array
Given an array a, you have to find the minimum product possible with a non-empty subset of elements present in the array. The minimum product can be a single element also.

Examples
Example 1

Input: a[] = { -1, -1, -2, 4, 3 }

Output: -24

Explanation: The minimum product will be (-2 * -1 * -1 * 4 * 3) = -24.

approach : generate all subsets and track the minimum product 


how to generate subsets using bitmasking

for(int mask = 0 ; mask < (1 << n ) ; mask++)
{
    vector<int>subset;
    for(int i = 0 ; i < n ; i++)
    {
        if(mask & (1 << i))
        {
            subset.push_back(arr[i]);
        }
    }
}


code :
    vector<long long >arr;
    long long x;
    while(cin >> x)
    {
        arr.push_back(x);
    }
    long long n = arr.size();
    long long minProduct = LLONG_MAX;

    for(long long mask = 1 ; mask < (1 << n) ; mask++)
    {
        long long product = 1;
        for(long long  i = 0; i < n ; i++)
        {
            if(mask & (1 << i))
            {
                product *= arr[i];
            }
        }
        minProduct = min(minProduct , product);
    }
    cout << minProduct << endl;
    

4. class room attendence tracker

Problem: Classroom Attendance Tracker
A teacher keeps track of student names for each day of class. Some students attend multiple days, so their names appear multiple times in the attendance list.

Your task is to count how many times each student attended class and display the results in alphabetical order of names.

Input Format
First line: an integer n - number of attendance entries (1 ≤ n ≤ 1000).

Second line: n space-separated strings - names of students.

Output Format
For each unique student, print: StudentName:count

Names should be printed in alphabetical order.

Examples
Example 1
Input:

6
Alice Bob Alice Charlie Bob Alice
Output:

Alice:3
Bob:2
Charlie:1
Example 2
Input:

5
David Eve David Eve Frank
Output:

David:2
Eve:2
Frank:1


code :

    int n ; cin >> n;
    map<string,int>pranav;
    for(int i = 0 ; i < n ;  i++)
    {
        string name;
        cin >> name;
        pranav[name]++;
        
    }
    for(auto &it : pranav)
    {
        cout << it.first << " " << it.second << endl;
    }



7. find smallest common element in all rows

Of course! Here's the text from the problem statement.

Smallest Common Element in All_Rows BinarySearch
Problem 1

Your task is to find the smallest common element in all rows. If there is no common element, return -1.

You are given an n x m matrix mat where each row is sorted in non-decreasing order.

Input Format:
Line-1: Two integers n and m, representing the number of rows and columns, respectively.

Line-2: The next n lines contain m space-separated integers each, representing the elements of the matrix. Each row of the matrix is sorted in non-decreasing order.

Output Format:
Line-1: Print a single integer, the smallest common element in all rows. If no common element exists, print -1.

Constraints:
1≤n,m≤500

1≤mat[i][j]≤10 
4
 

Each row is sorted in non-decreasing order.

Sample Input-1:
3 4
2 3 4
1 2 3 4
3 5 6 7
Sample Output-1:
3
Explanation: The number 3 is the smallest common element in all rows.

Sample Input-2:
2 3
1 2 3
4 5 6
Sample Output-2:
-1
Explanation: There is no common element in all rows, so the output is -1.


Sample Input 3
This case tests for a common element that appears at different positions in each row.

4 5
1 5 9 13 17
3 5 7 11 19
5 6 8 10 12
2 4 5 14 18
Sample Output 3
5
Explanation: The number 5 is the only element present in all four rows.

Sample Input 4
This test case has multiple common elements. The algorithm should find the smallest one.

3 7
4 8 12 16 20 24 28
6 12 18 24 30 36 42
3 6 9 12 15 18 24
Sample Output 4
12
Explanation: Both 12 and 24 are common to all rows. The correct output is the smallest common element, which is 12.

Sample Input 5
This example is a tricky case where no single element is present in all rows, even though some elements appear in most rows.

4 4
10 20 30 40
15 20 25 35
10 20 30 50
10 15 25 45
Sample Output 5
-1
Explanation: No single number appears in all four rows. For instance, 10 is missing from the second row and 20 is missing from the last row.

Sample Input 6
This tests a scenario with a single column.

5 1
7
7
7
7
7
Sample Output 6
7
Explanation: The only element, 7, is common across all rows.


code : 

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    unordered_map<int,int> freqmap;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            freqmap[matrix[i][j]]++;
        }
    }

    int result = INT_MAX;
    for(auto &it : freqmap) {
        if(it.second == n) {
            result = min(result, it.first);
        }
    }

    if(result == INT_MAX) 
        cout << -1 << endl;
    else 
        cout << result << endl;


it.first → the number from the matrix

it.second → how many rows it appeared in

it.second == n → the number is present in all rows

min(result, it.first) → keeps the smallest number among all common numbers


8. roman to integer 

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.


We have a map<char,int> that stores Roman → Integer mappings.

We loop through each character in the string.

Rule:

If the next Roman digit is bigger than the current one → subtract the current digit.

Otherwise → add it.

int romanToInt(string s) 
    {   

        map<char,int>pranav = {
            {'I',1} , {'V',5}, {'X',10} ,{'L',50} , {'C',100} , {'D',500} , {'M',1000}
        };


        int res = 0;
        for(int i = 0; i < s.size() ; i++)
        {
            if(i+1 < s.size() && pranav[s[i]] < pranav[s[i+1]])
            {
                res -= pranav[s[i]];
            }
            else res += pranav[s[i]];
        }

        return res;
        
    }

Dry Run Example 3: s = "MCMXCIV" (= 1994)

res = 0

i=0 → 'M'(1000), next='C'(100). 1000 < 100 ❌ → add → res=1000

i=1 → 'C'(100), next='M'(1000). 100 < 1000 ✅ → subtract → res=1000-100=900

i=2 → 'M'(1000), next='X'(10). 1000 < 10 ❌ → add → res=900+1000=1900

i=3 → 'X'(10), next='C'(100). 10 < 100 ✅ → subtract → res=1900-10=1890

i=4 → 'C'(100), next='I'(1). 100 < 1 ❌ → add → res=1890+100=1990

i=5 → 'I'(1), next='V'(5). 1 < 5 ✅ → subtract → res=1990-1=1989

i=6 → 'V'(5), no next → add → res=1989+5=1994

✅ Output: 1994


int romantoint(string &s)
{

    map<char,int>pk = {{'I',1},{'V',5},{'X',10},{'L',50},{'D',500},{'C',100},{'M',1000},};
    int res = 0;
    for(int i = 0; i < s.size() ; i++)
    {
        if(pk[s[i]] < pk[s[i+1]] && i+1 < s.size()) res -= pk[s[i]];
        else res += pk[s[i]];
    }
    return res;
}


6. lemonade change 

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

 

Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
 


bool lemonadeChange(vector<int>& bills)
    {
        int fives = 0;
        int tens = 0;
        int twenties = 0;
        int n = bills.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(bills[i] == 5) fives++;
            else if(bills[i] == 10)
            {
                if(fives)
                {
                    fives--;
                    tens++;
                }
                else return false;
            }
            else
            {
                if(tens && fives )
                {
                    tens--;
                    fives--;
                }
                else if(fives >= 3) fives -= 3;
                else return false;
            }
        }
        return true;
}



5. encrypted staircase problem - recursion 





int countWays(int n, int m) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ways = 0;
    for (int step = 1; step <= m; step++)
        ways += countWays(n - step, m);

    return ways;
}

int countways(int n , int m)
{
    if(n==0) return 1;
    if (n < 0) return 0;
    int ways = 0 ;
    for(int step = 1 ; step <= m ; step++)
    {
        ways += countWays(n - step , m);
    }
    return ways;
}

int countways(int n , int m)
{
    if(n == 0 ) return 1;
    if(n < 0) return 0;
    int ways = 0 ;
    for(int step = 1; step <= m ; step++)
    {
        ways += countways(n-step,m);
    }
    return ways;
}


/*
5th october

1. integer to roman 
2. reverse words in a string
3. Count Number of Homogenous Substrings
4. Minimum Cost to connect ropes
5. coin change
6. Store Questions with Answers in Insertion Order 
7. Print Matrix Rows
8. Last Stone Weight
9. Find the Winner of the Circular Game
10.Maximum Candies Allocated to K Children
11.Koko Eating Bananas
12. Merge Strings Alternately
13. Different Ways to Add Parentheses

*/


1. integer to roman 

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999
 

code 


string intToRoman(int num) 
{   
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result = "";

        for (int i = 0; i < 13; i++) 
        {       
            while (num >= values[i]) 
            {        
                result += symbols[i];         
                num -= values[i];             
            }
        }
        return result;  
}


2. reverse words in a string

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;
        while(ss >> word){
            if(result.empty()) result = word;
            else result = word + " " + result;
        }
        return result;
    }
};



3. Count Number of Homogenous Substrings




