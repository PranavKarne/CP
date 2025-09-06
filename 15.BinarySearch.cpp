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
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x); 
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

// upper_bound → points to the first element > target.


int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}






