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

/*

lower_bound in cpp stl 

    vector<int> v = {1, 3, 3, 5, 7};

if u want the Index directly do this : 
    int idx = lower_bound(v.begin(), v.end(), 3) - v.begin();
    cout << "Index: " << idx << endl;     // 1
    cout << "Value: " << v[idx] << endl;  // 3

r
                        (OR)

if u want the interator    
    vector<int> v = {1, 3, 3, 5, 7};
    auto lb = lower_bound(v.begin(), v.end(), 3);  // auto deduces the type
    cout << "lower_bound points to: " << *lb << endl;    // 3
    cout << "Index: " << (lb - v.begin()) << endl;       // 1


upper_bound in cpp stl 

vector<int> v = {1, 3, 3, 5, 7};

// If you want the Index directly
int idx = upper_bound(v.begin(), v.end(), 3) - v.begin();
cout << "Index: " << idx << endl;     // 3
cout << "Value: " << v[idx] << endl;  // 5


// (OR)

// If you want the iterator
auto ub = upper_bound(v.begin(), v.end(), 3);
cout << "upper_bound points to: " << *ub << endl;    // 5
cout << "Index: " << (ub - v.begin()) << endl;       // 3

*/

// floor in BS = greatest element ≤ target
// ceil in BS = smallest element ≥ target






















