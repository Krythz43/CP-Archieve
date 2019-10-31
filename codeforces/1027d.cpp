#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
#define vinput(a,n) vlli a(n+1);rep(i,n+1,1)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    vlli d(n+1);
    rep(i,n+1,1)
    cin>>d[i];
    vector<bool> vis(n+1,false);
    vi z(n+1,inf);
    int bf=0;

    function<int(int,int)> dfs=[&](int id,int b)->int{
        if(vis[id]==true)
        return z[id]=min(z[id],b);
        vis[id]=true;
        return z[id]=min(z[id],dfs(d[id],b));
    };

    for(int i=1;i<n+1;i++)
    {
        if(vis[i]==false)
        {
            bf++;
            z[i]=dfs(i,bf);
            if(z[i]<bf)
            bf--;
        }
    }
    vis.clear();
    vis.resize(n+1,false);
    vlli bur(bf+1,inf);
    rep(i,n+1,1)
    bur[z[i]]=min(bur[z[i]],a[i]);
    vi lol(n+1,0);
    lli ans=0,tans;
    
    function<void(int)> dfs2=[&](int id)->void{
        lol[id]++;
        vis[id]=true;
        if(lol[id]==2)
        {
            tans=min(tans,a[id]);
        }
        if(lol[id]==3)
        {
            ans+=tans;
            return;
        }
        dfs2(d[id]);
    };
    bf=1;
    rep(i,n+1,1)
    {
        if(z[i]==bf)
        {
            tans=inf;
            dfs2(i);
            bf++;
        }
    }
    cout<<ans<<endl;

}