#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define MaxVertexNum 100
#define INF 32767

//定义图结构
typedef struct {
    char vertex[MaxVertexNum];                  //顶点
    int edges[MaxVertexNum][MaxVertexNum];      //边的权值
    int n,e;                                    //顶点数和边数
}MGraph;

//创建图
void CreateMGraph(MGraph &G){
    int i,j,g;
    cout << "请输入顶点数和边数：";
    cin >> G.n >> G.e;
    cout << "请输入顶点元素：" ;
    for (int i = 0; i < G.n; ++i) {
        cin >> G.vertex[i];
    }

    //图初始化
    for (int i = 0; i < G.n; ++i) {
        for (int j = 0; j < G.n; ++j) {
            G.edges[i][j] = INF;
            if(i == j){
                G.edges[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < G.e; ++k) {
        cout << "请输入第" << k + 1 << "条弧头弧尾号以及权值：" ;
        cin >> i >> j >> g;
        G.edges[i][j] = g;
    }
}

//获取路径
void Ppath(int path[][MaxVertexNum],int i,int j){
    int k;
    k = path[i][j];
    if(k == -1)
        return;
    Ppath(path,i,k);
    printf("%d,",k);
    Ppath(path,k,j);
}

void Dispath(int A[][MaxVertexNum],int path[][MaxVertexNum],int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == INF) {
                if (i != j)
                    printf("从%d到%d没有路径\n", i, j);
            } else {
                printf("从%d到%d=》路径长度：%d\n", i, j, A[i][j]);
                //输出路径
                printf("%d,", i);
                Ppath(path, i, j);
                printf("%d\n", j);
            }
        }
    }
}

void Floyd(MGraph &G)
{
    int A[MaxVertexNum][MaxVertexNum];
    int path[MaxVertexNum][MaxVertexNum];
    for (int i = 0; i < G.n; ++i) {
        for (int j = 0; j < G.n; ++j) {
            A[i][j] = G.edges[i][j];
            path[i][j] = -1;
        }
    }
    for (int k = 0; k < G.n; ++k) {               //从顶点编号0开始到n

        //对A（k）更新
        for (int i = 0; i < G.n; ++i) {
            for (int j = 0; j < G.n; ++j) {
                if(A[i][j] > A[i][k] + A[k][j]){
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;               //更新中间顶点
                }
                Dispath(A,path,G.n);              //输出当前最短路径长度
            }
        }
    }
}
int main(){
    MGraph G;
    CreateMGraph(G);
    Floyd(G);
    return 0;
}

