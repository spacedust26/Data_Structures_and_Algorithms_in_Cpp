//Implementation Of Trie - add string, search string, delete string
//Time complexity and Space complexity Analysis
//Insertion of a string - TC: O() SC: O()
//Searching of a string - TC: O() SC: O()
//Deletion of a string - TC: O() SC: O()

#include<iostream>
using namespace std;

//Class for an individual node
class TrieNode{
  public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char data){
    this->data = data;
    for(int i = 0 ; i < 26 ; i++){
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

//Class for a Trie
class Trie{
  public:
  TrieNode *root;
  Trie(char data){
    root = new TrieNode(data);
  }

  //Insertion in a Trie
  void insertUtil(TrieNode *root, string word){
    if(word.length() == 0){
      root->isTerminal = true;
      return;
    }
    int index = word[0] - 'a'; //assuming all are lower case alphabets
    TrieNode *child;
    if(root->children[index] != NULL){
      child = root->children[index];
    }else{
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word){
    insertUtil(root, word);
  }

  //Searching in a Trie
  bool searchUtil(TrieNode *root, string word){
    if(word.length() == 0){
      return root->isTerminal;
    }
    int index = word[0] - 'a'; //assuming all are lower case alphabets
    TrieNode *child;
    if(root->children[index] != NULL){
      child = root->children[index];
    }else return false;
    return searchUtil(child, word.substr(1));
  }
  
  bool searchWord(string word){
    return searchUtil(root, word);
  }

  //Deletion in a Trie
  void deleteUtil(TrieNode *root, string word){
    if(word.length() == 0){
      root->isTerminal = false;
      return;
    }
    int index = word[0] - 'a'; //assuming all are lower case alphabets
    TrieNode *child;
    if(root->children[index] != NULL){
      child = root->children[index];
    }else{
      cout << "Word not found";
      return;
    }
    deleteUtil(child, word.substr(1));
  }
  
  void deleteWord(string word){
    deleteUtil(root, word);
  }

};

//Main function
int main(){
  Trie *t = new Trie('\0'); //root node is NULL character

  cout << "MENU: 0) Insert word 1) Search word 2) Delete word 3)Exit "<<endl;
  int option;
  do{
    cout << endl << "Enter menu option: ";
    cin >> option;
    switch(option){
      case 0:{
        string word;
        cout << "Enter word to be inserted: ";
        cin >> word;
        t->insertWord(word);
        break;
      }
      case 1:{
        string word;
        cout << "Enter word to be searched: ";
        cin >> word;
        if(t->searchWord(word) == true) cout << "Word found";
        else cout << "Word not found";
        break;
      }
      case 2:{
        string word;
        cout << "Enter word to be deleted: ";
        cin >> word;
        t->deleteWord(word);
        break;
      }
      default: break;
    }
  }while(option != 3);
}