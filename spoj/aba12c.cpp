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

int n,k;
vlli a;
bool ok;
lli dp[105][105];

lli solve(int packs,int id)
{
    if(id<0 || packs<0)
    return inf;
    lli &ans=dp[packs][id];
    if(ans!=-1)
    {
        // cout<<"returning state "<<id<<" as "<<ans<<endl;
        return ans;
    }

    ans=inf;
    if(id==0)
    {
        ok=true;
        // cout<<"returning state "<<packs<<","<<id<<" as "<<ans<<endl;
        return ans=0;
    }


    if(packs==0)
    {
        // cout<<"returning state "<<packs<<","<<id<<" as "<<ans<<endl;
        return ans;
    }

    rep(i,a.size(),0)
    {
        if(i<=id && a[i]!=-1)
        {
            ans=min(ans,a[i]+solve(packs-1,id-1-i));
        }
        if(i>id)
        break;
    }
    // cout<<"returning state "<<packs<<","<<id<<" as "<<ans<<endl;
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        a.resize(k);
        rep(i,k,0)
        cin>>a[i];
        ok=false;
        memset(dp,-1,sizeof dp);
        solve(n,k);
        // printarray(dp,k)
        if(ok)
        cout<<dp[n][k]<<endl;
        else 
        cout<<-1<<endl;
    }
}
