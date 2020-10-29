void dnc(ll l,ll r,ll optl,ll optr)
{
    if(l>r)
        return ;
    ll mid=(l+r)/2;
    ll res=1e18,idx=-1;
    ll st=optl;
    ll en=min(optr,mid);
    rep(i,st,en+1)
    {
        // Add your cost function Here.
        ll ccst1=(mid-i+1)*cost[mid]-(pscost[mid]-pscost[i-1]);        
        ll ccst=dp_before[i-1]+ccst1;
        if(ccst<res)
        {
            res=ccst;
            idx=i;
        }
    }
    dp_curr[mid]=res;    
    if(l!=r)
    {
        dnc(l,mid-1,optl,idx);
        dnc(mid+1,r,idx,optr);
    }
}