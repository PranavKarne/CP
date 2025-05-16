#include<bits/stdc++.h>
using namespace std;


int main()
{   
    //1. Pairs

    pair<int , int > p = {1,5};
    // p.F -> 1 , p.S -> 5

    // to store 3 elements

    pair<int,pair<int , int>>p = {1,{3,4}};

    //p.F = 1 . p.S.F = 3

    pair<int , int> arr[] = {{1,2},{1,4},{5,6}};
	//cout << arr[0];

    // this doesnt work in u cannot print the pair directly

    //instead u can do this 

    pair<int , int> arr[] = {{1,2},{1,4},{5,6}};
    cout << arr[0].first << " " << arr[0].second << " " << endl;
    cout << arr[1].first << " " << arr[1].second << " " ;

  /*  output :
    1 2 
    1 4 
  */


// to print a pair , u can do this 

/*
void printPair(pair<int, int> p)
{
    cout << "(" << p.first << ", " << p.second << ")" ;
}

int main() {
    pair<int , int> arr[] = {{1,2},{1,4},{5,6}};
    printPair(arr[0]);
    return 0;
}
*/







    
    

// 2.Vectors - dynamic in nature
 
vector<int> v;
v.push_back(1);


vector<pair<int,int>>vec;
// do more research on this , taking input , printing output etc ;


vector<int>v(5,10); // -->  {10,10,10,10,10};


for(auto it : v) cout << it << " ";

vector<int>v2 ; 
for(auto it : v2) cout <<  it << " ";

//{10,20,12,23}
v.erase(v.begin()+1); // -> 20 is deleted

//{10,20,12,23,35}
v.erase(v.begin()+2 , v.begin()+4); // [start,end) --> {10,20,35}


vector<int>v(2,100); // -> {100,100}
v.insert(v.begin(),300); // -> {300,100,100}
v.insert(v.begin()+1 , 2,10); // -> {300,10,10,100,100}

vector<int>copy(2,50); // -> {50,50}
v.insert(v.begin(),copy.begin(),copy.end()); // -> {50,50,300,10,10,100,100}

 


    // 3. Lists
list<int>ls = {2,4};
ls.push_back(5); // -> {5,2,4}
//less TC


    // 4.Stack - LIFO 


stack<int>st;

st.top(); // -> prints the last guy who went it
// indexing is not allowed  
st.push(4);
st.pop(); // -> removes the "top" element
st.size();
st.empty();
stack<int>st2;
st2.swap(st);

// Queue and Priority Queue we will covered in Level 2

    // 5. Set -> sorted & unique order

    set<int>set={2,4,5,8};
   // st.insert(4);
    set.emplace(8);
    
    set.erase(8) ;

    //.find() returns an iterator — not a boolean!
    auto it = set.find(5);  // tries to find 5

    if (it != set.end()) 
    {
        cout << "Found: " << *it << endl;  // dereference to get the value
    } 
    else 
    {
        cout << "Not Found" << endl;
    }
    int cnt = set.count(1);


    auto it = set.find(3);
    set.erase(it);

    // {1,2,3,4,5}
    auto it1 = set.find(2);
    auto it2 = set.find(4);
    set.erase(it1,it2) ; // [start,end)


    // 6. Multiset --> only sorted but not unique , stores multiple occurences

    multiset<int>mst;
    mst.erase(2); // erases all the occurences of 2 in the multiset;

    mst.erase(mst.find(1));
    // only a single one is erased

   

    // 7. Unordered Set --> everything is same as set , but not in sorted order but has unique

    unordered_set<int>unst;

    //TC - O(1) 
    // lower bound and upper bound function does not work 
    // all operations are similar to set 

    // 8.Map 

    map<int,int>mpp;
//     (key,value)
    mpp[1] = 2; // ->{1,2}

    mpp.insert({4,5}); // key,value

    // map stores keys(unique) in sorted order 
    
    // (key,value) -> keys are unique , values can be duplicate , key can be any datatype

    // do research on map + pair mixing , learn how to use it 
    
    map<int,pair<int,int>>mpp1;
    map<pair<int,int>,int>mpp2;

     
























    





}
