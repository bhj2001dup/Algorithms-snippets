#define N       100005

bool vis[N];

vi a[N];

void dfs(int node)
{
	vis[node]=1;
	for(auto i:a[node])
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
}


void add_edge(ll int u, ll int v)
{
    a[u].push_back(v);
    a[v].push_back(u);
}
