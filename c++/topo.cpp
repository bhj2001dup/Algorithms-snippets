ll n,m,cnt=0;
vi a[N],in(N,0),order;
set<ll> nextnode;

void topsort()
{
	rep(i,1,n+1)
	if(!in[i])
		nextnode.insert(i);
	while(!nextnode.empty())
	{
		ll cur=*nextnode.begin();
		nextnode.erase(cur);
		order.pb(cur);
		cnt++;
		for(auto i:a[cur])
		{
			in[i]--;
			if(!in[i])
				nextnode.insert(i);
		}
	}
	if(cnt!=n) //Failed
	{
		
	}
}