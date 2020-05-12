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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    vlli is,ie;
    int c=1;
    is.pb(c);
    ie.pb(c);
    rep(i,n,1){
        if(a[i]>a[i-1]){
            c++;
        }
        else{
            c=1;
        }
        is.pb(c);
    }
    c=1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            c++;
        }
        else{
            c=1;
        }
        ie.pb(c);
    }
    reverse(all(ie));
    lli ans=0;
    rep(i,n,0)ans=max(ans,is[i]);
    rep(i,n-1,1){
        if(a[i+1]>a[i-1])
        ans=max(ans,is[i-1]+ie[i+1]);
    }

    cout<<ans<<endl;
    // printarray(is,n)
    // printarray(ie,n)
}