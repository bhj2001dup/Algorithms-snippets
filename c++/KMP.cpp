vi LPS(string pat)
{

	vi lps(sz(pat));
	lps[0]=0;
	ll len=0;
	ll i=1;
	while(i<sz(pat))
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len)
				len=lps[len-1];
			else
				lps[i]=0,i++;
		}
	}
	return lps;
}

vi KMP(string pat,string txt)
{
	vi lps=LPS(pat);
	vi ans;
	ll i=0,j=0;
	while(i<sz(txt))
	{
		if(pat[j]==txt[i]) i++,j++;
		if(j==sz(pat)) 
		{
			ans.pb(i-j+1);
			j=lps[j-1];
		}
		else if(i<sz(txt)&&txt[i]!=pat[j])
		{
			if(j)
				j=lps[j-1];
			else
				i++;
		}
	}
	return ans;
}