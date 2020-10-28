class convexHull
{
public:
    vector<pair<ll,ll> > lines;

    static bool intersect(pair<ll,ll> p1,pair<ll,ll> p2,pair<ll,ll> p3)
    {
        return (ld)(p1.second - p2.second)/(ld)(p2.first - p1.first) > (ld)(p1.second - p3.second)/(ld)(p3.first - p1.first);
    }
    
    void addLine(pair<ll,ll> newLine)
    {
        while(!lines.empty() and lines.back().first==newLine.first and lines.back().second<=newLine.second) //change here for MIN
            lines.pop_back();
        while((ll)lines.size()>1LL and !intersect(lines[(ll)lines.size()-2LL],lines.back(),newLine)) // remove ! for MIN
            lines.pop_back();
        if(lines.empty() or lines.back().first != newLine.first)
            lines.push_back(newLine);

    }

    ll getMax(ll valx)
    {
        ll L =0,R=(ll)lines.size()-1,mid;
        ll maxi = LLONG_MIN;    //Change here
        while(L<=R)
        {
            mid = (L+R)/2;
            maxi = max(maxi,lines[mid].first*valx+lines[mid].second);
            if(mid+1<=R and lines[mid].first*valx+lines[mid].second > lines[mid+1].first*valx+lines[mid+1].second)  //Change here
                R = mid;
            else if(mid+1<=R)
                L = mid+1;
            else
                break;
        }
        return maxi;
    }
};