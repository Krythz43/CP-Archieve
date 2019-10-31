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
    int n,m;
    cin>>n>>m;
    vector <ipair> a,b;
    int x;
    rep(i,n,0)
    {
        cin>>x;
        a.pb(mp(x,i));
    }

    rep(i,m,0)
    {
        cin>>x;
        b.pb(mp(x,i));
    }

    SO(a);
    SO(b);

    int p1=0,p2=0;
    cout<<a[p1].ss<<" "<<b[p2].ss<<endl;

    while(p1!=n-1 || p2!=m-1)
    {
        if(p1==n-1)
        p2++;
        else if(p2==m-1)
        p1++;
        else
        {
            if(a[p1+1].ff>b[p2+1].ff)
            p2++;
            else
            p1++;
        }

        cout<<a[p1].ss<<" "<<b[p2].ss<<endl;
    }
}