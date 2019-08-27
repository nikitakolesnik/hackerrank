// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
// Solution is the lca function beginning on line 48 - the rest was pre-filled

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
        if (!root)
            return root;

        Node *curr = root;

        if (v1 > v2) // Make sure v1 is less than v2
        {
            v1 ^= v2; // XOR swap
            v2 ^= v1;
            v1 ^= v2;
        }

        while( curr->data < v1 || curr->data > v2 ) // While it's not in the middle
        {
            curr = (curr->data > v2) ? curr->left : curr->right; // Move to the outlier
        }

        return curr;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
