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

#define mod 1000000007

vi a[100005];
vector<bool> vis(100005);

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
    lli n,m,t;
    cin>>t;
    while(t--)
    {
        int x,y;
        int z=0;
        cin>>n>>m;
        vector<int> ans;
         rep(i,n,0)
        {vis[i]=false;
        a[i].clear();}
        
        rep(i,m,0)
        {
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
        }



        rep(i,n,0)
        {
            if(vis[i]==false)
            {
                z++;
                dfs(i);
                ans.pb(z);
            }
        }


        cout<<z<<endl;
    }
}