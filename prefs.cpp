/*

3rd oct


1.Best Time to Buy and Sell Stock - minprice , maxprofit
2. Strobogrammatic Number - 0,1,3,6,9
3. minimum product subset of an array - bitmasking 
4. Class room attendance tracker - simple unor_map problem
5. coin change
6. lemonade change
7. minimum cost to connect ropes - priority queue 
8. find smallest common element in all rows
9. print matrix rows as they appear 
10. roman to integer 



*/ 

// 1.Best Time to Buy and Sell Stock




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

8. find smallest common element in all rows

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

