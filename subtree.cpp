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
bool isIdentical(Node *p, Node *q){
    if(p == NULL or q == NULL) return p == q;

    bool isLeftSame = isIdentical(p -> left, q -> left);
    bool isRightSame = isIdentical(p -> right, q -> right);

    return (isLeftSame and isRightSame) and (p -> data == q -> data);
}

bool isSubtree(Node *root, Node *subRoot){
    if( root == NULL or subRoot == NULL) return root == subRoot;
    if((root -> data == subRoot -> data)and isIdentical(root, subRoot)) return true;
    
    return isSubtree(root -> left, subRoot) or isSubtree(root -> right, subRoot);
}
int main(){
    int preorder1[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int preorder2[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    idx = -1;
    Node *p = buildTree(preorder1);
    idx = -1;
    Node *q = buildTree(preorder2);

    cout << isIdentical(p, q) << endl;
    cout << isSubtree(p,q) << endl;
}