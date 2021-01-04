#include "stdio.h"
typedef struct {
    char vexs[10];
    int edges [10][10];
    int v,e;
}MGraph;

void create(MGraph &G)
{
    int  i,j,x,y;
    printf("请输入顶点和边的数目 ");
    scanf("%d%d",&G.v,&G.e);
    for(i=0;i<G.v;i++)
        G.vexs[i]='A'+i;
    for (int i = 0; i < G.v; i++)
        for (j=0;j<G.v;j++)
            G.edges[i][j]=0;
    printf("请输入边(弧)的信息（例如：0 1）：");
    for (int i = 0; i < G.e; i++) {
        scanf("%d%d",&x,&y);
        G.edges[x][y]=1;
    }
    for (int i = 0; i < G.v; i++) {
        for (int j = 0; j < G.v;j++)
            printf("%d",G.edges[i][j]);
        printf("\n");
    }
}
int visited [10];
void DFS(MGraph G,int i)
{
    int j;
    printf("%c",G.vexs[i]);
    visited[i]=1;
    for (int j = 0; j < G.v; j++)
        if(G.edges[i][j]==1 &&visited[j]==0)
            DFS(G,j);
}
void DFSTravel(MGraph G)
{
   int i;
   for(i=0;i<G.v;i++)
       visited[i]=0;
   for(i=0;i<G.v;i++)
       if(visited[i]==0)
           DFS(G,i);
}
int main()
{
    MGraph G;
    create(G);
    DFSTravel(G);
}