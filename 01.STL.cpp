#include<bits/stdc++.h>
using namespace std;

/*


STL 

1.Pairs 
2.Vectors
3.Lists
4.Stacks
5.Queue
6.Priority Queue 
7.Set
8.Multiset
9.Unordered Set
10.Map 
11.multimap
12.unordered map 


*/
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


// how to print the complete pair or pair of vectors

/*

void printVectorOfPairs(vector<pair<int,int>> &vec) 
{
    for(auto p : vec)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
}

int main()
{
    vector<pair<int, int>> arr = {{1,2},{1,4},{5,6}};
    printVectorOfPairs(arr);
    return 0;
}

*/


    
    

// 2.Vectors - dynamic in nature
 



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

    // TC - O(1) 
    // lower bound and upper bound function does not work 
    // all operations are similar to set 



    // 8.Map 

    map<int,int>mpp;
//     (key,value) 
    mpp[1] = 2; // ->{1,2} -> {key , value} 

    mpp.insert({4,5}); // key,value

    mpp[5] = 50;
    mpp[10] = 100;

    for (auto it : mpp)
    {
        cout << "Key: " << it.first << " -> Value: " << it.second << "\n";
    }

    // to find 
    for (auto it : mpp)
    {
        if (it.first == 1)
    {
        cout << it.first << " " << it.second << endl;
    }
} 

    // map stores keys(unique) in sorted order 
    
    // (key,value) -> keys are unique , values can be duplicate , key can be any datatype

    // do research on map + pair mixing , learn how to use it 

    // erase , swap , size are same as above 



     

    map<int,pair<int,int>>mpp1;
    
    //  --> key is int  & value is 2 integers 

    mpp1[1] = {10, 20};
    mpp1[2] = {30, 40};
    //  [key] = {values};

    for (auto it : mpp1)
    {
        cout << "Key: " << it.first << " -> Value: (" << it.second.first << ", " << it.second.second << ")\n";
    }

    

    map<pair<int,int>,int>mpp2; // --> key is 2 integers & value is 1 integer
    mpp2[{2,4}] = 100;
    mpp2[{1, 2}] = 100;
    mpp2[{3, 4}] = 200;
//    [{keys pair}] = value ;


// 9.MultiMap -> similar to map but only difference is tht it can store multiple keys(duplicate keys)
//  but everything  in sorted order



// 10. unordered map --> will have unique keys , not in sorted order


// maps are O(log n) 
// unordered map is O(1) in all cases ,very rarely O(N) once in a bluemoon


// sorting

int n ;
int a[n];
sort(a,a+n); // [start , end)

vector<int>v;
sort(v.begin() , v.end());

// to sort a particular portion of the vector(ascending)

    vector<int>v1 = {4,9,6,4,1,4,2};
    sort(v1.begin()+2,v1.begin()+4); // -> here it [start,end)
    for(auto it : v1) cout << it << " ";

// to sort in descending order 

    vector<int> v = {4,2,5,3,5,8,3};
    sort(v.rbegin(),v.rend());   // --> decreasing order  sorting
    for(auto it : v) cout << it << " " ; // --> 8 5 5 4 3 3 2 
    // or

    // sort(v,v+n,greater<int>);


// to sort in my own way (this will be used alot in future)

/*

bool comp(pair<int,int>p1 , pair<int,int>p2) 
{
    // we assume tht the p1 lies before p2

    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    // if they are same 
    if(p1.first > p2.first) return true;
    else return false;


}

*/

// sort it acc to second element and if second element is same then sort it 
// according to 1st element but in descending 

pair<int,int>a[] = {{1,2},{2,1},{4,1}};

 

// sort(a,a+n,comp);
// comp  --> it is a self return comparator and it is a bool function

// {4,1} , {2,1} , {1,2}

    int num = 7;
    int set_bits = __builtin_popcount(num); // --> in its binary form it gives the number of set bits
    cout << set_bits ;

// for a larger number (long long)

    long long  num1 = 90886848348924923;
    int set_bits1 = __builtin_popcountll(num1);
    cout << set_bits1 << endl;


// how to print permutations of a string

string s = "pranavkarne";
sort(s.begin() , s.end());

do
{   
    cout << s << '\n';
}
while (next_permutation(s.begin(),s.end()));


//  how to find the max element / min element in an array or vector

    vector<int>v =  {4,5,6,23,23,242,4};
    int max_elemen = *max_element(v.begin() , v.end());
    int min_elemen = *min_element(v.begin() , v.end());

    cout << max_elemen << '\n' ;
    cout << min_elemen << '\n' ;




















 














   
















    


     



















}
