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
#define ipair pair <lli,lli>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(lli i=0;i<m;i++){for(lli j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(lli i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

lli n;
vector<llipair> a[10005];
bool vis[10005];
vector <long long int> dist;

void dij(lli start,lli end)
{
    memset(vis,false,sizeof vis);
    priority_queue<pair<lli,lli>,vector<ipair>,greater<ipair>> PQ;
    dist.clear();
    dist.resize(n+5,inf/2);
    PQ.push(mp(0,start));
    lli x,w;
    dist[start]=0;
    llipair z;
    while(!PQ.empty())
    {
        z=PQ.top();
        PQ.pop();
        if(vis[z.ss])
        continue;
        x=z.ss;
        w=z.ff;
        vis[x]=true;
        // cout<<"connected to "<<a[x].size()<<" cities"<<endl;
        for(auto i:a[x])
        {
            lli e=i.ss;
            lli wei=i.ff;
            if(!vis[e] && wei+dist[x]<dist[e])
            {
                dist[e]=dist[x]+wei;
                PQ.push(mp(dist[e],e));
                // cout<<"updating distance of "<<e<<" to "<<dist[e]<<endl;
            }
        }

        if(x==end)
        return;
    }
}


int main()
{
    fastio;
    lli t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        lli x,y,w;
        map <string,lli> city;
        rep(i,n+1,1)
        {
            cin>>s;
            city[s]=i;
            cin>>x;
            while(x--)
            {
                cin>>y>>w;
                a[i].pb(mp(w,y));
                // a[y].pb(mp(w,i));
            }
        }

        lli r;
        cin>>r;
        while(r--)
        {
            string s1,s2;
            cin>>s1>>s2;
            dij(city[s1],city[s2]);
            cout<<dist[city[s2]]<<endl;
        }
    }
}
