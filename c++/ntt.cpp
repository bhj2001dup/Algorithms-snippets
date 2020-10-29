const int mod=998244353;    
const int root=565042129;   // nth root of mod
const int root_1=950391366; // inverse of root
const int root_pw=1<<20;    // value of n
void fft(vi&a,bool invert){
    int i,j,n=(int)a.size();
    for(i=1,j=0;i<n;++i){
        int bit=n>>1;
        for(;j>=bit;bit>>=1){
            j-=bit;
        }
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len<<=1){
        int wlen=invert?root_1:root;
        for(i=len;i<root_pw;i<<=1){
            wlen=(wlen*wlen%hell);
        }
        for(i=0;i<n;i+=len){
            int w=1;
            for(j=0;j<len/2;++j){
                int u=a[i+j],v=(int)(a[i+j+len/2]*w%hell);
                a[i+j]=(u+v+hell)%hell;
                a[i+j+len/2]=(u-v+hell)%hell;
                w=(w*wlen%hell);
            }
        }
    }
    if(invert){
        int nrev=expo(n,hell-2);
        for(i=0;i<n;++i){
            a[i]=(a[i]*nrev%hell);
        }
    }
}
void multiply(const vi &a,const vi &b,vi &res){
    vi fa(a.begin(),a.end()),fb(b.begin(),b.end());
    size_t n=1;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<= 1;
    fa.resize(n),fb.resize(n);
    fft(fa,false),fft(fb,false);
    for(size_t i=0;i<n;++i){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for(size_t i=0;i<n;++i){
        res[i]=fa[i];
    }
}