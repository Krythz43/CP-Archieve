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


vector <int> a[10005];
vector <bool> vis(10005,false);

void dfs(int i)
{
    vis[i]=true;
    rep(j,a[i].size(),0)
    {
        if(vis[a[i][j]]==false)
        {
            dfs(a[i][j]);
        }
    }
}

int main()
{
    fastio;
    int n,m,x,y;
    cin>>n>>m;

    rep(i,m,0)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    dfs(1);

    rep(i,n+1,1)
    {
        if(vis[i]==false)
        {
            cout<<"NO";
            return 0;
        }
    }

    if(m==n-1)
    cout<<"YES";
    else
    cout<<"NO";
}