ll seg[50*N],lc[50*N],rc[50*N];
ll ct;
ll root[50*N];
ll build(ll L, ll R)
{
    ll node = ++ct;
    if(L==R)
        return node;
    ll M = (L+R)/2;
    lc[node] = build(L, M);
    rc[node] = build(M+1, R);
    return node;
}
 
ll update(ll curnode, ll L, ll R, ll pos, ll val)
{
    ll node = ++ct;
    if(L==R)
    {
        seg[node] = seg[curnode] + val;
        return node;
    }
    ll M = (L+R)/2;
    lc[node] = lc[curnode];
    rc[node] = rc[curnode];
    if(pos<=M)
        lc[node] = update(lc[curnode], L, M, pos, val);
    else
        rc[node] = update(rc[curnode], M+1, R, pos, val);
    seg[node] = seg[lc[node]] + seg[rc[node]];
    return node;
}
 
ll query(ll node, ll L, ll R, ll i, ll j)
{
    if(j<L || i>R)
        return 0;
    if(i<=L && R<=j)
        return seg[node];
    ll M = (L+R)/2;
    return query(lc[node], L, M, i, j) + query(rc[node], M+1, R, i, j);
}