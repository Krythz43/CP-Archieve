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
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();
    int cnt=0;
    rep(i,m,0)
    {
        if(a[i]!=b[i])  cnt=cnt^1;
    }
    int p=0;
    for(int i=1;i<m;i++)
    {
        if(a[i]!=a[i-1])
            p=p^1;
    }
    int ans=0;
    if(cnt%2==0)    ans++;
    for(int i=m;i<n;i++)
    {
        if(a[i]!=a[i-1])    p=p^1; 
        cnt=cnt^p;
        if(!cnt)    ans++;
        if(a[i-m]!=a[i-m+1])    p=p^1;
    }
    cout<<ans<<endl;
}