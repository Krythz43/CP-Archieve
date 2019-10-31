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

lli n;
lli memo[3005][3005][3];
vlli s,c;
lli f=0;


lli solve(lli id,lli lc,lli cho)
{
    if(id<0)
    return inf;

    if(memo[id][lc][cho]!=-1)
    return memo[id][lc][cho];

    if(cho==0)
    {
        f=1;
        return memo[id][lc][cho];
    }
    if(s[id]<s[lc])
    return memo[id][lc][cho]=min(solve(id-1,id,cho-1)+c[id],solve(id-1,lc,cho));
    else
    return memo[id][lc][cho]=solve(id-1,lc,cho);
}

int main()
{
    fastio;
    cin>>n;
    lli x;
    memset(memo,-1,sizeof memo);
    rep(i,n,0)
    {
        cin>>x;
        s.pb(x);
    }

    rep(i,n,0)
    {
        cin>>x;
        c.pb(x);
    }

    rep(i,n,0)
    {
        //id,last chosen,choices left
        solve(i-1,i,2);
    }

    if(f)
    {
        lli ans=inf;
        rep(i,n,0)
        {
            lli d=solve(i-1,i,2);
            if(d!=inf)
            ans=min(ans,d+c[i]);
        }

        cout<<ans<<endl;
    }
    else
    cout<<-1<<endl;
}