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


3. 






