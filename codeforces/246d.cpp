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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    set <int> a[100005];
    vi col(n);
     int lo=0,mini=inf;
    rep(i,n,0)
    {
        cin>>col[i];
        mini=min(mini,col[i]);
    }
    signed int ans=0,ma=0;
    int x,y;

    rep(i,m,0)
    {
        cin>>x>>y;
        lo=max(lo,max(col[x-1],col[y-1]));
        if(col[x-1]!=col[y-1])
        {
            a[col[x-1]].insert(col[y-1]);
            a[col[y-1]].insert(col[x-1]);
        }
    }
    lli tans=0;
    rep(i,lo+1,0)
    {
        if(a[i].size()>tans)
        {
            tans=a[i].size();
            ans=i;
        }   
    }
    if(ans==0)
    ans=mini;
    cout<<ans<<endl;
}