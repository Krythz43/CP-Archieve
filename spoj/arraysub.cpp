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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
int n,q;
vi a(100005);
vi tree(400010);


void build(int nodei,int l,int r) 
{ 
    if(l==r)
    {tree[nodei]=a[l];
        // cout<<"inserting "<<tree[nodei]<<" at position "<<nodei<<endl;
    }
    else
    {
        int mid=l+r;
        mid=mid>>1;
        build(2*nodei,l,mid);
        build(2*nodei+1,mid+1,r);
        tree[nodei]=max(tree[2*nodei],tree[2*nodei+1]);
        // cout<<"inserting "<<tree[nodei]<<" at position "<<nodei<<endl;
    }
}

int query(int node, int le,int ri, int l,int r)
{
    if(le>r || l>ri)
    return -1;
    
    if(l<=le && r>=ri)
    {
        return tree[node];
    }
    
    int mid=le+ri;
    mid=mid>>1;
    int p1=query(2*node,le,mid,l,r);
    int p2=query(2*node+1,mid+1,ri,l,r);
    return max(p1,p2);
}

int main()
{
    fastio;
    cin>>n;

    rep(i,n,0)
    cin>>a[i];
    
    build(1,0,n-1);

    int k;
    cin>>k;
    int l,r;
    for(int i=1;i<n-k+2;i++)
    {
        l=i;
        r=i+k-1;
        cout<<query(1,0,n-1,l-1,r-1)<<" ";
    }
    nl;
    // printarray(tree,2*n+1)
}