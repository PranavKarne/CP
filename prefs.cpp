//solutions

/*
2.
N-th Tribonacci number

class Solution {
public:

    int tribonacci(int n) 
    {
        
        long long  trib[50];
        trib[0] = 0;
        trib[1] = trib[2] = 1;
        
        for(int i = 3 ; i <= 38 ; i++)
        {
            trib[i] = trib[i-1] + trib[i-2] + trib[i-3];
        }

        return trib[n];

}};
*/

/*

3.fibonacci number

class Solution {
public:
    int fib(int x) {
        
    if(x==0) return 0;
    if(x==1) return 1;
    else 
        return fib(x-1) + fib(x-2);
       
    return 0;

        
    }

    int main(){
        int x;
        cin >>x ;
    
        int fibon = fib(x);
        cout << fibon << endl;
        return 0;
    }
};

*/



/*

4.Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s)
    {
        string s1 = "";
        for(char c :s)
        {
            if(isalnum(c))
            {
                s1 += tolower(c);
            }
        }
        string rev = s1;
        reverse(rev.begin(),rev.end());
        return rev == s1;

    }
};

*/

/*
search in 2d matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>v;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                v.push_back(matrix[i][j]);
            }
        }
        return binary_search(v.begin(),v.end(),target);
        
        
        

    }
};
*/

/*
majority element

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int n1 : nums)
        {
            mp[n1]++;
            if(mp[n1] > n /2) return n1;
        }
        return -1;
        
        


        
    }
};

*/

/*
majority element 2

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {   

        int n = nums.size();
        unordered_map<int,int>maps;
        vector<int>res;
        for(int n1 : nums) maps[n1]++;

        for(auto it : maps)
        {
            if(it.second > n/3) res.push_back(it.first);
        }
        
        return res;
    }
};
*/

/*
Valid perfect square

class Solution {
public:
    bool isPerfectSquare(long long num) 
    {
        for(long long i = 1 ; i * i <= num ; i++)
        {
            if(i*i == num) return true;
            
        }
        return false;
    }
};


*/

/*

*/

