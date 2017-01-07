//
// Created by djc on 07/01/2017.
//

#ifndef C_RESET_FUNCTION_H
#define C_RESET_FUNCTION_H

#include <iostream>
#include "Graph.h"

using namespace std;


void createUndirectGraph(Graph &Graph0,Node *A)
{
    Node *B = new Node("B", 0);
    Node *C = new Node("C", 0);
    Node *D = new Node("D", 0);
    Node *E = new Node("E", 0);
    Node *F = new Node("F", 0);
    Node *G = new Node("G", 0);
    Node *H = new Node("H", 0);
    Node *I = new Node("I", 0);
    Node *J = new Node("J", 0);
    Node *K = new Node("K", 0);
    Node *L = new Node("L", 0);
    Node *M = new Node("M", 0);
    Node *N = new Node("N", 0);
    Node *O = new Node("O", 0);
    Node *P = new Node("P", 0);
    Node *Q = new Node("Q", 0);
    Node *R = new Node("R", 0);
    Node *S = new Node("S", 0);
    Node *T = new Node("T", 0);
    Node *U = new Node("U", 0);
    Node *V = new Node("V", 0);
    Node *W = new Node("W", 0);
    Node *X = new Node("X", 0);
    Node *Y = new Node("Y", 0);
    Node *Z = new Node("Z", 0);

    Graph0.addNode(A);
    Graph0.addNode(B);
    Graph0.addNode(C);
    Graph0.addNode(D);
    Graph0.addNode(E);
    Graph0.addNode(F);
    Graph0.addNode(G);
    Graph0.addNode(H);
    Graph0.addNode(I);
    Graph0.addNode(J);
    Graph0.addNode(K);
    Graph0.addNode(L);
    Graph0.addNode(M);
    Graph0.addNode(N);
    Graph0.addNode(O);
    Graph0.addNode(P);
    Graph0.addNode(Q);
    Graph0.addNode(R);
    Graph0.addNode(S);
    Graph0.addNode(T);
    Graph0.addNode(U);
    Graph0.addNode(V);
    Graph0.addNode(W);
    Graph0.addNode(X);
    Graph0.addNode(Y);
    Graph0.addNode(Z);

    Edge *AB = new Edge(A->getId(), B->getId(), 1892);
    Edge *BC = new Edge(B->getId(), C->getId(), 216);
    Edge *BD = new Edge(B->getId(), D->getId(), 1145);
    Edge *BW = new Edge(B->getId(), W->getId(), 676);
    Edge *DE = new Edge(D->getId(), E->getId(), 668);
    Edge *DZ = new Edge(D->getId(), Z->getId(), 340);
    Edge *EF = new Edge(E->getId(), F->getId(), 137);
    Edge *EX = new Edge(E->getId(), X->getId(), 695);
    Edge *FG = new Edge(F->getId(), G->getId(), 704);
    Edge *FK = new Edge(F->getId(), K->getId(), 674);
    Edge *GH = new Edge(G->getId(), H->getId(), 305);
    Edge *GJ = new Edge(G->getId(), J->getId(), 397);
    Edge *HI = new Edge(H->getId(), I->getId(), 242);
    Edge *KL = new Edge(K->getId(), L->getId(), 651);
    Edge *KU = new Edge(K->getId(), U->getId(), 1323);
    Edge *KX = new Edge(K->getId(), X->getId(), 349);
    Edge *LM = new Edge(L->getId(), M->getId(), 825);
    Edge *MN = new Edge(M->getId(), N->getId(), 622);
    Edge *MQ = new Edge(M->getId(), Q->getId(), 367);
    Edge *MZ = new Edge(M->getId(), Z->getId(), 1067);
    Edge *OP = new Edge(O->getId(), P->getId(), 140);
    Edge *PQ = new Edge(P->getId(), Q->getId(), 675);
    Edge *QR = new Edge(Q->getId(), R->getId(), 672);
    Edge *QU = new Edge(Q->getId(), U->getId(), 902);
    Edge *QY = new Edge(Q->getId(), Y->getId(), 409);
    Edge *RS = new Edge(R->getId(), S->getId(), 255);
    Edge *RU = new Edge(R->getId(), U->getId(), 607);
    Edge *TU = new Edge(T->getId(), U->getId(), 639);
    Edge *TV = new Edge(T->getId(), V->getId(), 1100);
    Edge *UV = new Edge(U->getId(), V->getId(), 967);
    Edge *VW = new Edge(V->getId(), W->getId(), 842);
    Edge *WX = new Edge(W->getId(), X->getId(), 511);

    Graph0.addEdge(AB);
    Graph0.addEdge(BC);
    Graph0.addEdge(BD);
    Graph0.addEdge(BW);
    Graph0.addEdge(DE);
    Graph0.addEdge(DZ);
    Graph0.addEdge(EF);
    Graph0.addEdge(EX);
    Graph0.addEdge(FG);
    Graph0.addEdge(FK);
    Graph0.addEdge(GH);
    Graph0.addEdge(GJ);
    Graph0.addEdge(HI);
    Graph0.addEdge(KL);
    Graph0.addEdge(KU);
    Graph0.addEdge(KX);
    Graph0.addEdge(LM);
    Graph0.addEdge(MN);
    Graph0.addEdge(MQ);
    Graph0.addEdge(MZ);
    Graph0.addEdge(OP);
    Graph0.addEdge(PQ);
    Graph0.addEdge(QR);
    Graph0.addEdge(QU);
    Graph0.addEdge(QY);
    Graph0.addEdge(RS);
    Graph0.addEdge(RU);
    Graph0.addEdge(TU);
    Graph0.addEdge(TV);
    Graph0.addEdge(UV);
    Graph0.addEdge(VW);
    Graph0.addEdge(WX);
}

void createUndirectGraph2(Graph &Graph0,Node *A)
{
    Node *B = new Node("B", 0);
    Node *C = new Node("C", 0);
    Node *D = new Node("D", 0);
    Node *E = new Node("E", 0);
    Node *F = new Node("F", 0);
    Node *G = new Node("G", 0);
    Node *H = new Node("H", 0);
    Node *I = new Node("I", 0);
    Node *J = new Node("J", 0);
    Node *K = new Node("K", 0);
    Node *L = new Node("L", 0);
    Node *M = new Node("M", 0);
    Node *N = new Node("N", 0);
    Node *O = new Node("O", 0);
    Node *P = new Node("P", 0);
    Node *Q = new Node("Q", 0);
    Node *R = new Node("R", 0);
    Node *S = new Node("S", 0);
    Node *T = new Node("T", 0);
    Node *U = new Node("U", 0);
    Node *V = new Node("V", 0);
    Node *W = new Node("W", 0);
    Node *X = new Node("X", 0);
    Node *Y = new Node("Y", 0);
    Node *Z = new Node("Z", 0);

    Graph0.addNode(A);
    Graph0.addNode(B);
    Graph0.addNode(C);
    Graph0.addNode(D);
    Graph0.addNode(E);
    Graph0.addNode(F);
    Graph0.addNode(G);
    Graph0.addNode(H);
    Graph0.addNode(I);
    Graph0.addNode(J);
    Graph0.addNode(K);
    Graph0.addNode(L);
    Graph0.addNode(M);
    Graph0.addNode(N);
    Graph0.addNode(O);
    Graph0.addNode(P);
    Graph0.addNode(Q);
    Graph0.addNode(R);
    Graph0.addNode(S);
    Graph0.addNode(T);
    Graph0.addNode(U);
    Graph0.addNode(V);
    Graph0.addNode(W);
    Graph0.addNode(X);
    Graph0.addNode(Y);
    Graph0.addNode(Z);

    Edge *AB = new Edge(A->getId(), B->getId(), 1892);
    Edge *BC = new Edge(B->getId(), C->getId(), 216);
    Edge *BD = new Edge(B->getId(), D->getId(), 1145);
    Edge *BW = new Edge(B->getId(), W->getId(), 676);
    Edge *DE = new Edge(D->getId(), E->getId(), 668);
    Edge *DZ = new Edge(D->getId(), Z->getId(), 340);
    Edge *EF = new Edge(E->getId(), F->getId(), 137);
    Edge *EX = new Edge(E->getId(), X->getId(), 695);
    Edge *FG = new Edge(F->getId(), G->getId(), 704);
    Edge *FK = new Edge(F->getId(), K->getId(), 674);
    Edge *GH = new Edge(G->getId(), H->getId(), 305);
    Edge *GJ = new Edge(G->getId(), J->getId(), 397);
    Edge *HI = new Edge(H->getId(), I->getId(), 242);
    Edge *KL = new Edge(K->getId(), L->getId(), 651);
    Edge *KU = new Edge(K->getId(), U->getId(), 1323);
    Edge *KX = new Edge(K->getId(), X->getId(), 349);
    Edge *LM = new Edge(L->getId(), M->getId(), 825);
    Edge *MN = new Edge(M->getId(), N->getId(), 622);
    Edge *MQ = new Edge(M->getId(), Q->getId(), 367);
    Edge *MZ = new Edge(M->getId(), Z->getId(), 1067);
    Edge *OP = new Edge(O->getId(), P->getId(), 140);
    Edge *PQ = new Edge(P->getId(), Q->getId(), 675);
    Edge *QR = new Edge(Q->getId(), R->getId(), 672);
    Edge *QU = new Edge(Q->getId(), U->getId(), 902);
    Edge *QY = new Edge(Q->getId(), Y->getId(), 409);
    Edge *RS = new Edge(R->getId(), S->getId(), 255);
    Edge *RU = new Edge(R->getId(), U->getId(), 607);
    Edge *TU = new Edge(T->getId(), U->getId(), 639);
    Edge *TV = new Edge(T->getId(), V->getId(), 1100);
    Edge *UV = new Edge(U->getId(), V->getId(), 967);
    Edge *VW = new Edge(V->getId(), W->getId(), 842);
    Edge *WX = new Edge(W->getId(), X->getId(), 511);

    Graph0.addEdge(AB);
    Graph0.addEdge(BC);
    Graph0.addEdge(BD);
    Graph0.addEdge(BW);
    Graph0.addEdge(DE);
    Graph0.addEdge(DZ);
    Graph0.addEdge(EF);
    Graph0.addEdge(EX);
    Graph0.addEdge(FG);
    Graph0.addEdge(FK);
    Graph0.addEdge(GH);
    Graph0.addEdge(GJ);
    Graph0.addEdge(HI);
    Graph0.addEdge(KL);
    Graph0.addEdge(KU);
    Graph0.addEdge(KX);
    Graph0.addEdge(LM);
    Graph0.addEdge(MN);
    Graph0.addEdge(MQ);
    Graph0.addEdge(MZ);
    Graph0.addEdge(OP);
    Graph0.addEdge(PQ);
    Graph0.addEdge(QR);
    Graph0.addEdge(QU);
    Graph0.addEdge(QY);
    Graph0.addEdge(RS);
    Graph0.addEdge(RU);
    Graph0.addEdge(TU);
    Graph0.addEdge(TV);
    Graph0.addEdge(UV);
    Graph0.addEdge(VW);
    Graph0.addEdge(WX);
}

void createDirectGraph(Graph &Graph0,Node *A)
{
    Node *B = new Node("B", 0);
    Node *C = new Node("C", 0);
    Node *D = new Node("D", 0);
    Node *E = new Node("E", 0);
    Node *F = new Node("F", 0);
    Node *G = new Node("G", 0);
    Node *H = new Node("H", 0);
    Node *I = new Node("I", 0);
    Node *J = new Node("J", 0);
    Node *K = new Node("K", 0);
    Node *L = new Node("L", 0);
    Node *M = new Node("M", 0);
    Node *N = new Node("N", 0);
    Node *O = new Node("O", 0);
    Node *P = new Node("P", 0);
    Node *Q = new Node("Q", 0);
    Node *R = new Node("R", 0);
    Node *S = new Node("S", 0);
    Node *T = new Node("T", 0);
    Node *U = new Node("U", 0);
    Node *V = new Node("V", 0);
    Node *W = new Node("W", 0);
    Node *X = new Node("X", 0);
    Node *Y = new Node("Y", 0);
    Node *Z = new Node("Z", 0);

    Graph0.addNode(A);
    Graph0.addNode(B);
    Graph0.addNode(C);
    Graph0.addNode(D);
    Graph0.addNode(E);
    Graph0.addNode(F);
    Graph0.addNode(G);
    Graph0.addNode(H);
    Graph0.addNode(I);
    Graph0.addNode(J);
    Graph0.addNode(K);
    Graph0.addNode(L);
    Graph0.addNode(M);
    Graph0.addNode(N);
    Graph0.addNode(O);
    Graph0.addNode(P);
    Graph0.addNode(Q);
    Graph0.addNode(R);
    Graph0.addNode(S);
    Graph0.addNode(T);
    Graph0.addNode(U);
    Graph0.addNode(V);
    Graph0.addNode(W);
    Graph0.addNode(X);
    Graph0.addNode(Y);
    Graph0.addNode(Z);

    Edge *AB = new Edge(A->getId(), B->getId(), 1892);
    Edge *BC = new Edge(B->getId(), C->getId(), 216);
    Edge *BD = new Edge(B->getId(), D->getId(), 1145);
    Edge *BW = new Edge(B->getId(), W->getId(), 676);
    Edge *DE = new Edge(D->getId(), E->getId(), 668);
    Edge *DZ = new Edge(D->getId(), Z->getId(), 340);
    Edge *EF = new Edge(E->getId(), F->getId(), 137);
    Edge *EX = new Edge(E->getId(), X->getId(), 695);
    Edge *FG = new Edge(F->getId(), G->getId(), 704);
    Edge *FK = new Edge(F->getId(), K->getId(), 674);
    Edge *GH = new Edge(G->getId(), H->getId(), 305);
    Edge *GJ = new Edge(G->getId(), J->getId(), 397);
    Edge *HI = new Edge(H->getId(), I->getId(), 242);
    Edge *KL = new Edge(K->getId(), L->getId(), 651);
    Edge *KU = new Edge(K->getId(), U->getId(), 1323);
    Edge *KX = new Edge(K->getId(), X->getId(), 349);
    Edge *LM = new Edge(L->getId(), M->getId(), 825);
    Edge *MN = new Edge(M->getId(), N->getId(), 622);
    Edge *MQ = new Edge(M->getId(), Q->getId(), 367);
    Edge *MZ = new Edge(Z->getId(), M->getId(), 1067);
    Edge *OP = new Edge(P->getId(), O->getId(), 140);
    Edge *PQ = new Edge(Q->getId(), P->getId(), 675);
    Edge *QR = new Edge(Q->getId(), R->getId(), 672);
    Edge *QU = new Edge(Q->getId(), U->getId(), 902);
    Edge *QY = new Edge(Q->getId(), Y->getId(), 409);
    Edge *RS = new Edge(R->getId(), S->getId(), 255);
    Edge *RU = new Edge(R->getId(), U->getId(), 607);
    Edge *TU = new Edge(S->getId(), T->getId(), 639);
    Edge *TV = new Edge(T->getId(), V->getId(), 1100);
    Edge *UV = new Edge(U->getId(), V->getId(), 967);
    Edge *VW = new Edge(W->getId(), V->getId(), 842);
    Edge *WX = new Edge(X->getId(), W->getId(), 511);

    Edge *NU = new Edge(N->getId(), U->getId(), 429);
    Edge *OS = new Edge(O->getId(), S->getId(), 630);
    Edge *UT = new Edge(U->getId(), T->getId(), 684);
    Edge *YP = new Edge(Y->getId(), P->getId(), 639);
    Edge *CW = new Edge(C->getId(), W->getId(), 656);
    Edge *IL = new Edge(I->getId(), L->getId(), 676);
    Edge *JI = new Edge(J->getId(), I->getId(), 326);

    Graph0.addEdge(AB);
    Graph0.addEdge(BC);
    Graph0.addEdge(BD);
    Graph0.addEdge(BW);
    Graph0.addEdge(DE);
    Graph0.addEdge(DZ);
    Graph0.addEdge(EF);
    Graph0.addEdge(EX);
    Graph0.addEdge(FG);
    Graph0.addEdge(FK);
    Graph0.addEdge(GH);
    Graph0.addEdge(GJ);
    Graph0.addEdge(HI);
    Graph0.addEdge(KL);
    Graph0.addEdge(KU);
    Graph0.addEdge(KX);
    Graph0.addEdge(LM);
    Graph0.addEdge(MN);
    Graph0.addEdge(MQ);
    Graph0.addEdge(MZ);
    Graph0.addEdge(OP);
    Graph0.addEdge(PQ);
    Graph0.addEdge(QR);
    Graph0.addEdge(QU);
    Graph0.addEdge(QY);
    Graph0.addEdge(RS);
    Graph0.addEdge(RU);
    Graph0.addEdge(TU);
    Graph0.addEdge(TV);
    Graph0.addEdge(UV);
    Graph0.addEdge(VW);
    Graph0.addEdge(WX);

    Graph0.addEdge(NU);
    Graph0.addEdge(OS);
    Graph0.addEdge(UT);
    Graph0.addEdge(YP);
    Graph0.addEdge(CW);
    Graph0.addEdge(IL);
    Graph0.addEdge(JI);
}


void DepthFirstTraverse()
{

    cout << "DepthFirstTraverse:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createUndirectGraph(Graph0,A);

    cout << Graph0.getGraph() << endl;
    cout << Graph0.depthFirstTraverse(A) << endl;
}

void breadthFirstTraverse()
{

    cout << "breadthFirstTraverse:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createUndirectGraph(Graph0,A);

    cout << Graph0.breadthFirstTraverse(A) << endl;
}

void primTree()
{

    cout << "primTree:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createUndirectGraph(Graph0,A);

    cout << Graph0.primTree(A) << endl;
}

void KruskalTree()
{

    cout << "KruskalTree:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createUndirectGraph(Graph0,A);

    cout << Graph0.KruskalTree() << endl;
}

void topsort()
{

    cout << "topsort:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createDirectGraph(Graph0,A);

    cout << Graph0.getGraph() << endl;

    cout << Graph0.topsort() << endl;
}


void Dijk()
{

    cout << "Dijk:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createDirectGraph(Graph0,A);

    vector<string> Dijk = Graph0.Dijkstra(A);
    for(int i = 0; i < Dijk.size(); ++i)
    {
        cout << Dijk[i] << endl;
    }
}

void CriticalPath()
{
    cout << "CriticalPath:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createDirectGraph(Graph0,A);

    cout << Graph0.CriticalPath() << endl;
}

void connectedSubGraph()
{

    cout << "connectedSubGraph:";
    Graph Graph0;
    Node *A = new Node("A", 0);
    createUndirectGraph2(Graph0,A);

    vector<Graph> SubGraph = Graph0.connectedSubGraph();
    for(int i = 0; i < SubGraph.size(); ++i)
    {
        cout << SubGraph[i].getGraph() << endl;
    }
}



#endif //C_RESET_FUNCTION_H
