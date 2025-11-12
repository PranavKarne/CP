/*

3rd oct


1.. Best Time to Buy and Sell Stock - minprice , maxprofit -> 10th nov 
2.. Strobogrammatic Number - 0,1,3,6,9 -> 10th nov 
3.. minimum product subset of an array - bitmasking -> 10th nov 
4.. Class room attendance tracker - simple unor_map problem -> 11th nov 
5.. encrypted staircase problem - recursion -> 11th nov 
6.. lemonade change -> 11th nov 
7.. find smallest common element in all rows - unor_map -> 11th nov
8.. roman to integer - unor_map and one condition -> 11th nov


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
// 0 , 1 , 8 -> ki same ee
// 6 ki 9 , 9 ki 6 

bool isStrobogrammatci(string &num)
{
    string rotated = "";
    for(int i = num.size() - 1 ; i >= 0; i--)
    {
        char c = num[i];
        if(c == '0' || c == '1' || c == '8')
        {
            rotated += c;
        }
        else if(c == '6') rotated += '9';
        else if (c == '9') rotated += '6';
        else return false;

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
    long long n ; cin >> n;
    vector<long long >arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
    long long minProduct = arr[0];

    for(long long mask = 1 ; mask < (1LL << n) ; mask++)
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

    vector<vector<int>> matrix(n,vector<int>(m));
    


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
    for(auto it : freqmap) 
    {
        if(it.second == n) 
        {
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
    // roamtoint -> map -> conditions
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
                if(tens && fives)
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

int countWays(int n, int m) 
{
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ways = 0;

    for (int i = 1; i <= m; step++) ways += countWays(n - i, m); 
    return ways;
}



/*

5th october

1.. integer to roman - 9th nov 
2.. reverse words in a string - 9th nov 
3.. Count Number of Homogenous Substrings - 9th nov 
4.. Minimum Cost to connect ropes - 9th nov 
5..  coin change - 9th nov 
6.~~   Store Questions with Answers in Insertion Order (not needed)
7..  Print Matrix Rows - 9th nov 
8..   Last Stone Weight - 10th nov 
9.   Find the Winner of the Circular Game - 10th nov 
10..   Maximum Candies Allocated to K Children - 10th nov 
11..  Koko Eating Bananas - 8th nov 
12..  Merge Strings Alternately - 8th nov 
13.~~   Different Ways to Add Parentheses (not needed)
14.. arranging coins - 8th nov 


15.. longest mountain in array - https://leetcode.com/problems/longest-mountain-in-array/description/ - 8th nov 
16.. Find the K-Beauty of a Number. - 8th nov 
17..  Baseball Game - 8th nov 
18.. Largest Number At Least Twice of Others.  - 8th nov 






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


Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
Example 3:

Input: s = "zzzzz"
Output: 15


code : 



int counthomosubstrings(string s)
{
    long long ans = 0;
    long long count = 1;

    const int MOD = 1e9 + 7;

    for(int i = 1; i < s.size() ; i++)
    {
        if(s[i] == s[i-1]) count++;
        else count = 1;
        ans += count;
    }

    ans = ans % MOD;
    return ans+1;

}


// 4. Minimum Cost to connect ropes




int connectSticks(vector<int>& sticks) 
{
        // Use a min-heap to always access the smallest sticks efficiently
        // This ensures we minimize the cost by combining smallest sticks first
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int , vector<int> , greater<int>> minHeap;
        priority_queue<int , vector<int> , greater<int>> minHeap;


        // Add all sticks to the min-heap
        for (const int& stickLength : sticks) {
            minHeap.push(stickLength);
        }

        // Track the total cost of connecting all sticks
        int totalCost = 0;

        // Keep combining sticks until only one remains
        while (minHeap.size() > 1) {
            // Extract the two smallest sticks
            int firstSmallest = minHeap.top();
            minHeap.pop();

            int secondSmallest = minHeap.top();
            minHeap.pop();

            // Calculate the cost of combining these two sticks
            int combinedLength = firstSmallest + secondSmallest;

            // Add the cost to the total
            totalCost += combinedLength;

            // Push the combined stick back to the heap for further combinations
            minHeap.push(combinedLength);
        }

        return totalCost;
}

//16.. Find the K-Beauty of a Number.

The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:

It has a length of k.
It is a divisor of num.
Given integers num and k, return the k-beauty of num.

Note:

Leading zeros are allowed.
0 is not a divisor of any value.
A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: num = 240, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.
Example 2:

Input: num = 430043, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "43" from "430043": 43 is a divisor of 430043.
- "30" from "430043": 30 is not a divisor of 430043.
- "00" from "430043": 0 is not a divisor of 430043.
- "04" from "430043": 4 is not a divisor of 430043.
- "43" from "430043": 43 is a divisor of 430043.
Therefore, the k-beauty is 2.

int divisorSubstrings(int num, int k) 
{   
        string numStr = to_string(num);
        int n = numStr.size();
        int count = 0;

        for (int i = 0; i <= n-k ; i++) {
            string subStr = numStr.substr(i, k);   
            int val = stoi(subStr);                   
            if (val != 0 && num % val == 0) count++; 
        }
 
        return count;
}




//15.  longest mountain in array

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
 

Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?

int longestmountain(vector<int>&arr)
{
    int n = arr.size();
    int longest_mountain = 0;
    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(arr[i] < arr[i+1] && arr[i] > arr[i+1])
        {
            int left = i;
            int right = i;


            while(left > 0 && arr[left - 1] > arr[left]) left--;
            while(right < n - 1 && arr[right] > arr[right + 1]) right++;


            longest_mountain = max(longest_mountain , right - left + 1 );
        }
    }
    return longest_mountain;
}



//18.Largest Number At Least Twice of Others.

You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

 

Example 1:

Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.
Example 2:

Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.
 

Constraints:

2 <= nums.length <= 50
0 <= nums[i] <= 100
The largest element in nums is unique.


int dominantIndex(vector<int>& nums)
{

        
        int n = nums.size();
        int max_index = 0;
        int max = nums[0];
        for(int i  = 0 ; i < n ; i++)
        {
            if(nums[i] > max)
            {
                max = nums[i];
                max_index = i;
            }
        }
        

        int largest = *max_element(nums.begin() , nums.end());
        
        int count = 0;

        for(int i = 0 ; i < n ; i++)
        {   

            if(largest >= 2 * nums[i]) count++;
            
        }

        if(count == n - 1) return max_index;
        else return -1;


        
}

// 7.Print Matrix Rows  

Given an an N×N matrix, print its rows as they appear.

problem

Rahul is given a row of numbers where each row and columns are same.
Rahul now prints the numbers of the rows as shown in the following manner.
Help Rahul to write the code .

The first line of input consists of the size followed by the row numbers.

Sample Input:
3
1 2 3
4 5 6
7 8 9

Explanation:

1<-2<-3
|
4->5->6
|
7<-8<-9

Sample Output:
3 2 1 4 5 6 9 8 7

int N , M ;
cin >> N >> M;
vector<vector<int>> matrix(N , vector<int>(M));
vector<vector<int>> matrix(N , vector<int>(M));
vector<vector<int>> pranavkarne1(n , vector<int>(M));
vector<vector<int>> matrixname(n,vector<int>(M));
vector<vector<int>> matrixname(n,vector<int>(M));



for(int i = 0 ; i < N ; i++)
{
    for(int j = 0 ; j < M ; j++)
    {
        cin >> matrix[i][j];
    }
}

for(int i = 0 ; i < N ; i++)
{
    if(i % 2 == 0) // even row - print right to left 
    {
        for(int j = M - 1 ; j >= 0 ; j--) 
        {
            cout << matrix[i][j] << endl;
        }
    }
    else
    {   // odd row - prints from left to right 
        for(int j = 0 ; j < M ; j++)
        {
            cout << matrix[i][j] << endl;
        }

    }
}

for(int i = 0 ; i < N ; i++)
{
    if(i % 2 == 0) // even row - print right to left
    {
        for(int j = M - 1 ; j >= 0 ; j--)
        {
            cout << matrix[i][j] << endl;
        }
    }
    else 
    {  // odd row - prints froom left to right 
        for(int j = 0; j < M ; j++)
        {
            cout << matrix[i][j] << endl;

        }
    }
}



// 14. arranging coins 

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
 

Constraints:

1 <= n <= 2^31 - 1

long long  arrangeCoins(long long n)
{   
        long long low = 0 ; 
        long long high = n ;
        int ans = 0;

        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            long long total_coins = mid * (mid+1)/2;
            if(total_coins == n) return mid;
            else if(total_coins < n) 
            {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
}

So, if you build mid rows,
you’ll need a total of
1 + 2 + 3 + ... + mid coins. 
so mid * (mid +1) / 2;

//5. coin change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104


int coinChange(vector<int>& coins, int amount) 
{
        sort(coins.rbegin() , coins.rend());
        int count = 0;
        for(int coin : coins)
        {
            if(amount >= coin)
            {
                int use = amount / coin ;
                count += use;
                amount = amount % coin;
            }
        }

        if(amount != 0) return -1;
        else return count;
}


// 12. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 



string mergeAlternately(string word1, string word2)
{
        string ans = "";

        int n = word1.size();
        int m = word2.size();

        int i = 0;
        int j = 0;

        while(i < n && j < m)
        {
            ans += word1[i++];
            ans += word2[j++];
        }

        while(i < n) ans += word1[i++];
        while(j < m ) ans += word2[j++];
        return ans;
}


// 17. baseball game 

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

 

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.
 

Constraints:

1 <= operations.length <= 1000
operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.


code

class Solution {
public:
    int calPoints(vector<string>& operations) 
    {   
        vector<int>res;
        int x = operations.size();
        

        for(int i = 0 ; i < x ; i++)
        {
            if(operations[i] != "C" && operations[i] != "D" && operations[i] != "+")
            {
                int temp = stoi(operations[i]);
                res.push_back(temp);
            }
            else if(operations[i] == "+")
            {   
                int n = res.size();
                int sum = res[n-1] + res[n-2];
                res.push_back(sum);
            }
            else if(operations[i] == "C")
            {
                res.pop_back();
            }
            else if(operations[i] == "D")
            {   
                int n = res.size();
                
                int d_operation = 2 * res[n-1];
                res.push_back(d_operation);
            }
        }

        
        int total_sum = accumulate(res.begin() , res.end() , 0);
        return total_sum;


    }
};

// 11. koko eating bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

long long  totalhours(vector<int>&piles , long long h)
{
        long long  hours = 0;
        long long  n = piles.size();
        for(long long  i = 0 ; i < n ; i++)
        {
            hours += ceil((double)(piles[i]) / (double)(h));
        }
        return hours;
}

long long minEatingSpeed(vector<int>& piles, long long  h) 
{   
        sort(piles.begin() , piles.end());
        long long n = piles.size();
        long long  max_element = piles[n-1];
        long long low = 1;
        long long  high = max_element;
        while(low <= high)
        {
            long long mid = low + (high - low)/2 ;
            long long  res = totalhours(piles,mid);
            if(res <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
}

//  Maximum Candies Allocated to K Children

You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the  number of candies each child can get.

 

Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
Example 2:

Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.
 

Constraints:

1 <= candies.length <= 105
1 <= candies[i] <= 107
1 <= k <= 1012

bool distribution(vector<int>& candies , long long k , long long mid)
    {
        long long count = 0;
        for(int c : candies)
        {
            count += c / mid;
        }
        return count >= k;
    }

int maximumCandies(vector<int>& candies, long long k) 
{   
        long long low = 1;
        long long high = *max_element(candies.begin() , candies.end());
        long long ans = 0;
        while(low <= high)
        {
            long long  mid = low + (high - low)/2;
            if(distribution(candies,k,mid))
            {
                ans  = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;        
}

// 8. last stone weight 
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that the value of last stone




Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000


code :
int lastStoneWeight(vector<int>& stones) 
{   
        priority_queue<int>pq;
        for(int stone : stones) pq.push(stone);
        while(pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x != y ) pq.push(y-x);
        }
        if(pq.empty()) return 0;
        else return pq.top();
}

    
// 9. Find the Winner of the Circular Game

There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.

 

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // 0-indexed base case 
        for (int i = 1; i <= n; i++) 
        {
            winner = (winner + k) % i;
        }
        return winner + 1; // convert to 1-indexed
    }

    int findwinner(int n , int k)
    {
        int winner = 0;
        for(int i = 1; i <= n ; i++)
        {
            winner = (winner + k) % i;
        }
        return winner + 1; 

    }

    int findwinner(int n , int k)
    {
        int winner = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
    
};













