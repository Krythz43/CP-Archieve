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
lli llmax(lli a,lli b){if(a>b)return a; return b;}

bool hit(ipair a, ipair b)
{
    return a.ff<b.ff;
}

bool comp(ipair a, ipair b)
{
    if(a.ff<b.ff)
    return true;
    if(a.ff>b.ff)
    return false;
    return a.ss<b.ss;    
}

int main()
{
    fastio;
    int p,s;
    cin>>p>>s;

    vector<ipair>ans;
    vector<ipair>a(s);

    rep(i,p+1,1)
    {
        rep(j,s,0)cin>>a[j].ff;
        rep(j,s,0)cin>>a[j].ss;
        sort(a.begin(),a.end(),hit);

        int c=0;
        rep(j,s-1,0)if(a[j].ss>a[j+1].ss)c++;
        // cout<<c<<" of ";
        ans.pb(mp(c,i));
    } 
    
    // nl;
    sort(ans.begin(),ans.end(),comp);

   

    rep(i,p,0)
    cout<<ans[i].ss<<endl;
}