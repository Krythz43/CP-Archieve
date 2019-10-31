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



lli ans1=INT_MAX,ans2=inf;
lli n,d;


lli dsum(lli x)
{
    lli ans=0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}

void solve(lli cnum,int dep)
{
    if(dep>20)
    return;
    // cout<<dep<<endl;

    if(cnum<10)
    {
        if(cnum<ans1)
        {
            ans1=cnum;
            ans2=dep;
        }
        else if(cnum==ans1)
        {
            if(dep<ans2)
            ans2=dep;
        }
    }

    int z=1;
    solve(cnum+d,dep+1);

    while(cnum>9)
    {
        cnum=dsum(cnum);
        solve(cnum,dep+z);
        z++;
    }
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        ans1=ans2=inf;
        cin>>n>>d;
        solve(n,0);
        cout<<ans1<<" "<<ans2<<endl;
    }
}        
       
