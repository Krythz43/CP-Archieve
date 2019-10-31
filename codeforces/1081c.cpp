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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}
#define S 2005
lli mod=998244353;

lli memo[S][S][2];
lli m;


lli solve(lli n,lli k,lli oc)
{

    if(memo[n][k][oc]!=-1)
    return memo[n][k][oc];


    if(n<0 || k<0)
    return -1;

    if(n==1 && k>0)
    return memo[n][k][oc]=0;

    if(n==1)
    {
        return memo[n][k][oc]=1;
    }

    if(k==0)
    {
        return memo[n][k][oc]=1;
    }

    return memo[n][k][oc]=(solve(n-1,k,0)%mod + (m-1)*solve(n-1,k-1,1)%mod)%mod;

}

int main()
{
    fastio;
    lli n,k;
    cin>>n>>m>>k;
    memset(memo,-1,sizeof memo);
    cout<<(m*solve(n,k,0))%mod<<endl;
}