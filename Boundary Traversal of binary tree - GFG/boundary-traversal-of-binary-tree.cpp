//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftbound(Node * node,vector<int>&left){
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL){
            return;
        }
        left.push_back(node->data);
        if(node->left==NULL && node->right!=NULL) leftbound(node->right,left);
        leftbound(node->left,left);
    }
    
    void btbound(Node * node,vector<int>&bottom){
        if(node==NULL) return;
        if(node->left==NULL and node->right==NULL ){
            bottom.push_back(node->data);
            return;
        }

           btbound(node->left,bottom);
           btbound(node->right,bottom);
    }
    
    void rightbound(Node * node,vector<int>&right){
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL) return;
        
        right.push_back(node->data);
        if(node->right==NULL && node->left!=NULL) rightbound(node->left,right);
        rightbound(node->right,right);
    }
    
    vector <int> boundary(Node *root)
    { 
        if(root==NULL) return {};
        vector<int>left,bottom,right,ans;
        if(root->left!=NULL || root->right!=NULL)ans.push_back(root->data);
        leftbound(root->left,left);
        btbound(root,bottom);
        rightbound(root->right,right);
        
        for(int i=0;i<left.size();i++) ans.push_back(left[i]);
        for(int i=0;i<bottom.size();i++) ans.push_back(bottom[i]);
         for(int i=right.size()-1;i>=0;i--) ans.push_back(right[i]);
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends