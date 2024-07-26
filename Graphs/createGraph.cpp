#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
  public:
  unordered_map<int, list<int>> adj;

  //add an edge
  void addEdge(int u, int v, bool direction){
    adj[u].push_back(v);
    if(direction == 0) adj[v].push_back(u); //directed graph
  }

  // print the list
  void printAdjList(){
    for(auto i : adj){
      cout << i.first << " -> ";
      for(auto j : i.second){
        cout << j << " ";
      }
      cout<< endl;
    }
  }
};

//main function
int main(){
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n;
  cin >> m;
  Graph g;
  for(int i = 0; i < m ; i++){
    int u, v;
    cout << "Enter source and destination vertex: ";
    cin >> u;
    cin >> v;
    g.addEdge(u,v,0);
  }
  g.printAdjList();
  return 0;
}