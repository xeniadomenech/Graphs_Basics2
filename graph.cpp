#include "graph.h"
//
//  Complete graph with vn vertices to adjacencies lists (graph)
//
graph
graph_complete( indice n )
{
    vertex vn = n;
    graph Kn( vn );
    for( vertex v=0; v<vn; v++)
        for( vertex u=v+1; u<vn; u++ ) {
            Kn[v].push_back( u );
            Kn[u].push_back( v );
        }
    return Kn;
}
//
//Cycle
//
graph
graph_cycle( indice n )
{
    vertex vn = n;
    graph Cn( vn );
    for( vertex v=0; v<vn-1; v++){
        Cn[v].push_back( v+1 );
        Cn[v+1].push_back( v );
    }
    Cn[vn-1].push_back( 0 );
    Cn[0].push_back( vn-1 );
    return Cn;
}
//
//Star
//
graph
graph_star( indice n )
{
    vertex vn = n;
    graph Sn( vn );
    for( vertex v=0; v<vn-1; v++){
        Sn[v].push_back( vn-1 );
        Sn[vn-1].push_back( v );
    }
    return Sn;
}
//
//Wheel (unió de cycle i star)
//
graph
graph_wheel( indice n )
{
    vertex vn = n;
    graph Wn( vn );
    for( vertex v=0; v<vn-1; v++){
        Wn[v].push_back( v+1 );
        Wn[v].push_back( vn-1 );
        Wn[v+1].push_back( v );
        Wn[vn-1].push_back( v );
    }
    Wn[vn-1].push_back( vn-2 );
    Wn[0].push_back( vn-2 );
    Wn[vn-2].push_back( vn-1 );
    Wn[vn-2].push_back( 0 );
    return Wn;
}
//
//Bipartit complet
//
graph
graph_bipartit( indice n1, indice n2 )
{
    vertex vn = n1 + n2;
    graph Bn(vn);
    for(vertex v=0; v<n1; v++){
        for(vertex u=n1; u<vn; u++){
            Bn[v].push_back(u);
            Bn[u].push_back(v);
        }
    }
    return Bn;
}
//
//
//  Read from file fname of edges to adjacencies lists (graph)
//
graph
graph_read( string fname )
{
    ifstream fin;
    fin.open( fname.c_str() );
    if( fin.fail() ) {
        cerr << "No s'ha pogut obrir " << fname.c_str() << " per la llectura." << endl;
        exit( 1 );
    }
    vertex vn;
    edge en;
    fin >> vn >> en;
    graph G( vn );
    for( edge e=0; e<en; e++ ) {
        vertex v, u;
        fin >> v >> u;
        G[v].push_back(u);
        if( u != v )
            G[u].push_back(v);
    }
    return G;
}
//
//  Write from adjacencies lists (graph) to stream
//  - vertices and edges numbers
//  - edges
void
graph_write(  graph& G, ofstream& fout )
{
    //  Vertices number
    vertex vn = G.size();
    //  Count edges number from adjacencies lists
    //  PLEASE CORRECT WHEN THERE ARE LOOPS(CREC QUE JA ESTÀ REVISAT)
    edge en = 0;
    for( vertex v = 0; v < vn; v++ )
        for( indice i = 0; i < G[v].size(); i++ )
            if( v <= G[v][i] )
                en++;
    //  Write edges
    fout << "Graf amb " << vn << " vertex i " << en << " arestes " << endl;
    fout << "Llista d'adjacència " << endl;
    for( vertex v=0; v<vn; v++ )  {
        fout << v << "\t:";
        for( indice i=0; i<G[v].size(); i++)
            fout << "\t" << G[v][i];
        fout << endl;
    }
    fout << "Arestes" << endl;
    for( vertex v = 0; v < vn; v++ )
        for( indice i = 0; i < G[v].size(); i++ )
            if( v <= G[v][i] )
                fout << v << "-" << G[v][i] << endl;
}
//
// REI
//
graph
graph_king(indice n1, indice n2)
{
    graph Kg ( n1*n2 );
    for( indice i1=0; i1<n1; i1++){
        for( indice i2=0; i2<n2; i2++){
            vertex v = i1*n2+i2;
            if(i2 < n2-1){
                Kg[v].push_back(v+1);
                Kg[v+1].push_back(v);
            }
            if(i1 < n1-1){
                Kg[v].push_back(v+n2);
                Kg[v+n2].push_back(v);
            }if (i1 < n1-1 && i2 < n2-1) {
                Kg[v].push_back(v+n2+1);
                Kg[v+n2+1].push_back(v);
            }
            if (i1 < n1 - 1 && i2>0) {
                Kg[v].push_back(v+n2-1);
                Kg[v+n2-1].push_back(v);
            }
        }
    }
    return Kg;
}
//
//TORRE
//
graph
graph_rook(indice n1, indice n2)
{
    graph Rk ( n1*n2 );
    for (indice i1 = 0; i1 < n1; i1++) {
        for (indice i2 = 0; i2 < n2; i2++) {
            vertex v = i1*n2 + i2;
                for(indice k=1; i2+k < n2; k++){
                    Rk[v].push_back(v+k);
                    Rk[v+k].push_back(v);
                }
                for(indice k=1; i1+k < n1; k++){
                    Rk[v].push_back(v + k*n2);
                    Rk[v + k*n2].push_back(v);
                }
        }
    }
    return Rk;
}
//
//ALFIL
//
graph
graph_bishop (indice n1, indice n2)
{
    graph Bp(n1*n2);
    for (indice i1 = 0; i1 < n1; i1++) {
        for (indice i2 = 0; i2 < n2; i2++){
            vertex v = i1*n2 + i2;
                for (indice k=1; i2+k < n2 && i1+k < n1; k++){
                    Bp[v].push_back(v+k*(n2+1));
                    Bp[v+k*(n2+1)].push_back(v);
                }
                for(indice k=1; i1+k < n1 && i2 >= k; k++){
                    Bp[v].push_back(v+k*(n2-1));
                    Bp[v+k*(n2-1)].push_back(v);
                }
        }
    }
    return Bp;
}
//
//CAVALL
//
graph
graph_knight(indice n1, indice n2)
{
    graph Kn(n1*n2);
    for (indice i1 = 0; i1 < n1; i1++) {
        for (indice i2 = 0; i2 < n2; i2++) {
            vertex v = i1*n2 + i2;
            //En aquest if faig el moviment del cavall quan avança 2 horitzontalment
            if(i1 < n1-1){
                //I un verticalment
                if(i2 < n2-2){
                    Kn[v].push_back((i1+1)*n2 + (i2+2));
                    Kn[(i1+1)*n2 + (i2+2)].push_back(v);
                }
                //I avança un verticalment
                if(i2 > 1){
                    Kn[v].push_back((i1+1)*n2 + (i2-2));
                    Kn[(i1+1)*n2 + (i2-2)].push_back(v);
                }
            }
            //En aquest if faig els moviment del cavall quan avança 2 verticalment
            if(i1 < n1-2){
                //I avança un horitzontalment
                if(i2 < n2-1){
                    Kn[v].push_back((i1+2)*n2 + (i2+1));
                    Kn[(i1+2)*n2 + (i2+1)].push_back(v);
                }
                //I retrocedeix un horitzontalment
                if(i2 > 0){
                    Kn[v].push_back((i1+2)*n2 + (i2-1));
                    Kn[(i1+2)*n2 + (i2-1)].push_back(v);
                }
            }
        }
    }
    return Kn;
}
//
//Trobem el mínim camí a cada vertex des d'un vertex donat
//
void
DijkstraExercici10(  graph &G, indice n1, indice n2, vertex s1, vertex s2, ofstream& fout )
{
    vertex vn = G.size();
    vertex sv= s1*n2+s2;
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
            if( md > Dd[v] && Dl[v]==false ) {
                md = Dd[v];
                mdv = v;
            }
    } while( mdv<vn );
    for( vertex v=0; v<vn; v++ ){
        if(v%n2==0)
            fout<<endl;
        if( Dd[v]<infty )
            fout << Dd[v] << " ";
        //Com hi ha algunes figures que mai arriben a certes caselles, com és el cas de l'alfil, els senyalem amb el símbol 'X'
        else
            fout<< "X ";
    }
}
//
//Trobem el grau de cada vertex del graf
//
void
graucaselles (graph &G,indice n1, indice n2, ofstream &fout){
    vertex vn=G.size();
    vector<vertex> grau( vn, 0 );
    for(indice v=0; v<vn; v++){
        //Guardem la seva dimensió de cada vertex en grau[v].
        grau[v] = G[v].size();
        if(v%n2==0)
            fout<<endl;
        fout << grau[v] << " ";
    }
}
