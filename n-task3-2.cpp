#include <iostream>
using namespace std;
const int MaxVnum=100;// Maximum number of vertices
 
typedef char VexType;// Data type of vertices is character
 
typedef struct AdjNode{ // Definition of adjacency node
    int v; // Index of the adjacent vertex
    struct AdjNode *next; // Pointer to the next adjacent node
}AdjNode;
 
typedef struct VexNode{ // Definition of vertex node
    VexType data; // Data of the vertex
    AdjNode *first; // Pointer to the first adjacent node
}VexNode;
 
typedef struct{// Definition of adjacency list
    VexNode  Vex[MaxVnum];
    int vexnum,edgenum; // Number of vertices, number of edges
}ALGragh;
 
int locatevex(ALGragh G,VexType x)
{
    for(int i=0;i<G.vexnum;i++)// Find the index of the vertex
       if(x==G.Vex[i].data)
        return i;
    return -1;// Not found
}
 
void insertedge(ALGragh &G,int i,int j)// Insert an edge
{
    AdjNode *s;
    s=new AdjNode;
    s->v=j;
    s->next=G.Vex[i].first;
    G.Vex[i].first=s;
}
 
void printg(ALGragh G)// Print the adjacency list
{
   cout<<"----------Adjacency List----------"<<endl;
   for(int i=0;i<G.vexnum;i++)
   {
       AdjNode *t=G.Vex[i].first;
       cout<<G.Vex[i].data<<"£º  ";
       while(t!=NULL)
       {
           cout<<"["<<t->v<<"]  ";
           t=t->next;
       }
       cout<<endl;
   }
}
 
void CreateALGraph(ALGragh &G)// Create a directed graph using adjacency list
{
    int i,j;
    VexType u,v;
    cout<<"Enter the number of vertices and edges:"<<endl;
    cin>>G.vexnum>>G.edgenum;
    cout << "Enter the vertex information:"<<endl;
    for(i=0;i<G.vexnum;i++)// Input vertex information and store in the vertex array
        cin>>G.Vex[i].data;
    for(i=0;i<G.vexnum;i++)
        G.Vex[i].first=NULL;
    cout<<"Enter the two vertices u and v for each edge"<<endl;
    while(G.edgenum--)
    {
        cin>>u>>v;
        i=locatevex(G,u);// Find the index of vertex u
        j=locatevex(G,v);// Find the index of vertex v
        if(i!=-1&&j!=-1)
            insertedge(G,i,j);
        else
        {
           cout << "Wrong vertex information! Please re-enter!"<<endl;
           G.edgenum++;// This input doesn't count
        }
    }
}
 
int main()
{
    ALGragh G;
    CreateALGraph(G);// Create a directed graph using adjacency list
    printg(G);// Print the adjacency list
    return 0;
}
