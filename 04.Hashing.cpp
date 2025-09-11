
// If we say the definition of hashing in a naive way, it is nothing but the combination of the steps, pre-storing, and fetching.
// inside main function the maximum int array size is 10^6 and globally 10^7 is maximum 
// for bool arrays it is 1e7 in main function and 1e8 globally

// 10^6 = 1e6 
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // number hashing

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




// character hashing

    string s;
    cin >> s;
    // a - 97 , z - 122 

    int string_hash[26] = {0};
    for (int i = 0; i < s.size(); i++) 
    {
        string_hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while (q--) 
    {
        char c;
        cin >> c;
        // fetch:
        cout << string_hash[c - 'a'] << endl;
    }

    // Code if the string contains both uppercase and lowercase:
    // works for both 

    int hash1[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash1[s[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetch:
        cout << hash[c] << endl;
    }
    // maps - stores everything in sorted order
    // Key: In a map, a key refers to the element, for which we want to store information. 
    // We can access the value of a key using the key itself like mp[key].
    // Value: Value refers to the information stored corresponding to a key.
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    int number;
    cin >> number;
        // fetch:
    cout << mp[number] << endl;
    
    // using maps in string hashing

    map<char,int>mpp;
    for (int i = 0; i < n; i++) {
        mpp[s[i]]++;
    }

    // character hashing

    map<char, int> mp;
    for (char c : s) 
    {
        mp[c]++;
    }

    // maps = in storing and fetching takes log n TC in all cases 



    // unordered_map = no order 
    // TC -> the avg and the best tc is O(1) for most cases in
    // in worst case it is O(N) for unordered_map , very rare

    








    



}