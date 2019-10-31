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
    lli n;
    vlli s,e;
    cin>>n;
    vlli a(n/2);
    rep(i,n/2,0)
    cin>>a[i];

    s.pb(0);
    e.pb(a[0]);
    lli cmin=0,cmax=a[0];

    rep(i,n/2,1)
    {
        if(a[i]>cmin+cmax)
        {
            e.pb(cmax);
            cmin=a[i]-cmax;
            s.pb(cmin);
        }
        else
        {
            s.pb(cmin);
            e.pb(a[i]-cmin);
            cmax=a[i]-cmin;

        }
    }

    rep(i,s.size(),0)
    cout<<s[i]<<" ";
    for(int i=e.size()-1;i>=0;i--)
    cout<<e[i]<<" ";
    nl;
}