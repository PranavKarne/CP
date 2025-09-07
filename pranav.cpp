#include<bits/stdc++.h>
using namespace std;
int main()
{
    // partition array by sign(-ve,+ve)

    
    

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};

    

    //v2 now has all elements
    v2.insert(v2.end(),v1.begin(),v1.end());
    for(int y : v2) cout << y << " ";
    cout << endl; 


    cout << "example 2" << endl;
    vector<int>karne = {7,8,9};
    vector<int>pk = {10,11,12};

    karne.insert(karne.end(),pk.begin(),pk.end());
    for(int p : karne) cout << p << " ";
    cout << endl;








    

    


}
