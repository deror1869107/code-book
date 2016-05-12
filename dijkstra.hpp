struct Node {int b, d;};
bool operator<(const Node& n1, const Node& n2) {
	return n1.d > n2.d;
}

const int N;
int w[N][N];    // adjacency matrix
int d[N];
int parent[N];
bool visit[N];

void dijkstra(int source)
{
    for (int i=0; i<9; i++) visit[i] = false;
    for (int i=0; i<9; i++) d[i] = 1e9;

    priority_queue<Node> PQ;

    d[source] = 0;
    parent[source] = source;
    PQ.push((Node){source, d[source]});

    for (int i=0; i<9; i++)
    {
        int a = -1;
        while (!PQ.empty() && visit[a = PQ.top().b])
            PQ.pop();
        if (a == -1) break;
        
        visit[a] = true;

        for (int b=0; b<9; b++)
            if (!visit[b] && d[a] + w[a][b] < d[b])
            {
                d[b] = d[a] + w[a][b];
                parent[b] = a;
                PQ.push( (Node){b, d[b]} );
            }
    }
}