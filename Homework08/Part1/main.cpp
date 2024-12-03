//Programmer: Logan Kelsch
//Homework 08
//Date: 4/29/24
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

#include "WGraph.h"
//#include "Graph.h"

using namespace std;
using namespace std::chrono;

//HOMEWORK 08 SPECIFIC FUNCTIONS__________________
//function to check if graph is connected
template <class T, class W> bool connected(WGraph<T, W> &);
template <class T, class W>
void ConnDFS(WGraph<T, W> &, vector<int> &, vector<T> &, int, int &);
//Jarnik-Prim algorithm
template<class T, class W> WGraph<T,W> JPAlgorithm(WGraph<T,W> &G);
//Total Weight return function
template<class T, class W> int totalWeight(WGraph<T,W> G,bool dir);
//________________________________________________
//Kruskal aglorithm
template <class T, class W> WGraph<T, W> KruskalAlgorithm(WGraph<T, W> &G);
//cycle detecting function
template <class T, class W> bool detectCycles(WGraph<T, W> &);
template <class T, class W>
void CycleDFS(WGraph<T, W> &, vector<int> &, vector<T> &, int, int &,
              vector<pair<T, T>> &, bool &);

void div() { cout << "\n---------------------------------\n\n"; }

int main() {
  srand(time(0));
  
  auto start = high_resolution_clock::now();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  
  //PRE-EXISTING MAIN, WAS REQUESTED TO REMAIN IN HOMEWORK FOR TESTING
  //BEGINS HERE ______________________________________________________
  // An undirected connected weighted graph.
  WGraph<char, int> G(0);

  G.addEdge('a', 'b', 6);
  G.addEdge('a', 'c', 5);
  G.addEdge('b', 'c', 9);
  G.addEdge('b', 'e', 13);
  G.addEdge('c', 'd', 16);
  G.addEdge('c', 'f', 12);
  G.addEdge('d', 'e', 15);
  G.addEdge('d', 'f', 7);
  G.addEdge('e', 'g', 8);
  G.addEdge('f', 'g', 3);
  
  G.sortVertexList();
  G.print();
  G.saveGraphFileGML("G");

  div();
    //use of JPalgorithm here
  WGraph<char, int> MST = JPAlgorithm(G);
  //KruskalAlgorithm(G);
  MST.sortVertexList();
  MST.print();
  cout<<endl<<"WEIGHT: "<<totalWeight(MST,G.isDirected())<<endl;
  MST.saveGraphFileGML("MST");
  //PRE-EXISTING MAIN 
  //END HERE___________________________________________________________

  return 0;
}

/*
Kruskal's Algorithm for finding a minimal spanning tree for a weighted,
connected, undirected graph.  The algorithm does not check that the graph is
connected, it is assumed that this is the case.

Parameter: Weighted Connected Undirected Graph G.
*/
template <class T, class W> WGraph<T, W> KruskalAlgorithm(WGraph<T, W> &G) {
  WGraph<T, W> MST;
  vector<pair<T, pair<T, W>>> edges = G.getEdgeList();

  sort(edges.begin(), edges.end(),
       [](auto &a, auto &b) { return a.second.second < b.second.second; });

  int MSTedgecount = 0;
  int Gvertcount = G.size();
  for (size_t i = 0; i < edges.size() && MSTedgecount < Gvertcount - 1; i++) {
    // If the edge is already in the graph move to the next one.
    if (MST.getEdgePos(edges[i].first, edges[i].second.first) != -1)
      continue;

    WGraph<T, W> TestMST = MST;
    TestMST.addEdge(edges[i]);
    if (!detectCycles(TestMST)) {
      MST.addEdge(edges[i]);
      MSTedgecount++;
    }
  }

  return MST;
}

//JARNIK PRIM ALGORITHM
template<class T, class W> WGraph<T,W> JPAlgorithm(WGraph<T,W> &G){
    //tree = null
  WGraph<T, W> MST;
  //get list of edges in G
  vector<pair<T, pair<T, W>>> edges = G.getEdgeList();
    //sort list of edges by weight, least to greatest
  sort(edges.begin(), edges.end(),
       [](auto &a, auto &b) { return a.second.second < b.second.second; });
    //edgecounter and vert count
  int MSTedgecount = 0;
  int Gvertcount = G.size();
  //for each edge in order
  for (size_t i = 0; i < edges.size() && MSTedgecount < Gvertcount - 1; i++) {
    // If the edge is already in the graph move to the next one.
    if (MST.getEdgePos(edges[i].first, edges[i].second.first) != -1)
      continue;
    //make testing graph for insertion testing
    WGraph<T, W> TestMST = MST;
    //add next edge
    TestMST.addEdge(edges[i]);
    //see if it generated a cycle in the test tree
    if (!detectCycles(TestMST)) {
        //get verteces in test graph to check for incidents
        vector<T> verts = TestMST.getVertexList();
        bool incident = false;
        for(size_t n = 0; n < verts.size(); n++){
            //if the edge is incident to any vertex in test tree
            if(verts[n] == edges[i].first||verts[n] == edges[i].second.first)
                incident=true;
        }
        //insert edge into tree after passing both tests
        if(incident){
            MST.addEdge(edges[i]);
            MSTedgecount++;
        }
    }
  }
  return MST;
}

//Total Weight function, returns total weight of tree
template<class T, class W> int totalWeight(WGraph<T,W> G, bool dir){
    //make vector of edges
    vector<pair<T, pair<T, W>>> edges = G.getEdgeList();
    //E is number of edges in vector
    int E = edges.size();
    //weight variable to tally total
    int weight = 0;
    //tally and return weight
    for(int i = 0; i < E; i++){
        weight+=edges[i].second.second;
    }
    if(!dir)
        weight/=2;
    return weight;
}

/*
Cycle detection algorithm for an undirected weighted graph.  This portion
sets up the counting array and edge tracker and then calls the recursive
depth first search algorithm to cycle check.

Parameter: Weighted Graph G.
*/
template <class T, class W> bool detectCycles(WGraph<T, W> &G) {
  vector<T> vlist = G.getVertexList();
  vector<int> num(vlist.size());
  vector<pair<T, T>> Edges;
  int count = 1;
  bool cycle;

  while (find(num.begin(), num.end(), 0) < num.end()) {
    int pos = find(num.begin(), num.end(), 0) - num.begin();
    CycleDFS(G, num, vlist, pos, count, Edges, cycle);
  }

  return cycle;
}

/*
Recursive depth first search algorithm to cycle check, for an undirected
weighted graph.

Parameters:
 - Weighted Graph G
 - num: vector of integer counts to track visitation
 - vlist: vector of vertex names, used to determine positions of the
     vector/edge data in the graph.
 - pos: position of the vertex being processed/visited by the algorithm.
 - count: The current visit count.
 - Edges: vector of edge data for the sequence of the Depth First Search
     visits and edges traversed.
 - cycle: boolean output parameter that results in true if a cycle exists.
     Should be set to false on the call.
*/
template <class T, class W>
void CycleDFS(WGraph<T, W> &G, vector<int> &num, vector<T> &vlist, int pos,
              int &count, vector<pair<T, T>> &Edges, bool &cycle) {
  vector<pair<T, W>> Adj = G.getAdjacentList(vlist[pos]);
  num[pos] = count++;

  for (size_t i = 0; i < Adj.size(); i++) {
    T vert = Adj[i].first;

    size_t vPos = find(vlist.begin(), vlist.end(), vert) - vlist.begin();
    if (vPos < vlist.size() && num[vPos] == 0) {
      Edges.push_back({vlist[pos], vert});
      CycleDFS(G, num, vlist, vPos, count, Edges, cycle);
    } else if (find(Edges.begin(), Edges.end(), make_pair(vert, vlist[pos])) ==
               Edges.end()) {
      cycle = true;
      return;
    }
  }
}
/*
Connected algorithm for our graph class.  Simply calls the DFS recursive
helper function.  If the recursion visits all the nodes then the count
will be the graph size + 1.  Otherwise the graph is not connected.

Parameter: WGraph G.

Notes: If the graph is directed this will check strong connectedness.
 */
template <class T, class W> bool connected(WGraph<T, W> &G) {
  vector<T> vlist = G.getVertexList();
  vector<int> num(vlist.size());
  int count = 1;
  ConnDFS(G, num, vlist, 0, count);
  return (static_cast<size_t>(count) == G.getVertexList().size() + 1);
}

/*
ConnDFS recursive helper function for the connected algorithm.

Parameters:
 - WGraph G
 - num: vector of integer counts to track visitation
 - vlist: vector of vertex names, used to determine positions of the
     vector/edge data in the graph.
 - pos: position of the vertex being processed/visited by the algorithm.
 - count: The current visit count.
 */
template <class T, class W>
void ConnDFS(WGraph<T, W> &G, vector<int> &num, vector<T> &vlist, int pos,
             int &count) {
  vector<pair<T, W>> Adj = G.getAdjacentList(vlist[pos]);
  num[pos] = count++;

  for (size_t i = 0; i < Adj.size(); i++) {
    T vert = Adj[i].first;
    size_t vPos = find(vlist.begin(), vlist.end(), vert) - vlist.begin();
    if (vPos < vlist.size() && num[vPos] == 0)
      ConnDFS(G, num, vlist, vPos, count);
  }
}
