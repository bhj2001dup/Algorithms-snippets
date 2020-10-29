ll par[N];
ll sz[N];
std::vector<pii> changes[N];
ll st[N],en[N];
ll getpar(ll x)
{
	if(par[x]==x)
		return x;
	else
		return getpar(par[x]);
}
// Merge Nodes while storing the current state of each node
void merge(ll n1,ll n2,ll idx)
{		
	ll p1=getpar(n1);
	ll p2=getpar(n2);		
	if(p1==p2)
		return ;
	if(sz[p1]>sz[p2])
		swap(p1,p2);
	sz[p2]+=sz[p1];
	sz[p1]=0;
	for(auto i:ss[p1])
	{
		ss[p2].insert(i);
	}
	par[p1]=p2;

	// store the parents and changes to roll back
	if(idx!=-1)
	{
		st[idx]=p1;
		en[idx]=p2;
		for(auto i:ss[p1])
		{
			changes[idx].pb(i);
		}
	}
	ss[p1].clear();
}
ll getans(ll node)
{
	ll pp=getpar(node);	
	pii zz=*(ss[pp].rbegin());
	cout<<zz.F<<endl;	
	auto it=ss[pp].rbegin();
	ss[pp].erase(zz);
	val[zz.S]=0;	
	ss[pp].insert({val[zz.S],zz.S});
	return zz.F;
}