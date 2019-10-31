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

vector<string> a;
int memo[55][55];
int n,m;

int dfs(int i,int j)
{
    int tans=0;
    int &val=memo[i][j];
    if(val!=-1)
    return val;
    int x,y;

    vector<ipair> dir={ {-1,-1},{-1,0},{-1,1},{0,-1},{0,1}, {1,-1},{1,0},{1,1} };
    for(int z=0;z<dir.size();z++)
    {
        x=i+dir[z].ff;
        y=j+dir[z].ss;
        if(x>=0 && y>=0 && x<n && y<m)
        {
            if(a[x][y]-a[i][j]==1)
            tans=max(tans,dfs(x,y));
        }
    }
    return val=1+tans;
}

int main()
{
    fastio;
    for(int t=0;;t++)
    {
        cin>>n>>m;
        memset(memo,-1,sizeof memo);
        if(n==0)
        break;
        a.clear();
        a.resize(n);
        rep(i,n,0)
        cin>>a[i];
        int ans=0;
        rep(i,n,0)
        rep(j,m,0)
        if(a[i][j]=='A')
        ans=max(ans,dfs(i,j));

        cout<<"Case "<<t+1<<": "<<ans<<endl;
    }
}