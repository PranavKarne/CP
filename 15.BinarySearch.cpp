#include<bits/stdc++.h>
using namespace std;

    // lower_bound → points to the first element ≥ target.

    // in BS , left is for smaller ones and right is for bigger ones
    
    // if we dont find any index in lower_bound , the hypothetical index 
    // the last index will be the answer (i.e. "n")

    /*
    Example of lower bound

        Example 1:
        Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
        Result: 1
        Explanation: Index 1 is the smallest index such that arr[1] >= x.

        Example 2:
        Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
        Result: 3
        Explanation: Index 3 is the smallest index such that arr[3] >= x.

    */

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high){
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for a smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// upper_bound → points to the first element > target.

/*
Example of upper bound
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result: 4
Explanation: Index 4 is the smallest index such that arr[4] > x.

*/


int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x){
            ans = mid;
            //look for a smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// STL for lower_bound && upper_bound











