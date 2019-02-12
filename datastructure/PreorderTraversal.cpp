/* Tree:Preorder Traversal

Implemented by Sin Yong Teng

*/

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



    void preOrder(Node *root) {
        if(root==NULL){
            return;
        }

        Node *curr= root;
        Node *pre;

        while(curr!=NULL){
            if(curr->left==NULL){
                cout<<curr->data<<" ";
                curr=curr->right;
            }
            else{
                pre= curr->left;
                while(pre->right !=NULL && pre->right != curr){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = curr;
                    cout<<curr->data<<" ";
                    curr = curr->left;
                }else{
                    pre->right=NULL;
                    curr=curr->right;
             }
            }
            

        }

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
  
	myTree.preOrder(root);
    return 0;
}
