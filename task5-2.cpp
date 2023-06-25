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
} VexNode;
 
typedef struct
{ // Definition of adjacency list
    VexNode  Vex[MaxVnum];
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
 
    // For undirected graph, add the reverse edge as well
    s = new AdjNode;
    s->v = i;
    s->next = G.Vex[j].first;
    G.Vex[j].first = s;
}

void CreateALGraph(ALGragh &G)
{
    cout << "Enter the number of vertices: ";
    cin >> G.vexnum;
    cout << "Enter the number of edges: ";
    cin >> G.edgenum;

    cout << "Enter the data of each vertex:" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.Vex[i].data;
        G.Vex[i].first = NULL;
    }

    cout << "Enter the edges (format: start_vertex end_vertex):" << endl;
    for (int k = 0; k < G.edgenum; k++) {
        VexType v1, v2;
        cin >> v1 >> v2;
        int i = locatevex(G, v1);
        int j = locatevex(G, v2);
        if (i != -1 && j != -1) {
            insertedge(G, i, j);
        }
    }
}

void printg(ALGragh G) // Print the adjacency list
{
    cout << "----------Adjacency List----------" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        AdjNode *t = G.Vex[i].first;
        cout << G.Vex[i].data << ": ";
        while (t != NULL)
        {
            cout << "[" << G.Vex[t->v].data << "] ";
            t = t->next;
        }
        cout << endl;
    }
}

vector<VexType> getPredecessors(ALGragh G, VexType N) // Get the predecessors of a node
{
    vector<VexType> predecessors;
	int index = locatevex(G, N);
    if (index != -1) {
        for (int i = 0; i < G.vexnum; i++) {
            AdjNode* t = G.Vex[i].first;
            while (t != NULL) {
                if (t->v == index) {
                    predecessors.push_back(G.Vex[i].data);
                    break;
                }
                t = t->next;
            }
        }
    }
    return predecessors;
}

vector<VexType> getSuccessors(ALGragh G, VexType N) // Get the successors of a node
{
    vector<VexType> successors;
    int index = locatevex(G, N);
    if (index != -1) {
        AdjNode* t = G.Vex[index].first;
        while (t != NULL) {
            successors.push_back(G.Vex[t->v].data);
            t = t->next;
        }
    }
    return successors;
}

int main()
{
    ALGragh G;
    CreateALGraph(G); // Create an undirected graph using adjacency list
    printg(G); // Print the adjacency list   VexType N;
    cout << "Enter a node: ";
    VexType N;
    cin >> N;
    vector<VexType> predecessors = getPredecessors(G, N);
    cout << "Predecessors of node " << N << ": ";
    for (int i = 0; i < predecessors.size(); i++) {
        cout << predecessors[i] << " ";
    }
    cout << endl;
    
    vector<VexType> successors = getSuccessors(G, N);
    cout << "Successors of node " << N << ": ";
    for (int i = 0; i < successors.size(); i++) {
        cout << successors[i] << " ";
    }
    cout << endl;
    
    return 0;
}
