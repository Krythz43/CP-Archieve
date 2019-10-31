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


bool comp(llipair a,llipair b)
{
    return a.ss<b.ss;
}


int main()
{
    fastio;
    lli n,x,y;
    cin>>n;
    vector <llipair> a;
    rep(i,n,0)
    {
        cin>>x>>y;
        a.pb(mp(x,y));
    }
    SO(a);
    lli c=1;
    lli ans=0;
    rep(i,n,1)
    {
        if(a[i].ff==a[i-1].ff)
        c++;
        else
        {
            ans+=c*(c-1)/2;
            c=1;
        }
    }
    ans+=c*(c-1)/2;

    // cout<<ans<<endl;

    sort(a.begin(),a.end(),comp);

    c=1;
    rep(i,n,1)
    {
        if(a[i].ss==a[i-1].ss)
        c++;
        else
        {
            ans+=c*(c-1)/2;
            c=1;
        }
    }
    ans+=c*(c-1)/2;
    // cout<<ans<<endl;

    c=1;
    rep(i,n,1)
    {
        if(a[i].ff==a[i-1].ff && a[i].ss==a[i-1].ss)
        c++;
        else
        {
            ans-=c*(c-1)/2;
            c=1;
        }
    }
    ans-=c*(c-1)/2;

    cout<<ans;

}