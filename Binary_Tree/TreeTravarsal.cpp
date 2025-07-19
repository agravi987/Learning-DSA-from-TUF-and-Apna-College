
#include <iostream>
#include <vector>
#include <queue>

using namespace std ; 

class Node {
public:
    int data ; 
    Node* leftNode ; 
    Node* rightNode ; 

    Node(int val){
        data = val ; 
        leftNode = rightNode = nullptr ; 
    }
};

static int idx = -1 ; 

Node* buildTree(vector<int>& preOrderSeq){
    idx++ ; 

    if(preOrderSeq[idx] == -1){
        return nullptr ; 
    }

    Node* root = new Node(preOrderSeq[idx])  ;
    root->leftNode = buildTree(preOrderSeq)  ; 
    root->rightNode = buildTree(preOrderSeq) ; 
    return root ;

    
}


void preOrder(Node* root){
    if(root == nullptr){
        return ; 
    }

    cout << root->data << " " ; 
    preOrder(root->leftNode) ; 
    preOrder(root->rightNode) ; 


}


void inOrder(Node* root){
    if(root == nullptr){
        return ; 
    }

    inOrder(root->leftNode) ; 
    cout << root->data << " " ; 
    inOrder(root->rightNode) ; 

}


void postOrder(Node* root){
    if(root == nullptr){
        return ; 
    }

    postOrder(root->leftNode) ; 
    postOrder(root->rightNode) ; 
    cout << root->data << " " ; 
  
}

void levelOrder(Node* root){
    queue<Node*> Q ; 
    Q.push(root) ; 

    while(!Q.empty()){
        Node* current = Q.front() ; 
        Q.pop() ; 
        cout << current->data << " " ; 
        if(current->leftNode ) Q.push(current->leftNode) ; 
        if(current->rightNode ) Q.push(current->rightNode) ; 
    }
}


int main() {
    vector<int> preorder_seq = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder_seq) ; 


    preOrder(root);
    cout << endl ; 
    inOrder(root);
    cout << endl ; 
    postOrder(root);
    cout << endl ; 
    levelOrder(root);
    cout << endl ; 

}