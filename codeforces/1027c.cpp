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
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        vlli a(n);
        rep(i,n,0)
        cin>>a[i];

        vector<pair< lli,lli > > c;
        sort(a.begin(),a.end());
        c.pb(mp(a[0],1));
        rep(i,n,1)
        {
            if(a[i]==a[i-1])
            c[c.size()-1].ss++;
            else
            {
                c.pb(mp(a[i],1));
            }
        }
        vlli ans;
        rep(i,c.size(),0)
        {
            if(c[i].ss>1)
            ans.pb(c[i].ff);
        }
        SO(ans);
        int f=1;

        int an=1,mian=inf;

        if(c[0].ss>=4)
            {f=0;cout<<ans[0]<<" "<<ans[0]<<" "<<ans[0]<<" "<<ans[0]<<endl;}
        if(f)
        rep(i,c.size(),1)
        {
            if(c[i].ss>=4)
            {f=0;
            cout<<c[i].ff<<" "<<c[i].ff<<" "<<c[i].ff<<" "<<c[i].ff<<endl;
            break;}

            if(mian>c[i].ff-c[i-1].ff)
            {
                an=i;
                mian=c[i].ff-c[i-1].ff;
            }
        }

        if(f)
        cout<<ans[an]<<" "<<ans[an]<<" "<<ans[an-1]<<" "<<ans[an-1]<<endl;
    }
}