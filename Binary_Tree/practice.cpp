
// Class To create a node .... 
#include<iostream>
#include<vector>
using namespace std ; 

class Node{
public : 
    int data ; 
    Node* leftNode ; 
    Node* rightNode  ; 

    Node(int val){
        data = val ; 
        leftNode = rightNode = nullptr ; 
    }
};


static int idx = -1 ; 
Node* buildTree(vector<int> preOrderSeq){
    idx++ ; 

    if(preOrderSeq[idx] == -1){
        return nullptr ; 
    }

    Node* root = new Node(preOrderSeq[idx]); 
    root->leftNode = buildTree(preOrderSeq);
    root->rightNode = buildTree(preOrderSeq);
    return root ; 
}


void printTree(Node* root, string indent = "", bool isLeft = true) {
    if (root == nullptr) return;

    cout << indent;
    if (isLeft) {
        cout << "├── ";
        indent += "│   ";
    } else {
        cout << "└── ";
        indent += "    ";
    }

    cout << root->data << endl;
    printTree(root->leftNode, indent, true);
    printTree(root->rightNode, indent, false);
}


int main(){

    vector<int> preorder_seq = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder_seq);
    printTree(root);

    
    return 0 ; 
}

