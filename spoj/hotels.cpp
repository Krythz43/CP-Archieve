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


int main()
{
    fastio;
    lli n,m;
    cin>>n>>m;
    vlli a(n+1),su(n+1,0);
    rep(i,n+1,1)
    {
        cin>>a[i];
        su[i]=su[i-1]+a[i];
    }

    lli ans=0;

    int p1=1,p2=1;
    while(1)
    {
        if(p1>n || p2>n)
        break;

        if(su[p2]-su[p1-1]<=m)
        ans=max(ans,su[p2]-su[p1-1]);

        // cout<<p1<<" "<<p2<<" "<<su[p2]<<" "<<su[p1-1]<<endl;
        if(su[p2]-su[p1-1]>m)
        p1++;
        else
        p2++;
    }
    cout<<ans<<endl;
}