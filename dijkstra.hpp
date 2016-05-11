struct Node {int b, d;};
bool operator<(const Node& n1, const Node& n2) {return n1.d > n2.d;}

int w[9][9];    // adjacency matrix
int d[9];
int parent[9];
bool visit[9];

void dijkstra_with_priority_queue(int source)
{
    for (int i=0; i<9; i++) visit[i] = false;
    for (int i=0; i<9; i++) d[i] = 1e9;

    // C++ STL的Priority Queue
    priority_queue<Node> PQ;

    d[source] = 0;
    parent[source] = source;
    PQ.push((Node){source, d[source]});

    for (int i=0; i<9; i++)
    {
        // 找出下一個要加入到最短路徑樹的點。
        int a = -1;
        while (!PQ.empty() && visit[a = PQ.top().b])
            PQ.pop();   // 最後少pop一次，不過無妨。

        if (a == -1) break;
        visit[a] = true;

        for (int b=0; b<9; b++)
            if (!visit[b] && d[a] + w[a][b] < d[b])
            {
                d[b] = d[a] + w[a][b];
                parent[b] = a;
                // 交由Priority Queue比較大小
                PQ.push( (Node){b, d[b]} );
            }
    }
}
