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

bool comp(pair<ipair,int>  a,pair<ipair,int> b)
{
    return a.ff.ss<b.ff.ss;
}

int main()
{
    fastio;
    int n,x;
    cin>>n;
    vi a(n);
    rep(i,n,0)
    {
        cin>>a[i];
        // if(a[i]>i)
        // {
        //     cout<<"NO";
        //     return 0;
        // }
    }

    vi b(n);
    rep(i,n,0)
    {
        cin>>b[i];
        // if(b[i]>n-1-i)
        // {
        //    cout<<"NO";
        //     return 0; 
        // }
    }
    vector<pair<ipair,int> > c;
    rep(i,n,0)
    {
        x=a[i]+b[i];
        c.pb(mp(mp(x,i),1));
    }
    sort(c.begin(),c.end());
    for(int i=n-2;i>=0;i--)
    {
        if(c[i].ff.ff<c[i+1].ff.ff)
        c[i].ss=c[i+1].ss+1;
        else
        c[i].ss=c[i+1].ss;
    }

    vi d(n,0),e(n,0);

    sort(c.begin(),c.end(),comp);

    rep(i,n,0)
    {
        rep(j,i,0)
        {
            if(c[i].ss<c[j].ss)
            d[i]++;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(c[i].ss<c[j].ss)
            e[i]++;
        }
    }

    rep(i,n,0)
    {
        if(a[i]!=d[i])
        {
            cout<<"NO";
            return 0;
        }
    }

    rep(i,n,0)
    {
        if(b[i]!=e[i])
        {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES"<<endl;

    rep(i,n,0)
    cout<<c[i].ss<<" ";
}