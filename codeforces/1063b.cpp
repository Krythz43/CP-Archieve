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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
// #define endl '\n'

int main()
{
    fastio;
    int n,m,r,c,x,y;
    cin>>n>>m>>r>>c>>x>>y;
    vector<string> a(n);
    rep(i,n,0)
    cin>>a[i];
    bool vis[2005][2005];
    ipair maxh[2005][2005];
    memset(vis,0,sizeof vis);
    // function<void<int,int,int,int>>bfs=[&](int r,int c,int x,int y)->void{
        
    // }
    // bfs(r,c,0,0);   
    queue<pair<ipair,ipair>> Q;
    Q.push(mp(mp(r,c),mp(0,0)));
    lli ans=0;
    while(!Q.empty()){
        pair<ipair,ipair> temp=Q.front();
        Q.pop();
        int r1=temp.ff.ff,c1=temp.ff.ss,x1=temp.ss.ff,y1=temp.ss.ss;
        if(vis[temp.ff.ff][temp.ff.ss] && (maxh[r1][c1].ff<=x1 && maxh[r1][c1].ss<=y1))continue;
        if(a[r1-1][c1-1]=='*')continue;
        if(!vis[r1][c1])ans++;
        vis[r1][c1]=true;
        maxh[r1][c1]=mp(x1,y1);
        // cout<<"reached "<<r1<<" "<<c1<<":"<<ans<<" "<<Q.size()<<endl;
        //up
        if(r1!=1)Q.push(mp(mp(r1-1,c1),mp(x1,y1)));
        //down
        if(r1!=n)Q.push(mp(mp(r1+1,c1),mp(x1,y1)));
        //left
        if(c1!=1)if(x>x1)Q.push(mp(mp(r1,c1-1),mp(x1+1,y1)));
        //right
        if(c1!=m)if(y>y1)Q.push(mp(mp(r1,c1+1),mp(x1,y1+1)));
    }
    cout<<ans<<endl;
}