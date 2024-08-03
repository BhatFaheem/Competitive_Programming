void disktra(int src , vector<pii> adj[] , vector<int>& parent , vector<int>& dist)
{
    dist[src] = 0;
    priority_queue<pii , vector<pii> , greater<pii>>pq;
    pq.push({0 , src});
    while (!pq.empty())
    {
        int u = pq.top().ss;
        int d_u = pq.top().ff;
        pq.pop();
        if (d_u != dist[u])continue;
        for (auto it : adj[u])
        {
            int v = it.ff;
            int wt = it.ss;
            if (dist[v] > d_u + wt)
            {
                parent[v] = u;
                dist[v] = d_u + wt;
                pq.push({dist[v] , v});
            }
        }
    }
}
void getpath(int node , vector<int>& parent)
{
    while (node != -1)
    {
        cout << node << " ";
        node = parent[node];
    }
    cout << endl;
}
