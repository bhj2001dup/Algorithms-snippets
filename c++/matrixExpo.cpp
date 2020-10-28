class matrix{
public:
	int n,m;
	vector<vector<ll> >  v;
	
public:
	matrix(int x,int y)
	{
		n = x;
		m = y;
		vector<ll> tempMat(m,0);
		for(int i=0;i<n;i++)
			v.push_back(tempMat);
	}

	matrix operator * (matrix const &mat2)
	{
		matrix fin(n,mat2.m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<mat2.m;k++)
					fin.v[i][k] = (fin.v[i][k] + v[i][j]*mat2.v[j][k])%hell; 
		return fin;
	}

	matrix operator + (matrix const &mat2)
	{
		matrix fin(n,m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
					fin.v[i][j] = (v[i][j] + mat2.v[i][j])%hell; 
		return fin;
	}

	matrix operator - (matrix const &mat2)
	{
		matrix fin(n,m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
					fin.v[i][j] = (v[i][j] - mat2.v[i][j])%hell; 
		return fin;
	}

	static matrix matrixExpo(matrix base,ll exponent)
	{
		matrix ans = base;
		exponent--;
		 while(exponent !=0 ) {
	        if((exponent&1) == 1) {
	            ans = ans*base ;
	        }
	        base = base*base;
	        exponent>>= 1;
	    }
	    return ans;
	}

	static void printMatrix(matrix &mat)
	{
		for(int i=0;i<mat.n;i++)
		{
			for(int j=0;j<mat.m;j++)
				cout<<mat.v[i][j]<<" ";
			cout<<'\n';
		}
	}

	static void setAll(matrix &mat,ll x)
	{
		for(int i=0;i<mat.n;i++)
			for(int j=0;j<mat.m;j++)
				mat.v[i][j] = 1;
	}

	static matrix transpose(matrix &mat)
	{
		matrix res(mat.m,mat.n);
		for(int i=0;i<mat.n;i++)
			for(int j=0;j<mat.m;j++)
				res.v[j][i] = mat.v[i][j];
		return res;
	}
};