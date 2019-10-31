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



int main()
{
    fastio;
    int n;
    cin>>n;
    vector<lli> a1,a2,a3,a4;
    lli x;
    unordered_map<lli,lli> b;
    b.reserve(16000000);
    lli ans=0;
    rep(i,n,0)
    {
        cin>>x;
        a1.pb(x);
        cin>>x;
        a2.pb(x);
        cin>>x;
        a3.pb(x);
        cin>>x;
        a4.pb(x);
    }

    vector<lli> a;
    rep(i,a3.size(),0)
    rep(j,a4.size(),0)
    b[a3[i]+a4[j]]++;

    rep(i,a1.size(),0)
    rep(j,a2.size(),0)
    {
        x=b.count(-(a1[i]+a2[j]));
        if(x>0)
        ans+=b[-(a1[i]+a2[j])];
    }

    cout<<ans<<endl;
}