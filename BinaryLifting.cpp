vector<int>adj[maxN2];
vector<vector<int>>dp; // size if n * 16 (if n is upto 1e5 because (1 << 16) >= 1e5)
vector<int>level; // For finding lca we first bring the nodes to same level
void dfs(int u , int p , int lvl = 0)
{
    dp[u][0] = p;
    for (int i = 1 ; i <= 20 ; i++)
    {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    level[u] = lvl;
    for (auto v : adj[u])
    {
        if (v == p)continue;
        dfs(v , u , lvl + 1);
    }
}
int getKthParent(int node , int k)
{
    int cnt = 0;
    while (k)
    {
        if ((k & 1))node = dp[node][cnt];
        k >>= 1; cnt++;
    }
    return node;
                }
                
 int getLCA(int a , int b)
{
    // Remember to swap values of a & b if level[a] > level[b]
    if (level[a] < level[b])swap(a, b);
    int k = level[a] - level[b];
    a = getKthParent(a, k , dp);
    for (int i = 20 ; i >= 0 ; i--)
    {
        if (a == b) return a;
        if (dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}
