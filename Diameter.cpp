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

int height(Node *root){
    if(root == NULL) return 0;

    int leftHt = height(root -> left);
    int rightHt = height(root -> right);

    return max(leftHt, rightHt)+1;
}

int diam(Node *root){
    if( root == NULL) return 0;

    int leftDiam = diam(root -> left);
    int rightDiam = diam(root -> right);
    int currDiam = height(root -> left) + height(root -> right);

    return max(currDiam, max(leftDiam, rightDiam));
}
int main(){
    int preorder[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root = buildTree(preorder);
    cout << height(root) << endl;
    cout << diam(root) << endl;

}