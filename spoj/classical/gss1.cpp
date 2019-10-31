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

struct tr{
    int cmax;
    int sum;
    int lsum;
    int rsum;
};

vi a(50005);
vector <tr> tree(200020);

tr merge(tr a, tr b)
{
    tr temp;
    temp.sum= a.sum + b.sum;
    temp.cmax=max(max(a.cmax,b.cmax),a.rsum+b.lsum);
    temp.lsum=max(a.lsum,a.sum+b.lsum);
    temp.rsum=max(b.rsum,b.sum+a.rsum);
    return temp;
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].cmax=a[l];
        tree[node].lsum=tree[node].rsum=tree[node].sum=a[l];
        // cout<<"inserting "<<tree[node].sum<<" at position "<<node<<endl;
    }
    else
    {
        int mid=(l+r)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
        // cout<<"inserting "<<tree[node].sum<<" at position "<<node<<endl;
    }
}

tr query(int node,int le,int ri,int l,int r)
{
    // cout<<"querying "<<le<<":"<<ri<<endl;
    if(ri==r && le==l)
    return tree[node];

    int mid=(le+ri)/2;
    if(r<=mid)
    return query(2*node,le,mid,l,r);
    else if(l>=mid)
    return query(2*node+1,mid+1,ri,l,r);
    else
    return merge(query(2*node,le,mid,l,r),query(2*node+1,mid+1,ri,l,r));
}

int main()
{
    int n,x,y;
    scanf("%d",&n);
    rep(i,n,0)
    scanf("%d",&a[i]);
    build(1,0,n-1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d", &x,&y);
        tr t=query(1,0,n-1,x-1,y-1);
        printf("%d\n",max(t.sum,max(t.cmax,max(t.lsum,t.rsum))));
    }
}

