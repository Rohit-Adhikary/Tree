#include <iostream>
#include<queue>
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

// preOrder traversal
void preOrder(Node *root){
    if(root == NULL) return;

    cout << root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

// inorder traversal

void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root -> left);
    cout << root -> data <<" ";
    inOrder(root -> right);
}

// postorder traversal

void postOrder(Node *root){
    if(root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data <<" ";
}

// level order traversal

void levelOrder(Node *root){
    queue<Node*> q;
    
    q.push(root);
    while(q.size() > 0){
        Node *curr = q.front();

        q.pop();
        cout << curr -> data <<" ";
        if(curr -> left != NULL) q.push(curr -> left);
        if(curr -> right != NULL) q.push(curr -> right);
    }
}

int main(){
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);
    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
}