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
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}


vector <int> a[1000005];
vi g(100005);
vector <bool> vis(100005);
vector <bool> isblocked(100005,false);

void bfs(int x,int y)
{
    queue <ipair > q;
    q.push(mp(x,0));
    int layer=0;
    while(q.empty()==false)
    {
        t=q.pop();
        for(int i=0;i<a[t.ff].size();i++)
        {
            if(a[t.ff][i]==y)
            {
                if(t.ss%2)

            }
        }        
    }
}

int main()
{
    fastio;
    int n,m,t,x,y,v;
    cin>>n>>m;
    rep(i,n+1,1)
    cin>>g[i];

    while(m--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            g[x]=y;
        }
        else if(t==2)
        {
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);

            bfs(x,y);

            if(isblocked[x] || isblocked[y])
            {
                isblocked[x]=true;
                isblocked[y]=true;
            }
        }
        else
        {

            if(isblocked[x] || isblocked[y])
            cout<<"0"<<endl;
            else
            {
                rep(i,n+1,1)
                vis[i]=false;
            }

        }
    }
}