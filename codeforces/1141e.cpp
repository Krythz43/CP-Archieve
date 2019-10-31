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
    lli h,n;
    cin>>h>>n;
    vinput(a,n);
    lli sum=0;
    vector<llipair> prefix;
    lli mn=LLONG_MAX;
    rep(i,n,0)
    {
        sum+=a[i];
        prefix.pb(mp(sum,i));
        mn=min(mn,sum);
        if(h+sum<=0)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    SO(prefix);
    if(sum>=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        lli ans=0;
        lli h1=h+mn;
        sum*=-1;
        lli t=h1/(sum);
        if(t)
        t--;
        ans=t*n;
        h-=t*sum;
        for(int i=0;;i=(i+1)%n)
        {
            ans++;
            h+=a[i];
            if(h<=0)
            {
                cout<<ans<<endl;
                return 0;
            }
        }
    }
}
