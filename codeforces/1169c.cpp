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


int n,m;
vi a;

bool F(int x)
{
    int mine=a[0],sr;
    if(a[0]+x>=m)
    mine=0;

    rep(i,a.size(),1)
    {
        if(a[i]<mine && a[i]+x<mine)
        return false;
        if(a[i]<=mine)continue;
        if(a[i]+x<m || a[i]+x-m<mine)
        {
            mine=a[i];
        }
    }
    return true;
}

int main()
{
    fastio;
    cin>>n>>m;
    a.resize(n);
    rep(i,n,0)
    cin>>a[i];
    int lo=0,hi=m-1,mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(F(mid))
        hi=mid;
        else
        lo=mid;
    }
    if(F(lo))
    cout<<lo<<endl;
    else
    cout<<hi<<endl;
}
