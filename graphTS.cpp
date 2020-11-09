
//	TREE SEARCH IN GRAPHS
//  - BFS method
//  - DFS method
//  - Dijkstra (without weights) method
//
#include "graph.h"
//
//  Breadth First Search: returns components/trees number
//
component
BFS( graph &G )
{
    vertex vn = G.size();
    component Tn = 0;
    //  Vertices list
    vector<vertex> BFSv( vn );
    //  Label vertices as unvisited
    vector<bool> BFSl( vn, false );
    //  List index
    indice BFSn = 0;
    //  Find non labeled vertex as root vertex rv of new component/tree Tn
    for( vertex rv=0; rv<vn; rv++ )
        if( !BFSl[rv] ) {
            //  Actualize display index
            indice BFSi = BFSn;
            //  New root rv found for new component
            Tn++;
            //  Label and list rv
            vertex v = rv;
            BFSl[rv] = true;
            BFSv[BFSn++] = rv;
            if( G[v].size() )
                do {
                    //  New vertex v to display
                    vertex v = BFSv[BFSi++];
                    for( indice i=0; i<G[v].size(); i++ )
                        if( !BFSl[G[v][i]] ) {
                            //  Label and list adjacent G[v][i]
                            BFSl[G[v][i]] = true;
                            BFSv[BFSn++] = G[v][i];
                        }
                } while( BFSi < BFSn );
        }
    return Tn;
}
//
//  Per l'exercici 9, canviem el nom d'aquesta funcio per BFS_Trees i el modifiquem.
//
void
BFS_Trees( graph &G, ofstream& fout )
{
    vertex vn = G.size();
    component Tn = 0;
    vector<vertex> BFSv (vn); //Quan declarem el vector el tenim ple de 0's
    //  Declarem identificador, profunditat (depth) i pares dels vertexs
    vector<indice> BFSind (vn);
    vector<length> BFSd (vn);
    vector<vertex> BFSp (vn,vn);
    indice BFSn = 0;
    for( vertex rv=0; rv<vn; rv++ )
        if( BFSp[rv]==vn ) {
            //Trobem nova arrel (nou component)
            Tn++;
            indice BFSi = BFSn;
            BFSv[BFSn] = rv;
            BFSind[rv] = BFSn++;
            BFSd[rv]=0; //La profunditat d'una arrel sempre és 0
            BFSp[rv]=rv; //El "pare" d'una arrel sempre és ella mateixa
            if( G[rv].size() )
                do {
                    vertex v = BFSv[BFSi];
                    BFSi++;
                    for( indice i=0; i < G[v].size(); i++)//Entro a la llista d'adjacència de l'arrel
                        if( BFSp[G[v][i]] == vn ) {
                            BFSv[BFSn] = G[v][i];
                            BFSind[G[v][i]] = BFSn++;
                            BFSd[G[v][i]] = BFSd[v]+1;
                            BFSp[G[v][i]] = v;
                        }
                } while(BFSi < BFSn);
        }
            // Escrivim els vertex en l'ordre que ens indica el mètode BFS, l'índex en el recorregut, l'indentificador, i el nivell repecte l'arrel
            fout << "Vertexs: ";
            for( vertex v=0; v<vn; v++ )
                fout << v << " ";
            fout<<endl;
            fout << "Índex en el recorregut: ";
            for( vertex v=0; v<vn; v++ )
                fout << BFSind[v] << " ";
            fout<<endl;
            fout << "Identificador del predecessor: ";
            for( vertex v=0; v<vn; v++ )
                fout << BFSp[v] << " ";
            fout<<endl;
            fout << "Nivell respecte l'arrel: " ;
            for( vertex v=0; v<vn; v++ )
                fout << BFSd[v] << " ";
            fout <<endl;
            //Escrivim les arestes, els identificadors i si són o no arbres minimals
            for( vertex v=0; v<vn; v++ ){
                for( indice i=0; i<G[v].size(); i++ ){
                    if(v <= G[v][i]) {
                        fout << "L'aresta " << v << "->" << G[v][i];
                        fout << ", amb identificadors ";
                        fout << BFSind[v] << "->" << BFSind[G[v][i]];
                        if( BFSp[G[v][i]] == v || BFSp[v] == G[v][i])
                            fout<<", pertany als arbres expansius. "<< endl;
                        else
                            fout<<", no pertany als arbres expansius. "<<endl;
                    }
                }
             }
            fout <<endl;
            fout << "Hi ha " << Tn << " arrels." <<endl;
}

//
//  Recursive function for Depth First Search from v
//
 void 
    DFS( graph &G, vector<bool> &DFSl,  vertex v ) 
{
	for( indice i=0; i<G[v].size(); i++ )
        if( !DFSl[G[v][i]] ) {
		//  Label adjacent vertex as visited
            DFSl[G[v][i]] = true;
		//  DFS recursive for non visited adjacent vertices   
            DFS( G, DFSl, G[v][i] );
        }
}
//
//  Depth First Search: returns components/trees number
//
component
DFS(  graph &G )
{
    vertex vn = G.size();
    //  Initialize number of components/trees to 0
    component Tn = 0;
    //  Label vertices as unvisited
    vector<bool> DFSl( vn, false );
    for( vertex rv=0; rv<vn; rv++)
        if( !DFSl[rv] ){
            //  New root found
            //  Count new component
            Tn++;
            //  Label root vertex
            DFSl[rv] = true;
            //  Display component
            DFS( G, DFSl, rv );
        }
    return Tn;
}
//
//  Ampliem la funció DFS per l'exercici 9
//
 component 
    DFS_Trees(  graph &G, ofstream& fout)
{
    vertex vn = G.size();
    //El nombre d'arbres=0
    component Tn = 0;
    //Declarem identificador, profunditat (depth) i pares dels vertexs
    vector<indice> DFSind (vn);
    vector<length> DFSd (vn);
    vector<vertex> DFSp (vn,vn);
    indice DFSn=0;//Ens serveix de comptador pels vertexs
    for( vertex rv=0; rv<vn; rv++) //reviso tots els vertexs
         if( DFSp[rv]==vn ){
		 //  Nova arrel, i per tant incrementem Tn
			 Tn++;
		 //  El pare d'una arrel es ella mateixa
			 DFSp[rv] = rv;
             DFSd[rv] = 0;
             DFSind[rv] = DFSn;
             DFS_Trees( G, rv, DFSn, DFSp, DFSind, DFSd);
         }
    // Escrivim els vertex en l'ordre que ens indica el mètode BFS, l'índex en el recorregut, l'indentificador, i el nivell repecte l'arrel
    fout << "Vertexs: ";
    for( vertex v=0; v<vn; v++ )
        fout << v << " ";
    fout<<endl;
    fout << "Índex en el recorregut: ";
    for( vertex v=0; v<vn; v++ )
        fout << DFSind[v] << " ";
    fout<<endl;
    fout << "Identificador del predecessor: ";
    for( vertex v=0; v<vn; v++ )
        fout << DFSp[v] << " ";
    fout<<endl;
    fout << "Nivell respecte l'arrel: " ;
    for( vertex v=0; v<vn; v++ )
        fout << DFSd[v] << " ";
    fout <<endl;
    //Escrivim les arestes, els identificadors i si són o no arbres minimals
    for( vertex v=0; v<vn; v++ ){
        for( indice i=0; i<G[v].size(); i++ ){
            if(v <= G[v][i]) {
                fout << "L'aresta " << v << "->" << G[v][i];
                fout << ", amb identificadors ";
                fout << DFSind[v] << "->" << DFSind[G[v][i]];
                if( DFSp[G[v][i]] == v || DFSp[v] == G[v][i])
                    fout<<", pertany als arbres expansius. "<< endl;
                else
                    fout<<", no pertany als arbres expansius. "<<endl;
            }
        }
    }
    fout <<endl;
    fout << "Hi ha " <<Tn << " arrels." <<endl;
    return Tn;
}
//
//Funció recursiva de DFS_Trees
//
void
DFS_Trees( graph &G, vertex rv, indice &DFSn, vector<indice> &DFSp, vector<vertex> &DFSind, vector<length> &DFSd )
{
    vertex vn = G.size();
    for( indice i=0; i<G[rv].size(); i++ )
        if( DFSp[G[rv][i]] == vn ) {
            DFSp[G[rv][i]] = rv;//El pare de qualsevol vertex que pertany a la llista d'adjacència de l'arrel és la mateixa arrel.
            DFSn++;
            DFSind[G[rv][i]] = DFSn;
            DFSd[G[rv][i]] = DFSd[rv]+1;
            //  Tornem a aplicar recursivitat per tota la llista d'adjacència de l'arrel
            DFS_Trees( G, G[rv][i], DFSn, DFSp, DFSind, DFSd );
        }
}
//
//  Minimal path lengths by Dijkstra's method to stream
//  - Distances to all vertices: lengths of minimal paths
//
 void
    Dijkstra(  graph &G,  vertex sv, ofstream& fout )
{
    vertex vn = G.size();
//  Inialize vertices as unlabeled
    vector<bool> Dl( vn, false );
//  Infinity for lengths
	length infty = UINT_MAX;
//  Inialitize distance to sv to infty for all vertices but sv
	vector<length> Dd( vn, infty );
	Dd[sv]=0;
//  Vertex mdv with minimum distance to starting vertex sv: sv
	vertex mdv = sv; 
	do {
	//  Label mdv and check distance from sv to its adjacents	
		Dl[mdv] = true;
		for( indice i=0; i<G[mdv].size(); i++ )
			if( Dd[G[mdv][i]] > Dd[mdv]+1 )	
				Dd[G[mdv][i]] = Dd[mdv]+1; 
	//  Find new not labeled vertex mdv with minimum distance to sv
		length md = infty;
		mdv = vn;
		for( vertex v=0; v<vn; v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv<vn );
    fout << "\nDistàncies des del vertex inicial " << sv << endl;
    for( vertex v=0; v<vn; v++ ){
        if( Dd[v]<infty )
		    fout << v << "\t" << Dd[v]  << endl;
        else
            fout << v << "\tNo connectat" << endl;
    }
}
