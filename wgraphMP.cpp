#include "wgraph.h"
//EXERCICI 11
//(PUNT 1) Distància entre dos vertex.
void
DijkstraP1(  wgraph &G,  vertex sv, vertex fv, ofstream& fout )
{
    vertex vn = G.size();
    //  Inialize vertices as unlabeled
    vector<bool> Dl( vn, false );
    //  Infinity for lengths
    weight infty = UINT_MAX;
    //  Inialitize distance to sv to infty for all vertices but sv
    vector<weight> Dd( vn, infty );
    Dd[sv]=0;
    //  Vertex mdv with minimum distance to starting vertex sv: sv
    vertex mdv = sv;
    do {
        //  Label mdv and check distance from sv to its adjacents
        Dl[mdv] = true;
        for( indice i=0; i<G[mdv].size(); i++ )
            if( Dd[G[mdv][i].first] > Dd[mdv]+ G[mdv][i].second )
                Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second;
        //  Find new not labeled vertex mdv with minimum distance to sv
        weight md = infty;
        mdv = vn;
        for( vertex v=0; v<vn; v++ ){
            if( md > Dd[v] && !Dl[v] ) {
                md = Dd[v];
                mdv = v;
            }
        }
    } while( mdv<vn  && Dd[fv]!=false);
    fout << "La distància de " << sv << " a " << fv << " es de: " << Dd[fv] <<endl;
}
//(PUNT 2) Distància màxima entre un vertex i tots els altres
component
DijkstraP2(  wgraph &G,  vertex sv)
{
    vertex vn = G.size();
    vector<bool> Dl( vn, false );
    weight infty = UINT_MAX;
    vector<weight> Dd( vn, infty );
    Dd[sv]=0;
    vertex mdv = sv;
    weight maxim;
    do {
        Dl[mdv] = true;
        for( indice i=0; i<G[mdv].size(); i++ )
            if( Dd[G[mdv][i].first] > Dd[mdv]+ G[mdv][i].second )
                Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second;
        weight md = infty;
        mdv = vn;
        for( vertex v=0; v<vn; v++ ){
            if( md > Dd[v] && !Dl[v] ) {
                md = Dd[v];
                mdv = v;
            }
        }
    } while( mdv<vn );
    maxim=Dd[0];
    for(vertex v=1; v<vn; v++){
        if(Dd[v] > maxim)
            maxim=Dd[v];
        if(Dd[v]==infty)
            v=vn;
    }
    return maxim;
}
//(PUNT 3) Diametre
void DijkstraP3 (wgraph &G, ofstream& fout){
    vertex vn=G.size();
    weight diametre=DijkstraP2(G, 0);
    for(indice i=1; i<vn; i++){
        if(DijkstraP2(G, i) > diametre)
            diametre=DijkstraP2(G, i);
    }
    fout << "El diametre és: " << diametre <<endl;
    
}
//(PUNT 4) Distància d'un vertex donat a tots els altres
void
DijkstraP4(  wgraph &G,  vertex sv, ofstream& fout )
{
    vertex vn = G.size();
    //  Inialize vertices as unlabeled
    vector<bool> Dl( vn, false );
    //  Infinity for lengths
    weight infty = UINT_MAX;
    //  Inialitize distance to sv to infty for all vertices but sv
    vector<weight> Dd( vn, infty );
    Dd[sv]=0;
    //  Vertex mdv with minimum distance to starting vertex sv: sv
    vertex mdv = sv;
    do {
        //  Label mdv and check distance from sv to its adjacents
        Dl[mdv] = true;
        for( indice i=0; i<G[mdv].size(); i++ )
            if( Dd[G[mdv][i].first] > Dd[mdv]+ G[mdv][i].second )
                Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second;
        //  Find new not labeled vertex mdv with minimum distance to sv
        weight md = infty;
        mdv = vn;
        for( vertex v=0; v<vn; v++ ){
            if( md > Dd[v] && !Dl[v] ) {
                md = Dd[v];
                mdv = v;
            }
        }
    } while( mdv<vn );
    fout << "Distàncies des del vertex inicial " << sv << endl;
     for( vertex v=0; v<vn; v++ ){
        if( Dd[v]<infty )
            fout << v << " : " << Dd[v]  << endl;
        else
            fout << v << " no està connectat." << endl;
     }
}
//(PUNT 5) l'arbre de camins minimals trobat des d'un vertex donat i els camins des de tots els vertexs accessibles a ell.
void
DijkstraP5(  wgraph &G, vertex sv, ofstream& fout )
{
    vertex vn = G.size();
    vector<vertex> Dp(vn,vn);
    vector<bool> Dl( vn, false );
    weight infty = UINT_MAX;
    vector<weight> Dd( vn, infty );
    Dd[sv]=0;
    Dp[sv]=sv; //El pare d'una arrel és ell mateix
    vertex mdv = sv;
    do {
        Dl[mdv] = true;
        for( indice i=0; i<G[mdv].size(); i++ )
            if( Dd[G[mdv][i].first] > Dd[mdv]+ G[mdv][i].second ){
                Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second;
                Dp[G[mdv][i].first] = mdv;
            }
        weight md = infty;
        mdv = vn;
        for( vertex v=0; v<vn; v++ ){
            if( md > Dd[v] && !Dl[v] ) {
                md = Dd[v];
                mdv = v;
            }
        }
    } while( mdv<vn );
    fout << "Minimal path des del vertex " << sv << " al vertex:" << endl;
    for(vertex v=0; v<vn; v++){
        if(v!=sv && Dd[v]<infty){
            fout << v << ": " << v << " <- ";
            vertex pv = Dp[v];
            while(pv!=sv){
                fout << pv << " <- ";
                vertex ppv= pv;
                pv=Dp[ppv];
            }
            fout << sv <<endl;
        }
    }
}

