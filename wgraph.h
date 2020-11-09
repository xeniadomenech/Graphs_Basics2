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
 typedef unsigned int weight;
 typedef vector<vector<pair<vertex,weight>> > wgraph;
 wgraph wgraph_complete( indice n,  weight Mw );
 wgraph wgraph_cycle( indice n,  weight Mw );
 wgraph wgraph_star( indice n,  weight Mw );
 wgraph wgraph_wheel( indice n,  weight Mw );
 wgraph wgraph_bipartit( indice n1, indice n2,  weight Mw );
 wgraph wgraph_read( string fname );
 void wgraph_write(  wgraph& G, ofstream& fout );
 void DijkstraP1(  wgraph &G, vertex sv, vertex fv, ofstream& fout );
 component DijkstraP2(  wgraph &G, vertex sv);
 void DijkstraP3(  wgraph &G, ofstream& fout );
 void DijkstraP4(  wgraph &G, vertex sv, ofstream& fout );
 void DijkstraP5(  wgraph &G, vertex sv, ofstream& fout );
 weight Kruskal (wgraph &G, ofstream &fout);
 weight Prim (wgraph &G, ofstream &fout);
 
