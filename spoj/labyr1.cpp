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

vector<string> a;
int n,m;
int ans[1005][1005]; 
bool vis[1005][1005];

void dfs(int i,int j,int d)
{
    if(i>=0 && j>=0 && i<n && j<m)
    {
        if(vis[i][j])
        return;
        vis[i][j]=true;
        if(a[i][j]=='.')
        {
            ans[i][j]=d;
            dfs(i+1,j,d+1);
            dfs(i,j+1,d+1);
            dfs(i-1,j,d+1);
            dfs(i,j-1,d+1);
        }
    }
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        a.resize(n);
        rep(i,n,0)
        cin>>a[i];
        memset(ans,-1,sizeof ans);
        memset(vis,false,sizeof vis);
        int f=0;
        rep(i,n,0)
        rep(j,m,0)
        {
            if(a[i][j]=='.')
            {
                dfs(i,j,0);
                f=1;
                break;
            }
            if(f)
            break;
        }
        int t1=0,t2=0;
        rep(i,n,0)
        rep(j,m,0)
        t1=max(t1,ans[i][j]);
        
        f=0;
        rep(i,n,0)
        rep(j,m,0)
        {
            if(ans[i][j]==t1)
            {
                memset(ans,-1,sizeof ans);
                memset(vis,false,sizeof vis);
                dfs(i,j,0);
                f=1;
                break;
            }
            if(f)
            break;
        }
        rep(i,n,0)
        rep(j,m,0)
        t2=max(t2,ans[i][j]);   
        cout<<"Maximum rope length is "<<t2<<"."<<endl;
    }
}
