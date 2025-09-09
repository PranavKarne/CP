
// If we say the definition of hashing in a naive way, it is nothing but the combination of the steps, pre-storing, and fetching.
// inside main function the maximum int array size is 10^6 and globally 10^7 is maximum 
// for bool arrays it is 1e7 in main function and 1e8 globally

// 10^6 = 1e6 
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] +=1;
    }

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    return 0;
}