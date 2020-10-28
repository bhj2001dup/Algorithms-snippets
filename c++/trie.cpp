ll trie[N][30]={0},sz=1;
vi isend(N*30);
void add(string s)
{
	ll cur=1;
	rep(i,0,sz(s))
	{
		ll id=s[i]-'a';
		if(trie[cur][id]==0) trie[cur][id]=++sz;
		cur=trie[cur][id]; 
	}
	isend[cur]=1;
}

ll find(string s)
{
	ll cur=1;
	rep(i,0,sz(s))
	{
		ll id=s[i]-'a';
		if(trie[cur][id]==0) return 0;
		else cur=trie[cur][id]; 		
	}
	if(isend[cur]) return 1;
	else return 0;
}