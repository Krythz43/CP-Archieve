#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

vlli a,b;
lli n,m;
vector <pair<lli,lli>> z;

lli F(lli r)
{
    lli c=0;
    rep(i,n,0)
    {
        if(z[i].ff>r)
        {
            c+=(z[i].ff-r)/z[i].ss;
            if((z[i].ff-r)%z[i].ss)
            c++;
            // cout<<"c print "<<c<<endl;
        }
    }
    return c;
}

int main()
{
    fastio;
    cin>>n>>m;
    lli sum=0;

    a.resize(n);
    b.resize(n);
    ainput(a,n);
    ainput(b,n);

    rep(i,n,0)
    {
        z.pb(mp(a[i]*b[i],b[i]));
        sum+=a[i];
    }
    SO(z);
    
    if(sum<=m)
    {
        cout<<0<<endl;
        return 0;
    }

    if(m==0)
    {
        cout<<z[n-1].ff<<endl;
        return 0;
    }

    lli lo=0,hi=z[n-1].ff,mid;

    while(hi-lo>1)
    {
        mid=lo+(hi-lo+1)/2;

        if(F(mid)<=m)
        hi=mid;
        else
        lo=mid;
    }

    // rep(i,25,0)
    // {
    //     cout<<i<<" "<<F(i)<<endl;
    // }
    if(F(hi)<=m)
    cout<<hi;
    else
    cout<<lo;
    nl; 
}
// 5 4 1 2 3 4 5 1 2 3 4 5
// 5 2 0 0 0 6 7 1 2 3 4 5