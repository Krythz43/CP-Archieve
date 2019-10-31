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
lli mod=998244353;

int main()
{
    fastio;
    int n,x,y;
    cin>>n;
    vector<ipair> a;
    rep(i,n,0)
    {
        cin>>x;
        a.pb(mp(x,i));
    }
    SO(a);
    vi hash(n,0);
    rep(i,n,1)
    {
        if(a[i].ff==a[i-1].ff)
        {
            x=a[i-1].ss;
            y=a[i].ss;
            if(a[i].ss>a[i-1].ss)
            {
                x=a[i-1].ss;
                y=a[i].ss;
            }
            else
            swap(x,y);

            hash[x]++;
            hash[y]--;
        }
    }
    int c=0;
    vi ans(n,0);
    rep(i,n,0)
    {
        ans[i]=c;
        c+=hash[i];
    }

    lli fans=1;

    rep(i,n,1)
    {
        if(ans[i]==0)
        {
            fans=(fans*2)%mod;
        }
    }
    cout<<fans<<endl;
}