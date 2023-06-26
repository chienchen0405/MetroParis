#include<stdio.h>

#define MAXVERTEXNUM 100 //�������鳤��

#define INFINITY 100//��������

struct Graph{

    int VertexNum;//ͼ�ж������

    char Vertex[MAXVERTEXNUM];//��ͼ�Ķ�����ĸ��������

    int AdjMatrix[MAXVERTEXNUM][MAXVERTEXNUM];//������Ӿ�������������

};

Graph MGraph;

char Path[MAXVERTEXNUM][MAXVERTEXNUM];//����ͼ���ڽӾ���

int Dest[MAXVERTEXNUM];//ȫ������Ȩֵ

void CreateGraph(Graph *G);//����ͼ���ú���

void ShowGraph(Graph *G);//չʾͼ���ú���

void ShortestPath(Graph *G, char StartVexChar);//����·��
void ShowPath(Graph *G); //չʾ·��

int main(){  

    char StartVex;//

   

    CreateGraph(&MGraph);

    ShowGraph(&MGraph);

    printf("�����뿪ʼ�Ķ���");

    scanf("%c", &StartVex);

    ShortestPath(&MGraph, StartVex);

    ShowPath(&MGraph);

    return 0;

}
//

void CreateGraph(Graph *G){

    int i, j;

   

    printf("�����붥�����\n");

    scanf("%d", &G->VertexNum);

    printf("�����붥��\n");

    getchar();

    for(i = 1; i <= G->VertexNum; i++){

        scanf("%c", &G->Vertex[i]);

        getchar();

    }
    printf("�������ڽӾ���\n");

    for(i = 1; i <= G->VertexNum; i++){

        for(j = 1; j <= G->VertexNum; j++){

            scanf("%d", &G->AdjMatrix[i][j]);

            getchar();

            if(G->AdjMatrix[i][j] == -1)

               G->AdjMatrix[i][j] = INFINITY;

        }  

    }

}
void ShowGraph(Graph *G){

    int i, j;

    for(i = 1; i <= G->VertexNum; i++){

        printf("%c ", G->Vertex[i]);

    }

    putchar('\n');

    for(i = 1; i <= G->VertexNum; i++){

        for(j = 1; j <= G->VertexNum; j++){

            printf("%d ", G->AdjMatrix[i][j]);

        }

        putchar('\n');  

    }

}
void ShortestPath(Graph *G, char StartVexChar){

    int i, j, m, StartVex, CurrentVex, MinDest, Final[MAXVERTEXNUM];

    for (i = 1; i <= G->VertexNum; i++){

        if(G->Vertex[i] == StartVexChar){

            StartVex = i;

            break;

        }

    }

    for (i = 1; i <= G->VertexNum; i++){

        Path[i][0] = 0;

        Dest[i] = INFINITY;
         if(G->AdjMatrix[StartVex][i] < INFINITY){

            Dest[i] = G->AdjMatrix[StartVex][i];

            Path[i][1] = G->Vertex[StartVex];

            Path[i][2] = G->Vertex[i];

            Path[i][0] = 2;

        }

        Final[i] = 'F';

    }
	Dest[StartVex] = 0;

    Final[StartVex] = 'T';

    for (i = 1; i <= G->VertexNum; i++){

        MinDest = INFINITY;

        for (j = 1; j <= G->VertexNum; j++){

            if(Final[j] == 'F'){

                if(Dest[j] < MinDest){

                    CurrentVex = j;

                    MinDest = Dest[j];

                }

            }

        }
		Final[CurrentVex] = 'T';

        for (j = 1; j <= G->VertexNum; j++){

            if((Final[j] == 'F') && (MinDest + G->AdjMatrix[CurrentVex][j]) < Dest[j]){

                Dest[j] = MinDest + G->AdjMatrix[CurrentVex][j];

                for(m = 0; m <= Path[CurrentVex][0]; m++)

                    Path[j][m] = Path[CurrentVex][m];

                Path[j][0]++;

                Path[j][Path[j][0]] = G->Vertex[j];

            }

        }    

    }  

}
void ShowPath(Graph *G){

    int i, j;

    for(i= 1; i <= G->VertexNum; i++){

        printf("%c(%d):", G->Vertex[i], Dest[i]);

        if(Path[i][0] > 0){

            for(j = 1; j <= Path[i][0]; j++){

                printf(" %c", Path[i][j]);

            }      

        }

        printf("%c\n", Path[i][j]);

    }

} 
