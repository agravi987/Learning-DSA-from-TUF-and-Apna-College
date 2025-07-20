


#include<iostream>
#include<vector>
using namespace std ; 

class Node{
public: 
    int data ; 
    Node* leftNode ; 
    Node* rightNode ; 

    Node(int val){
        data = val ; 
        leftNode = rightNode = nullptr ; 
    }
};

static int idx = -1  ; 
Node* buildTree(vector<int>& preorder_seq){

    idx++ ; 
    if(preorder_seq[idx] == -1 ){
        return nullptr ; 
    }

    Node* root = new Node(preorder_seq[idx]) ; 
    root->leftNode = buildTree(preorder_seq) ; 
    root->rightNode = buildTree(preorder_seq) ; 

    return root; 
} // TC = O(n)


int height(Node* root){
    if(root == nullptr){
        return 0 ; 
    }

    int leftHeight = height(root->leftNode) ; 
    int rightHeight = height(root->rightNode) ; 

    return max(leftHeight , rightHeight) + 1 ; 
} // TC = O(n)




int main(){

    vector<int> preorder_seq = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder_seq) ; 
    cout << "The height of tree is " << height(root)  << endl ; 
    return 0 ; 
}

