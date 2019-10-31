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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

const int S=200005;

vi adj[S];
vlli a,cre;
int f=1,po=1;
map<ipair,int> M;
int n;
vector <bool> vis(S,false);

void bfs(int id)
{
    vis[id]=true;
    queue<int> q;
    q.push(id);
    while(!q.empty())
    {
        int te=q.front();
        q.pop();
        int x=te;
        cre.pb(x);
        vis[x]=true;
        while(po<n)
        {
            if(M.count(mp(x,a[po])))
            {
                q.push(a[po]);
                vis[a[po]]=true;
                po++;
            }
            else
            break;
        }

        for(auto z: adj[x])
        {
            if(vis[z]==false)
            q.push(z);
        }
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
        adj[x].pb(y);
        adj[y].pb(x);
        M[mp(x,y)]++;
        M[mp(y,x)]++;
    }
    a.resize(n);
    ainput(a,n);
    bfs(1);

    // rep(i,cre.size(),0)
    // cout<<cre[i]<<" ";
    // nl;
    if(a.size()!=cre.size())
    {
        cout<<"No"<<endl;
        return 0;
    }
    rep(i,n,0)
    if(a[i]!=cre[i])
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}
