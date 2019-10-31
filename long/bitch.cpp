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

#define S 1000005
int n,m;
vi a[S],layer[S];
int maxd=0;
vector <bool> vis(S,false);


void dfs(int i,int d)
{
    if(vis[i])
    return;
    vis[i]=true;
    maxd=max(maxd,d);
    layer[d].pb(i);

    for(int j=0;j<a[i].size();j++)
    {
        if(vis[a[i][j]]==false)
        dfs(a[i][j],d+1);
    }
}

int main()
{
    fastio;
    cin>>n>>m;
    int x,y;
    rep(i,m,0)
    {
        cin>>x>>y;
        a[x].pb(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        dfs(i,0);
    }

    int ans=0;

    for(int i=maxd;i>=0;i--)
    ans+=layer[i].size()/2+layer[i].size()%2;

    cout<<ans<<endl;

    for(int i=maxd;i>=0;i--)
    {
        for(int j=layer[i].size()-1;j>=0;)
        {
            if(j>0)
            {
                cout<<2<<" "<<layer[i][j]<<" "<<layer[i][j-1]<<endl;
                j-=2;
            }
            else
            {
                cout<<1<<" "<<layer[i][j]<<endl;
                j--;
            }
        }
    }

}