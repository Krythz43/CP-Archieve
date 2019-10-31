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
#define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    vector<ipair> a;
    int x,y;
    rep(i,n,0)
    {
        cin>>x>>y;
        a.pb(mp(x,y));
    }

    int f1,f2,f3,f4;
    int ans=0;
    rep(i,n,0)
    {
        f1=f2=f3=f4=0;
        rep(j,n,0)
        {
            if(i==j)
            continue;
            if(a[i].ff==a[j].ff)
            {
                if(a[i].ss<a[j].ss)
                f1++;
                else
                f2++;
            }

            if(a[i].ss==a[j].ss)
            {
                if(a[i].ff>a[j].ff)
                f3++;
                else
                f4++;
            }
        }
        if(f1 && f2 && f3 && f4)
        ans++;
    }
    cout<<ans<<endl;
}
