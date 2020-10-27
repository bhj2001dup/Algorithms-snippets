#define N       100005

vi adj[N];

void dfs(ll int node, ll int par)
{
    for(auto it : adj[node])
    {
        if(it != par)
        {
            dfs(it, node);
        }
    }
}