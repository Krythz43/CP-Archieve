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

int main()
{
    fastio;
    lli n,a;
    cin>>n>>a;
    vi ans;
    while(a)
    {
        int x=a%10;
        if(x==2)
        ans.pb(2);
        if(x==3)
        ans.pb(3);
        if(x==4)
        {
            ans.pb(2);
            ans.pb(2);
            ans.pb(3);
        }
        if(x==5)
        ans.pb(5);
        if(x==6)
        {
            ans.pb(5);
            ans.pb(3);
        }
        if(x==7)
        ans.pb(7);
        if(x==8)
        {
            ans.pb(2);
            ans.pb(2);
            ans.pb(2);
            ans.pb(7);
        }
        if(x==9)
        {
            ans.pb(3);
            ans.pb(3);
            ans.pb(2);
            ans.pb(7);
        }
        a/=10;
    }
    sort(ans.begin(),ans.end());
    rrep(i,ans.size()-1)
    cout<<ans[i];
    
}