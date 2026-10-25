#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val){
            data = val;
            left = right = NULL;
        }
};
static int idx = -1;
Node *buildTree(int preorder[]){
    idx++;
    if (preorder[idx] == -1){
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

int Sum(Node *root){
    if(root == NULL) return 0;

    int leftSum = Sum(root -> left);
    int rightsum = Sum(root -> right);

    return leftSum + rightsum + root -> data;
}


int main(){
    int preorder[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root = buildTree(preorder);
    cout << Sum(root) << endl;
}