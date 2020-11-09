//
#include "wgraph.h"
//
weight Kruskal (wgraph &G, ofstream &fout){
    vertex vn=G.size();
    weight infty=UINT_MAX;
    weight TW=0;
    vector<weight> Kw (vn,0);
    vector<component> Kc(vn);
    weight mw;
    vertex mv=0;
    indice mvi=0;//mv i mvi son els extrems dels vertex
    indice mkc;
    indice Mkc;
    for(vertex v=0; v<vn; v++)
        Kc[v]=v;
    do{
        mw=infty;
        //DETERMINO LA MÍNIMA ARESTA
        for(vertex v=0; v<vn; v++)
            for(indice i=0; i<G[v].size(); i++)
                if(Kc[v]!=Kc[G[v][i].first] && mw > G[v][i].second){//Mira si les components connexes siguin diferents--> NO CICLE && optimitzem
                    mw=G[v][i].second;
                    mv=v;
                    mvi=i;
                }
        if(mw==infty)//Surt quan no hi ha més arestes
            break;
        TW+=mw;
        vertex mva=G[mv][mvi].first;
        mkc=min(Kc[mv], Kc[mva]);
        Mkc=max(Kc[mv], Kc[mva]);
        for(vertex v=0; v<vn; v++)
            if(Kc[v]==Mkc)
                Kc[v]=mkc;
        Kw[mkc]+= Kw[Mkc]+ mw;
        fout << "Aresta de Kruskal " << mv << " -> " << G[mv][mvi].first << " (" << mvi << ") "<< "Pes "<< mw << endl;
    }while(true);//mentres mw no canvïi
    fout << "Pes de cada arbre: " << endl;
    for( vertex v=0; v<vn; v++)
        if(Kc[v]==v)
            fout << "\tArbre " << v << ": " << Kw[v]<< endl;
    return TW;
}
//Prim: trobem l'aresta de menor pes i trobem les fulles.
//mva=G[mv][mvi].first(vertex amb menor pes)
//Pp[mv]=mv i Pp[mva]=mv;

weight Prim (wgraph &G, ofstream &fout){
    vertex vn=G.size();
    weight infty=UINT_MAX;
    component Tn=0;
    vector<weight> Pw (vn,0);
    vector<vertex> Pp (vn,vn);
    vector<component> Pc(vn);
    weight Tw=0, mw;
    vertex mv=0, mvi=0;
    //La idea és sortir d'un vertex amb pare a un vertex que el seu pare(Pp) es vn;
    do{
        mw=infty;
        for(vertex v=0; v<vn; v++)
            for(indice i=0; i<G[v].size(); i++)
                if(Pp[v]==vn && mw>G[v][i].second){
                    mw=G[v][i].second;
                    mv=v;
                    mvi=i;
                }
        if(mw==infty)
            break;
        vertex mva=G[mv][mvi].first;
        Pp[mv]=mv;
        Pp[mva]=mv;
        Pc[mv]=Tn;
        Pc[mva]=Tn;
        Tw+=mw;
        Pw[Tn]+=mw;
        do{
            fout << "Aresta de Prim " << mv << " -> " << G[mv][mvi].first << " (" << mvi << ") " << "Pes " << mw <<endl;
            mw=infty;
            for(vertex v=0; v<vn; v++)
                for(indice i=0; i<G[v].size(); i++)
                    if(Pp[G[v][i].first]==vn && Pp[v]<vn && mw>G[v][i].second){
                        mw=G[v][i].second;
                        mv=v;
                        mvi=i;
                    }
            if(mw==infty)
                break;
            vertex mva=G[mv][mvi].first;
            Pp[mva]=mv;
            //Assignem components
            Pc[mva]=Tn;
            Tw+=mw;
            Pw[Tn]+=mw;
        }while(true);//Per trobar totes les components
        Tn++;
    }while(true);//Trobo arestes inicials;
    for(vertex v=0; v<vn; v++)
        if(!G[v].size()){
            Pc[v]=Tn;
            Tn++;
        }
    fout << "Pares de cada vertex:" <<endl;
    for(vertex v=0; v<vn; v++)
        fout << "Vertex " << v << ": " << Pp[v] <<endl;
    fout << "Pes de cada arbre: " << endl;
    for( vertex v=0; v<vn; v++)
        if(Pc[v]==v)
            fout << "\tArbre " << v << ": " << Pw[v]<< endl;
    return Tw;
}
