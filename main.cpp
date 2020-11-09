#include <ctime>
#include "graph.h"
#include "wgraph.h"

int
main()
{
    ofstream fout;
    //  Seed rand()
    srand( (unsigned int) time( NULL ) ) ;
    indice maxim; //Per el punt 4 de l'exercici 11
    weight p,k; //Per l'exercici 14 (Pràctica 3)
    //
    //EXERCICI 8 i 9
    //
    //PRIMER PUNT
    //
    //K8
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/K8.out" );
    graph K8 = graph_complete( 8 );
    graph_write( K8, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( K8, fout);
    fout<<endl;
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( K8, fout);
    fout<<endl;
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( K8, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( K8, 0, fout );
    fout.close();
    //
    //K5_3 I K3_5
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/K5_3.out" );
    graph K5_3 = graph_bipartit(5, 3);
    fout << "Graf K5_3" <<endl;
    fout << endl;
    graph_write( K5_3, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( K5_3, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( K5_3, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( K5_3, 0, fout );
    graph K3_5 = graph_bipartit(3, 5);
    fout << "Graf K3_5" <<endl;
    graph_write( K3_5, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( K3_5, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( K3_5, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( K3_5, 0, fout );
    fout.close();
    //
    //S8
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/S8.out" );
    graph S8 = graph_star( 8 );
    graph_write( S8, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( S8, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( S8, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( S8, 0, fout );
    fout.close();
    //
    //C8
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/C8.out" );
    graph C8 = graph_cycle( 8 );
    graph_write( C8, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( C8, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( C8, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( C8, 0, fout );
    fout.close();
    //
    //W8
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/W8.out" );
    graph W8 = graph_wheel( 8 );
    graph_write( W8, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( W8, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( W8, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( W8, 0, fout );
    fout.close();
    //
    //SEGON PUNT
    //
    //graph0.in
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/graph0.out" );
    graph G0 = graph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/graph0.in");
    graph_write( G0, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( G0, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( G0, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( G0, 0, fout );
    fout.close();
    //
    //graph1.in
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/graph1.out" );
    graph G1 = graph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/graph1.in");
    graph_write( G1, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( G1, fout);
    fout  << "Dijkstra: "  <<endl;
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( G1, fout);
    Dijkstra( G1, 0, fout );
    fout.close();
    //
    //graph2.in
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/graph2.out" );
    graph G2 = graph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/graph2.in");
    graph_write( G2, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( G2, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( G2, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( G2, 0, fout );
    fout.close();
    //
    //graph3.in
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/graph3.out" );
    graph G3 = graph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/graph3.in");
    graph_write( G3, fout );
    fout  << "Mètode BFS: "  <<endl;
    BFS_Trees( G3, fout);
    fout  << "Mètode DFS: "  <<endl;
    DFS_Trees( G3, fout);
    fout  << "Dijkstra: "  <<endl;
    Dijkstra( G3, 0, fout );
    fout.close();
    //
    //TERCER PUNT (Utilitzo 50 com a mw)
    //
    //WK5_3 I WK3_5
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/WK5_3.out" );
    wgraph WK5_3 = wgraph_bipartit(5, 3, 50);
    fout << "Graf WK5_3" <<endl;
    fout << endl;
    wgraph_write( WK5_3, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WK5_3, 0, 7, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WK5_3, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WK5_3, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WK5_3, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WK5_3, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WK5_3, fout);
    p = Prim(WK5_3, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    wgraph WK3_5 = wgraph_bipartit(3, 5, 50);
    fout << "Graf WK3_5" <<endl;
    wgraph_write( WK3_5, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WK3_5, 0, 7, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WK3_5, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WK3_5, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WK3_5, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WK3_5, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WK3_5, fout);
    p = Prim(WK3_5, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //WS8
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/WS8.out" );
    wgraph WS8 = wgraph_star( 8, 50 );
    wgraph_write( WS8, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WS8, 0, 7, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WS8, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WS8, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WS8, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WS8, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WS8, fout);
    p = Prim(WS8, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //WC8
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/WC8.out" );
    wgraph WC8 = wgraph_cycle( 8, 50 );
    wgraph_write( WC8, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WC8, 0, 7, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WC8, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WC8, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WC8, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WC8, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WC8, fout);
    p = Prim(WC8, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //WW8
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/WW8.out" );
    wgraph WW8 = wgraph_wheel( 8, 50 );
    wgraph_write( WW8, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WW8, 0, 6, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WW8, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WW8, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WW8, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WW8, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WW8, fout);
    p = Prim(WW8, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //QUART PUNT
    //
    //graph1.in
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/wgraph1.out" );
    wgraph WG1 = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/wgraph1.in");
    wgraph_write( WG1, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WG1, 0, 3, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WG1, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WG1, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WG1, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WG1, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WG1, fout);
    p = Prim(WG1, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //graph2.in
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/wgraph2.out" );
    wgraph WG2 = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/wgraph2.in");
    wgraph_write( WG2, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WG2, 0, 4, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WG2, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WG2, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WG2, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WG2, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WG2, fout);
    p = Prim(WG2, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //graph3.in
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/wgraph3.out" );
    wgraph WG3 = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/wgraph3.in");
    wgraph_write( WG3, fout );
    //Exercici 11
    fout << endl << "PUNT 1 " <<endl;
    DijkstraP1(WG3, 0, 9, fout);
    fout << endl << "PUNT 2 " <<endl;
    maxim = DijkstraP2(WG3, 0);
    fout << "La distància màxima de 0 a qualsevol vertex és de: " << maxim <<endl;
    fout << endl << "PUNT 3 " <<endl;
    DijkstraP3(WG3, fout);
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(WG3, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(WG3, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(WG3, fout);
    p = Prim(WG3, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //EXERCICI 10
    //
    //King
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/Kg6_6.out" );
    graph Kg6_6= graph_king(6,6);
    graph_write( Kg6_6, fout );
    fout << "Nombre mínim de salts" <<endl;
    DijkstraExercici10(Kg6_6, 6, 6, 1, 4, fout);
    fout <<endl <<endl;
    fout << "Graus de les caselles" <<endl;
    graucaselles (Kg6_6, 6, 6,fout);
    fout.close();
    //
    //Rook
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/Rk6_6.out" );
    graph Rk6_6= graph_rook(6,6);
    graph_write( Rk6_6, fout );
    fout << "Nombre mínim de salts" <<endl;
    DijkstraExercici10(Rk6_6, 6, 6, 1, 4, fout);
    fout <<endl <<endl;
    fout << "Graus de les caselles" <<endl;
    graucaselles (Rk6_6, 6, 6,fout);
    fout.close();
    //
    //Bishop
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/Bs6_6.out" );
    graph Bs6_6= graph_bishop(6,6);
    graph_write( Bs6_6, fout );
    fout << "Nombre mínim de salts" <<endl;
    DijkstraExercici10(Bs6_6, 6, 6, 1, 4, fout);
    fout <<endl <<endl;
    fout << "Graus de les caselles" <<endl;
    graucaselles (Bs6_6, 6, 6,fout);
    fout.close();
    //
    //Knight
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/Kn6_6.out" );
    graph Kn6_6= graph_knight(6,6);
    graph_write( Kn6_6, fout );
    fout << "Nombre mínim de salts" <<endl;
    DijkstraExercici10(Kn6_6, 6, 6, 1, 4, fout);
    fout <<endl <<endl;
    fout << "Graus de les caselles" <<endl;
    graucaselles (Kn6_6, 6, 6,fout);
    fout.close();
    //
    //EXERCICI 12 (El vertex 'a' es el vertex 0)
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/Exercici12.out" );
    wgraph E12 = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/Exercici12.in");
    wgraph_write( E12, fout );
    fout << endl << "PUNT 4 " <<endl;
    DijkstraP4(E12, 0, fout);
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(E12, 0, fout);
    fout <<endl;
    fout.close();
    //
    //EXERCICI 13
    //
    //Dodecàedre
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/Dodecaedre.out" );
    wgraph DD = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/Dodecaedre.in");
    wgraph_write( DD, fout );
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(DD, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(DD, fout);
    p = Prim(DD, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //Icosàedre
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/Icosaedre.out" );
    wgraph IC = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/Icosaedre.in");
    wgraph_write( IC, fout );
    fout << endl << "PUNT 5 " <<endl;
    DijkstraP5(IC, 0, fout);
    fout <<endl;
    //PRÀCTICA 3
    k = Kruskal(IC, fout);
    p = Prim(IC, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //PRÀCTICA 3
    //
    //
    //EXERCICI 15
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/cities1.out" );
    wgraph C1 = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/cities1.in");
    wgraph_write(C1, fout);
    k = Kruskal(C1, fout);
    p = Prim(C1, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //EXERCICI 16
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Sortides/cities2.out" );
    wgraph C2 = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc2_DomenechXenia.cpp/Entrades/cities2.in");
    wgraph_write(C2, fout);
    k = Kruskal(C2, fout);
    p = Prim(C2, fout);
    fout << "SOLUCIÓ KRUSCAL: "<< k <<endl;
    fout << "SOLUCIÓ PRIM: " << p <<endl;
    fout.close();
    //
    //  Ending
    //
    cout << "Press enter to finish..." << endl;
    cin.get();
}

