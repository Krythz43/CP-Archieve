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


bool comp(pair<vector<llipair > , int> a, pair<vector<llipair > , int>  b)
{
    int l=a.ff.size();
    for(int i=l-1;i;i--)
    {
        if(a.ff[i].ss>b.ff[i].ss)
        return true;
        if(a.ff[i].ss<b.ff[i].ss)
        return false;
    }
    return a.ss<b.ss;
}

bool hit(llipair a, llipair b)
{
    return a.ff<b.ff;
}

int main()
{
    fastio;
    int p,s;
    cin>>p>>s;
    vector<     pair<vector<llipair>  ,int>      > a;
    vector<llipair > t(s);
    
    rep(i,p+1,1)
    {
        rep(j,s,0)cin>>t[j].ff;
        rep(j,s,0)cin>>t[j].ss;    
        sort(t.begin(),t.end(),hit);
        a.pb(mp(t,i));
    }

    sort(a.begin(),a.end(),comp);

    rep(i,p,0)
    {
        rep(j,s,0)cout<<a[i].ff[j].ff<<" ";nl;
        rep(j,s,0)cout<<a[i].ff[j].ss<<" ";nl;   
    }

    rep(i,a.size(),0)
    cout<<a[i].ss<<endl;
}