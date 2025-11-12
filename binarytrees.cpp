#include <bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};


int main()
{   

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "root node" << " : " << root->data << endl;
    cout << root->left->right->data << endl;
    cout << root->left->left->data << endl;

}









/* 


// leaf node - a node which has no children

        1
       / \
      2   3
     / \
    4   5

// here 4 and 5 are leaf nodes 
// subtree :- 

        1
       / \
      2   3
     / \
    4   5

// below is the subtree of the above tree 

    2
   / \
  4   5


// ancestors

        1
       / \
      2   3
     / \
    4   5

Ancestors of 4 → 2 → 1

Ancestors of 5 → 2 → 1

Ancestors of 2 → 1

Ancestors of 1 → none (it’s the root)



// 1.Full binary tree -> A full binary tree (also called a proper or strict binary tree) is one where 
// every node has either 0 or 2 children — never just one

        1
       / \
      2   3
     / \ / \
    4  5 6  7 

Here, every node has either 0 or 2 children, so it’s full.


// 2. complete binary tree

A complete binary tree is one where all levels are completely filled except possibly the last level,
and the last level’s nodes are filled from left to right, with no gaps.

        1
       / \
      2   3
     / \  /
    4  5 6

All levels above the last are full, and the last level (4, 5, 6) is filled left to right


// 3. perfect binary tree -> all leaf nodes are at same level 
// No missing nodes, no uneven levels , A perfect binary tree is the most “balanced” kind —
// every internal node has exactly two children, and all leaf nodes are at the same level.

        1
       / \
      2   3
     / \ / \
    4  5 6  7

// 4. balanced binary tree -> height of tree can be at max log (N) , here N is nodes 

// A balanced binary tree is one where the height difference between 
// the left and right subtrees of every node is at most 1.

No branch should be much longer than another.
The tree stays “balanced” in height, not necessarily in shape.

        1
       / \
      2   3
     / \
    4   5

Left height = 2
Right height = 1
→ difference = 1 → ✅ balanced


        1
       /
      2
     /
    3

The left side goes 3 levels deep, right side is empty → difference = 3 → ❌ unbalanced



// 5. A degenerate binary tree (also called a pathological tree) is a tree 
// where every parent node has only one child.

ex:
       1
         \
          2
           \
            3
             \
              4
            
ex : 
        1
       /
      2
     /
    3
   /
  4


*/





// traversal techniques

// DFS 

1. Preorder  Traversal -  ROOT LEFT RIGHT 

// Preorder Traversal: Root → Left → Right

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val; 
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// ✅ Preorder Traversal (Root → Left → Right)
void preorder(TreeNode* root) 
{   
    if (!root) return;

    cout << root->val << " ";     // Visit root
    preorder(root->left);         // Traverse left subtree
    preorder(root->right);        // Traverse right subtree
}

int main() 
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    
    TreeNode* root = buildTree(arr);
    

    

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    return 0;
}



2. postorder traversal = Left → Right → Root

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// ✅ Postorder Traversal (Left → Right → Root)
void postorder(TreeNode* root) 
{
    if (root == nullptr ) return;

    postorder(root->left);   // Traverse left subtree
    postorder(root->right);  // Traverse right subtree
    cout << root->val << " "; // Visit root
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);
    

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}



3.inorder traversal -> left root right


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// ✅ Inorder Traversal (Left → Root → Right)
void inorder(TreeNode* root)
 {
    if (root == nullptr ) return;

    inorder(root->left);    // Traverse left subtree
    cout << root->val << " "; // Visit root
    inorder(root->right);   // Traverse right subtree
}

int main() 
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);
    

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    return 0;
}






Problems 

1. 111. Minimum Depth of Binary Tree 



“Minimum Depth” means:

The number of nodes along the shortest path from the root node down to the nearest leaf node.

A leaf node is one that has no left and no right child.

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}


int minDepth(TreeNode* root) 
{
        if(root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(root->left == nullptr) return right + 1;
        if(root->right == nullptr) return left + 1;

        return  min(left,right) + 1;

}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    TreeNode* root = buildTree(arr);
    
    cout << minDepth(root) << endl;
    cout << "\n";

    return 0;
}


2. 104. Maximum Depth of Binary Tree 

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

 int maxDepth(TreeNode* root) 
{
        
        if(root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left,right);
        

        
}


int main() 
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    
    cout << maxDepth(root) << endl;
    cout << "\n";

    return 0;
}


3. univalued binary tree - 965 

A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.



#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

bool dfs(TreeNode* node , int val)
{
    if(node == nullptr) return true;
    if(node->val != val) return false;
    return dfs(node->left , val) && dfs(node->right,val);
}




bool isUnivalTree(TreeNode* root) 
{   
    if(root == nullptr) return true;
    return dfs(root,root->val);
 
}


int main() 
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);
    
    

    
    if(isUnivalTree(root)) cout << "True" << endl;
    else cout << "False" << endl;;

    return 0;
}


4. level order traversal (BFS)

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// ✅ Level Order Traversal (BFS)
void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        // Print all nodes at the current level
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // Move to the next line for next level
    }
}






int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    cout << "Level Order Traversal:" << endl;
    levelOrder(root);

    return 0;
}

5. Binary Tree Zigzag Level Order Traversal

root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).






// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// ✅ Zigzag Level Order Traversal
void zigzagLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;  // start direction

    cout << "Zigzag Level Order Traversal:\n";

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (!leftToRight) 
        {
            reverse(level.begin(), level.end());
        }

        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;

        // Flip direction for next level
        leftToRight = !leftToRight; 
    }
}





int main() 
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    zigzagLevelOrder(root);

    return 0;
}

6. LeetCode 515: Find Largest Value in Each Tree Row.


You’re given the root of a binary tree.
You need to find the largest value in each level (row) of the tree.

Return or print those values level by level.

        1
       / \
      3   2
     / \   \
    5   3   9

1 3 9




#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// ✅ Function to find the largest value in each level (BFS)
void largestValues(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Largest value in each level:\n";

    while (!q.empty()) 
    {
        int size = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            maxVal = max(maxVal, node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        cout << maxVal << " ";
    }
    cout << endl;
}




int main() 
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    largestValues(root);

    return 0;
}


7. LeetCode 637: Average of Levels in Binary Tree.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// ✅ Function to find average of each level
void averageOfLevels(TreeNode* root) 
{
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << fixed << setprecision(5); 
    // sets number of digits after the decimal point to 5. 
    cout << "Average value at each level:\n";

    while (!q.empty()) 
    {
        int size = q.size();
        long long sum = 0;  // long long to prevent overflow

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        double avg = (double)sum / size;
        cout << avg << " ";
    }

    cout << endl;
}


int main() 
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    averageOfLevels(root);

    return 0;
}


8. Maximum Level Sum of a Binary Tree 

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input (with "null" values)
TreeNode* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}



// ✅ Function to find the level with maximum sum
int maxLevelSum(TreeNode* root) 
{
    if (!root) return 0; 

    queue<TreeNode*> q;
    q.push(root);

    int level = 0;
    int ansLevel = 0;
    long long maxSum = LLONG_MIN;

    while (!q.empty()) {
        level++; // v v imp 
        int size = q.size();
        long long sum = 0;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (sum > maxSum) 
        {
            maxSum = sum;
            ansLevel = level;
        }
    }

    return ansLevel;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    cout << "Level with maximum sum: " << maxLevelSum(root) << endl;

    return 0;
}




