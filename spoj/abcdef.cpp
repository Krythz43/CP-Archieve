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
    map<lli,lli> lh,rh;
    map<lli,lli> :: iterator it;

    int n;
    cin>>n;
    vinput(a,n);
    rep(i,n,0)
    rep(j,n,0)
    rep(k,n,0)
    lh[a[i]*a[j]+a[k]]++;
    
    rep(i,n,0)
    rep(j,n,0)
    rep(k,n,0)
    {
        if(a[k]!=0)
        rh[(a[i]+a[j])*a[k]]++;
    }

    lli ans=0;

    for(it=lh.begin();it!=lh.end();it++)
    {
        // cout<<(*it).first<<" "<<(*it).second<<" "<<rh[(*it).first]<<endl;
        ans+=(((*it).second)*(rh[(*it).first]));
    }

    cout<<ans<<endl;
}