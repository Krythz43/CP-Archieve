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
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)if(a[i][j]==INT_MAX)cout<<0<<" ";else cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    lli adj[70][70],dp[70][70];

    rep(i,70,0)rep(j,70,0)adj[i][j]=inf;

    bitset<65> bts;
    lli x,n;
    cin>>n;
    rep(I,n,0){
        cin>>x;
        bts=x;   
        cout<<bts<<" "<<bts[0]<<endl;   
        rep(i,bts.size(),0)
        rep(j,bts.size(),i+1){
            if(bts[i]==1 && bts[i]==bts[j])adj[i][j]=adj[j][i]=1;
        }
    }
    // for (int k = 0; k < 70; k++)    
    // for (int i = 0; i < 70; i++)  
    // for (int j = 0; j < 70; j++)
    // if (adj[i][k] + adj[k][j] < adj[i][j])  adj[i][j] = adj[i][k] + adj[k][j];

    lli ans=inf/2;

    displaymatrix(adj,6,6)

    for(int i=0;i<70;i++)for(int j=i+1;j<70;j++){
        if(adj[i][j]!=inf){
            rep(l,70,0)rep(m,70,0)dp[l][m]=adj[l][m];
            dp[i][j]=dp[j][i]=inf;

            cout<<i<<' '<<j<<endl;
            cout<<dp[i][j]<<endl;

            for (int r = 0; r < 70; r++)    
            for (int p = 0; p < 70; p++)  
            for (int q = 0; q < 70; q++)
            if (dp[p][r] + dp[r][q] < dp[p][q]) dp[p][q] = dp[p][r] + dp[r][q];

            cout<<dp[i][j]<<endl;
            nl;

            ans=min(ans,dp[i][j]);
        }
    }

    if(ans==inf/2)cout<<-1<<endl;
    else cout<<ans+1<<endl;
}