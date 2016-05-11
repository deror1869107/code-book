int w[9][9];    // adjacency matrix
int d[9];       // 紀錄起點到各個點的最短路徑長度
int parent[9];  // 紀錄各個點在最短路徑樹上的父親是誰

void bellman_ford(int source)
{
    for (int i=0; i<9; i++) d[i] = 1e9;

    d[source] = 0;              // 設定起點的最短路徑長度
    parent[source] = source;    // 設定起點是樹根（父親為自己）

    for (int i=0; i<9-1; i++)   // 重覆步驟V-1次
        for (int a=0; a<9; ++a) // 全部的邊都當作捷徑
            for (int b=0; b<9; ++b)
                if (d[a] != 1e9 && w[a][b] != 1e9)
                    if (d[a] + w[a][b] < d[b])
                    {
                        d[b] = d[a] + w[a][b];
                        parent[b] = a;
                    }
}
