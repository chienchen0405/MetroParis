#include <iostream>
#include <vector>
using namespace std;

const int MaxVnum = 100; // Maximum number of vertices

typedef char VexType; // Vertex data type is character
typedef struct AdjNode
{ // Definition of adjacency node
    int v;                  // Index of adjacent vertex
    struct AdjNode *next;   // Pointer to the next adjacent node
} AdjNode;

typedef struct VexNode
{ // Definition of vertex node
    VexType data;            // Data of the vertex, type can be changed as needed
    AdjNode *first;          // Pointer to the first adjacent node
    vector<int> predecessors; // Store the set of predecessors
} VexNode;

typedef struct
{ // Definition of adjacency list
    VexNode Vex[MaxVnum];
    int vexnum, edgenum; // Number of vertices and edges
} ALGragh;

int locatevex(ALGragh G, VexType x)
{
    for (int i = 0; i < G.vexnum; i++) // Find the index of the vertex information
        if (x == G.Vex[i].data)
            return i;
    return -1; // Not found
}

void insertedge(ALGragh &G, int i, int j) // Insert an edge
{
    AdjNode *s;
    s = new AdjNode;
    s->v = j;
    s->next = G.Vex[i].first;
    G.Vex[i].first = s;

    // Update the set of predecessors
    G.Vex[j].predecessors.push_back(i);
}

void printg(ALGragh G) // Print the adjacency list
{
    cout << "----------Adjacency List----------" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        AdjNode *t = G.Vex[i].first;
        cout << G.Vex[i].data << ":  ";
        while (t != NULL)
        {
            cout << "[" << t->v << "]  ";
            t = t->next;
        }
        cout << endl;
    }
}

void CreateALGraph(ALGragh &G) // Create a directed graph using adjacency list
{
    int i, j;
    VexType u, v;
    cout << "Enter the number of vertices and edges:" << endl;
    cin >> G.vexnum >> G.edgenum;
    cout << "Enter the vertex information:" << endl;
    for (i = 0; i < G.vexnum; i++) // Input vertex information and store it in the vertex array
        cin >> G.Vex[i].data;
    for (i = 0; i < G.vexnum; i++)
        G.Vex[i].first = NULL;
    cout << "Enter the two vertices u and v for each edge" << endl;
    while (G.edgenum--)
    {
        cin >> u >> v;
        i = locatevex(G, u); // Find the index of vertex u
        j = locatevex(G, v); // Find the index of vertex v
        if (i != -1 && j != -1)
            insertedge(G, i, j);
        else
        {
            cout << "Invalid vertex information! Please re-enter!" << endl;
            G.edgenum++; //
        }
    }
}

vector<int> getPredecessors(ALGragh G, int node)
{
    return G.Vex[node].predecessors;
}

vector<int> getSuccessors(ALGragh G, int node)
{
    vector<int> successors;
    AdjNode *p = G.Vex[node].first;
    while (p != NULL)
    {
        successors.push_back(p->v);
        p = p->next;
    }

    return successors;
}

int main()
{
    ALGragh G;
    CreateALGraph(G); // Create a directed graph using adjacency list
    printg(G);        // Print the adjacency list

    // Get the set of predecessors and successors of node N
    VexType N;
    cout << "Enter the value of node N: ";
    cin >> N;

    int node = locatevex(G, N); // Get the index of node N
    if (node != -1)
    {
        vector<int> predecessors = getPredecessors(G, node);
        vector<int> successors = getSuccessors(G, node);    
        cout << "Predecessors of node " << N << ": ";
        for (int i = 0; i < predecessors.size(); i++)
        {
            cout << G.Vex[predecessors[i]].data << " ";
        }
        cout << endl;

        cout << "Successors of node " << N << ": ";
        for (int i = 0; i < successors.size(); i++)
        {
            cout << G.Vex[successors[i]].data << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Node " << N << " does not exist!" << endl;
    }

    return 0;
}
