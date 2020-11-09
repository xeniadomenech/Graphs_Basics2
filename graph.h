#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 using namespace std;
 typedef unsigned int vertex;
 typedef unsigned int edge;
 typedef unsigned int indice;
 typedef unsigned int degree;
 typedef unsigned int component;
 typedef unsigned int length;
 typedef vector<vector<vertex> > graph;
 graph graph_complete( indice n );
 graph graph_cycle( indice n );
 graph graph_star( indice n );
 graph graph_wheel( indice n );
 graph graph_bipartit( indice n1, indice n2 );
 graph graph_king(indice n1, indice n2);
 graph graph_rook(indice n1, indice n2);
 graph graph_bishop(indice n1, indice n2);
 graph graph_knight(indice n1, indice n2);
 void DijkstraExercici10(  graph &G, indice n1, indice n2, vertex s1, vertex s2, ofstream& fout );
 void graucaselles (graph &G,indice n1, indice n2, ofstream &fout);
 void BFS_Trees( graph &G, ofstream &fout );
 void DFS_Trees( graph &G, vertex rv, indice &DFSn, vector<indice> &DFSp, vector<vertex> &DFSind, vector<length> &DFSd );
 component DFS_Trees(  graph &G, ofstream& fout);
 graph graph_read( string fname );
 void graph_write(  graph& G, ofstream& fout );
 component BFS( graph &G );
 component DFS( graph &G );
 void Dijkstra( graph &G, vertex sv, ofstream& fout );
