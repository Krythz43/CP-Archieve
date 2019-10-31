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

lli memo[1005][2];
vlli a;
int n;

lli solve(int n, int id)
{
    
    lli & ans= memo[n][id];
    if(ans!=-1)
    return ans;
    if(n==0)
    {
        if(id)
        return ans=0;
        else
        return ans=a[n];
    }
    
    if(id==1)
    return ans=solve(n-1,0);

    return ans=max(solve(n-1,0),solve(n-1,1)+a[n]);
}

int main()
{
    fastio;
    int t;
    cin>>t;
    rep(z,t,0)
    {
        cin>>n;
        memset(memo,-1,sizeof memo);
        a.resize(n);
        rep(i,n,0)
        cin>>a[i];
        cout<<"Case "<<z+1<<": "<<solve(n-1,0)<<endl;
    }
}