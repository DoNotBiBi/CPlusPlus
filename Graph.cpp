#include <cstdlib>
#include <iostream>
#include <fstream>
#include <deque>
#define MAX_SIZE 16

using namespace std;

typedef struct ArcNode {
    int vertex;
    ArcNode* nextAdj;
};

typedef struct VNode {
    int data;
    ArcNode* fristAdj;
};

typedef struct Graph {
    VNode M[MAX_SIZE];
    int n;
};

bool visited[MAX_SIZE];

// 无向图
void CreateGraph(Graph& G)
{
    ifstream ifs;
    ifs.open("in.txt");  

    // in.txt 的内容
    // 4
    // 1  2
    // 1  4
    // 2  3
    // 2  4
    // 3  4
    ifs >> G.n;
    for (int i = 0; i < G.n; i++)
    {
        G.M[i].fristAdj = NULL;
    }
    int a, b;
    while (!ifs.eof())
    {
        ifs >> a >> b;
        a = a - 1;
        b = b - 1;
        ArcNode* arc_a = new ArcNode();
        ArcNode* arc_b = new ArcNode();
        arc_a->vertex = a;
        arc_b->vertex = b;
        arc_a->nextAdj = NULL; // 防止野指针
        arc_b->nextAdj = NULL; // 防止野指针

        if (!G.M[a].fristAdj)
        {
            G.M[a].fristAdj = arc_b;
        }
        else
        {
            ArcNode* p1 = G.M[a].fristAdj;
            while (p1->nextAdj) p1 = p1->nextAdj;
            p1->nextAdj = arc_b;
        }

        if (!G.M[b].fristAdj)
        {
            G.M[b].fristAdj = arc_a;
        }
        else
        {
            ArcNode* p2 = G.M[b].fristAdj;
            while (p2->nextAdj) p2 = p2->nextAdj;
            p2->nextAdj = arc_a;
        }
    }
    ifs.close();
}

void DFS(Graph& G, int v)
{
    visited[v] = true;
    cout << v << endl;
    for (ArcNode* w = G.M[v].fristAdj; w!=NULL; w = w->nextAdj)
    {
        if (!visited[w->vertex]) DFS(G, w->vertex);
    }
}

void DFSTraverse(Graph& G)
{
    for (int i = 0; i < G.n; i++) visited[i] = false;  // 初始化全部为false；
    for (int v = 0; v < G.n; v++)
    {
        if (!visited[v]) DFS(G, v);
    }
}

//广度优先搜索
void BFSTraverse(Graph& G)
{
    for (int i = 0; i < G.n; i++)
    {
        visited[i] = false;
    }
    deque<int> Q; // 使用的是循环队列
    for (int v = 0; v < G.n; v++)
    {
        if (!visited[v])
        {
            visited[v] = true;
            cout << v << endl;
            Q.push_back(v);
            while (!Q.empty())
            {
                v = Q.front();
                Q.pop_front();
                for (ArcNode* w = G.M[v].fristAdj; w; w = w->nextAdj)
                {
                    if (!visited[w->vertex])
                    {
                        visited[w->vertex] = true;
                        cout << w->vertex << endl;
                        Q.push_back(w->vertex);
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    Graph G;
    CreateGraph(G);
    DFSTraverse(G);
    BFSTraverse(G);
    system("PAUSE");
    return EXIT_SUCCESS;
}
