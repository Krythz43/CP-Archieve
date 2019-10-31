#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'


vlli a;
lli n,x;
const int S=3e5+7;
lli dp[S][3][3];

// 0- yet to arrive, 1-ongoing, 2-closed.

lli solve(int id,int cs,int rd){
    if(id==n)return 0;
    lli &ans=dp[id][cs][rd];
    if(ans!=-inf)return ans;

    if(rd==1)
    {
        if(cs==2){
            return ans=a[id]+max(solve(id+1,cs,rd),0LL);
        }

        if(cs==1){
            return ans=max(x*a[id]+max(0LL,solve(id+1,cs,rd)),a[id]+max(0LL,solve(id+1,cs+1,rd)));
        }

        return ans=max(a[id]+max(0LL,solve(id+1,cs,rd)),x*a[id]+max(0LL,solve(id+1,cs+1,rd)));
    }
    else{
        //dont read, read without multi, read with multi
        return ans=max(solve(id+1,cs,rd),max(  a[id]+max(0LL,solve(id+1,cs,rd+1)),x*a[id]+max(0LL,solve(id+1,cs+1,rd+1))  ));
    }
}

int main()
{
    fastio;
    cin>>n>>x;
    a.resize(n);
    rep(i,S,0)rep(j,3,0)rep(k,3,0)dp[i][j][k]=-inf;

    ainput(a,n);
    lli ans=0;
    ans=max(ans,solve(0,0,0));

    cout<<ans<<endl;
}