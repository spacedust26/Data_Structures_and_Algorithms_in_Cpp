#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *left;
  Node *right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* createBinaryTree(Node *root){
  int data;
  cout << "Enter data (-1 for no node): ";
  cin >> data;
  if(data == -1) return NULL;
  root = new Node(data);
  cout << "Left: ";
  root->left = createBinaryTree(root->left);
  cout << "Right: ";
  root->right = createBinaryTree(root->right);
  return root;
}

void printTree(Node *root){
  if(root == NULL) return;
  printTree(root->left);
  cout << root->data << " ";
  printTree(root->right);
}


int main(){
  Node *root = createBinaryTree(root);
  printTree(root);
}