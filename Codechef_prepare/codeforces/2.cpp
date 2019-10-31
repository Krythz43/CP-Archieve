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
#define llpair pair <lli,lli>
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

lli n,m;
vector <llpair> a;
vector <llpair> tree(400010);
void build(lli nodei,lli l,lli r) 
{ 
    if(l==r)
    {tree[nodei].ff=a[l].ff;
    tree[nodei].ss=a[l].ss;
        // cout<<"inserting "<<tree[nodei].ff<<" and "<<tree[nodei].ss<<" at position "<<nodei<<endl;
    }
    else
    {
        lli mid=l+r;
        mid=mid>>1;
        build(2*nodei,l,mid);
        build(2*nodei+1,mid+1,r);
        tree[nodei].ff=tree[2*nodei].ff<tree[2*nodei+1].ff?tree[2*nodei].ff:tree[2*nodei+1].ff;
        tree[nodei].ss=tree[2*nodei].ss>tree[2*nodei+1].ss?tree[2*nodei].ss:tree[2*nodei+1].ss;
    //    cout<<"inserting "<<tree[nodei].ff<<" and "<<tree[nodei].ss<<" at position "<<nodei<<endl;
    }
}

lli query(lli node, lli le,lli ri, lli p)
{
    if(p<tree[node].ff)
   {
    //    cout<<"1Querying between "<<tree[node].ff<<" and "<<tree[node].ss<<" result is ";
    //    cout<<tree[node].ff-p<<endl;
        return tree[node].ff-p;}

    if(p>=tree[node].ss)
    {
        // cout<<"2Querying between "<<tree[node].ff<<" and "<<tree[node].ss<<" result is ";cout<<-1<<endl;
    return -1;}
    
    if(le==ri)
    {
        // cout<<"3Querying between "<<tree[node].ff<<" and "<<tree[node].ss<<" result is ";cout<<0<<endl;
        return 0;
    }
    
    lli mid=le+ri;
    mid=mid>>1;
    lli p1=query(2*node,le,mid,p);
    lli p2=query(2*node+1,mid+1,ri,p);
    if(p1==-1)
    {
        // cout<<"4Querying between "<<tree[node].ff<<" and "<<tree[node].ss<<" result is ";cout<<p2<<endl;
        return p2;}
    else if(p2==-1)
    {
        // cout<<"5Querying between "<<tree[node].ff<<" and "<<tree[node].ss<<" result is ";
        cout<<p1<<endl;return p1;}
    else {
        // cout<<"6Querying between "<<tree[node].ff<<" and "<<tree[node].ss<<" result is ";cout<<llmin(p1,p2)<<endl;
        // return llmin(p1,p2);
        if(p1<p2)
        return p1;
        else
        return p2;
        }
}

int main()
{
    fastio;
    lli t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        lli x,y;
        a.resize(n);
        rep(i,n,0)
        {
            cin>>x>>y;
            a[i]=mp(x,y);
        }
        sort(a.begin(),a.end());
        build(1,0,n-1);

        // rep(i,n,0)
        // {
        //     cout<<a[i].ff<<" "<<a[i].ss<<endl;
        // }

        while(m--)
        {
            lli p;
            cin>>p;
            cout<<query(1,0,n-1,p)<<endl;
        }
    }
}