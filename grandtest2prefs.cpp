

1. Largest number atleast twice of others - over 
2. Baseball game - over 
3. Find the k-beauty of a number
4. Longest mountain in array - over 
5. Arranging coins - over 
6. Merge strings altternatively - over 
7. Koko eating bananas
8. Integer to roman 
9. Reverse words in string 
10. Count number of substrings 
11. Minimum cost to connect ropes 
12. Coin change
13. Print matrix Rows 
14. Last stone weight - over 
15. Find the winner of the circular game
16. Maximum candies allocated to k children
17. Best time to buy and sell stock - over 
18. Strogrammatic number
19. minimum product subset of an array 
20. class room attendence tracker - over 
21. encrypted staircase problem - over 
22. lemonade change - over 
23. find the smallest common element in all rows - over 
24. roman to integer 

1.largest number atleast twice of others


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



code :



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


2. baseball game 


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









11th nov 

1. class room attendence tracker - over 
2. encrypted staircase problem - over 
3. lemonade change - over 
4. find the smallest common element in all rows - over 
5. roman to integer 


1. class room attendence tracker

A teacher keeps track of student names for each day of class. Some students attend multiple days, so their names appear multiple times in the attendance list.

Your task is to count how many times each student attended class and display the results in alphabetical order of names.

Input Format
------------
First line: an integer n — number of attendance entries (1 ≤ n ≤ 1000).
Second line: n space-separated strings — names of students.

Output Format
-------------
For each student, print:
StudentName:Count
Names should be printed in alphabetical order.

Example 1
---------
Input=
6
Alice Bob Alice Charlie Bob Alice

Output=
Alice:3
Bob:2
Charlie:1

Example 2
---------
Input=
5
David Eve David Eve Frank


Output=
David:2
Eve:2
Frank:1



int main()
{
    int n ; cin >> n ;
    cin.ignore(); // clear leftover newline 
    string s; getline(cin , s);
    stringstream ss(s);
    string pranav;
    map<string,int>pk;
    while(ss >> pranav)
    {
        pk[pranav]++;
    }

    for(auto it : pk)
    {
        cout << it.first << " " << it.second << endl;
    }

}

2. encrypted staircase problem



In an ancient temple, there's a mystical staircase with n steps. A codebreaker needs to reach the top of the staircase by making jumps of at most m steps at a time.  
That means from any step, they can move to the next 1, 2, ..., up to m steps ahead – if possible.

Write a function countWays(n: int, m: int) -> int that returns the total number of distinct ways the codebreaker can climb from step 0 to step n.

Assume:

The codebreaker starts from step 0 (ground).

They can only move upward.

You need to compute the number of different sequences of jumps that sum up to exactly n steps, where each jump is between 1 and m.

Examples:
Example 1:
Input: n = 4, m = 2
Output: 5
Explanation: The codebreaker can jump in these 5 ways:

1 + 1 + 1 + 1  
1 + 1 + 2  
1 + 2 + 1  
2 + 1 + 1  
2 + 2

Example 2:
Input: n = 3, m = 3
Output: 4
Explanation:
1 + 1 + 1  
1 + 2  
2 + 1  
3


int countWaysRecursive(int n, int m) 
{
    if (n == 0) return 1;   // one way (no move)
    if (n < 0) return 0;    // invalid

    int total = 0;
    for (int i = 1; i <= m; i++)
        total += countWaysRecursive(n - i, m);

    return total;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    cout << countWaysRecursive(n, m);
    return 0;
}


3. lemonade change 


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
 
code:



bool lemonadeChange(vector<int>&bills)
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
            else if(fives >= 3) fives-=3;
            else return false;
        }
    }
    return true;

}


4. find the smallest common element in all rows 

Each row is sorted in non-decreasing order.

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n,vector<int>(m));
    vector<vector<int>>matrix(n,vector<int>(m));
    

    


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

    
5. Longest Mountain in Array

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


int longestMountain(vector<int>& arr) 
    {   
        int n = arr.size();
        if(n < 3) return 0;
        int longest_mountain = 0;
        for(int i = 1 ; i < n - 1 ; i++)
        {
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
            {
                int left = i ;
                int right = i ;

                while(left > 0 && arr[left-1] < arr[left]) left--;
                while(right < n - 1 && arr[right] > arr[right+1]) right++;

                longest_mountain = max(longest_mountain , right - left + 1);
            }
        }
        return longest_mountain;        
    }



6. arranging coins 

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

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

7. merge strings alternatively

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



14. last stone weight 



You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.


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
