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

#define S 150005
vi a[S];
vector <bool> vis(S,false);

int n;
int c=0;

int tx=0;

void bfs(int x)
{
    if(vis[x]==false)
    {
        if(c==n)
        return;
        vis[x]=true;
        cout<<x<<" ";
        c++;
    }
    for(auto y:a[x])
    {
        tx++;
        if(vis[y]==false)
        bfs(y);
    }
}

int main()
{
    fastio;
    int x,y;
    cin>>n;
    rep(i,n-1,0)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    int s;

    rep(i,n+1,1)
    {
        if(a[i].size()==1)
        {
            s=i;
            break;
        }
    }

    bfs(s);
    nl;
    cout<<tx<<endl;
}