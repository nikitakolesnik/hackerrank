// https://www.hackerrank.com/challenges/tree-top-view/problem

// This still fails for some test cases and needs to take into account vertical level as well as horizontal.
// The mistake here was assuming that the first visited node in each horizontal level would be the topmost one

// My solution in progress are the two functions spanning lines 44 through 72, rest was pre-filled

#include<iostream>
#include<map>

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
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}
			return root;
		}
	}

    void topView(Node *root)
    {
        /*
        - Start at level "0" for root
        - Recursively visit L & R
        - decrement level for L, increment for R
        - when you visit a node, store it & its level in an ordered map IF index for level is empty
        - After the entire tree is visited, iterate through the map in ascending order of levels, printing the node values
        */

        int level = 0; // TODO: label this as horizontal level
	// TODO: declare vertical level?
        map<short, int> M; // TODO: Expand this to include the vertical level as well

        topViewIterate(root, level, M);

        for (auto i = M.cbegin(); i != M.cend(); i++)
            cout << i->second << " ";
    }

    void topViewIterate(Node *root, int &level, map<short, int> &M) // TODO: add vertical level to arguments?
    {
    	// If the level is unique, add level,value pair to map
        M.insert(pair<short, int>(level, root->data)); // TODO: Compare vertical levels, overwrite old if new smaller

        if (root->left)  topViewIterate(root->left,  --level, M);
        if (root->right) topViewIterate(root->right, ++level, M);
    }
};

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
  
	myTree.topView(root);
    return 0;
}
