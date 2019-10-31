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
#define endl '\n'

lli p,n,m,z,b,c;

vector<llipair> a[1005];
bool vis[1005];

lli prims()
{
    lli ans=0;
    priority_queue<ipair,vector<ipair>,greater<ipair> > PQ;
    PQ.push(mp(0,1));
    llipair x;
    lli w,n;
    while(!PQ.empty())
    {
        x=PQ.top();
        PQ.pop();
        if(vis[x.ss])
        continue;
        // cout<<"connecting "<<x.ss<<" weight "<<x.ff<<endl;

        n=x.ss;
        w=x.ff;

        ans+=w;
        vis[n]=true;

        for(auto i:a[n])
        {
            if(vis[i.ss]==false)
            PQ.push(i);
        }
    }
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>p>>n>>m;
        rep(i,n+1,0)
        a[i].clear();
        memset(vis,false, sizeof vis);
        rep(i,m,0)
        {
            cin>>z>>b>>c;
            a[z].pb(mp(c,b));
            a[b].pb(mp(c,z));
        }

        cout<<p*prims()<<endl;
    }
}