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

int k1,k2,mod=1e8;
int memo[105][105][15][15];


int solve(int n1,int n2,int x, int y)
{
    if(n1<0 || n2<0)
    return 0;

    if(memo[n1][n2][x][y]!=-1)
    return memo[n1][n2][x][y];

    // cout<<"state:"<<n1<<" "<<n2<<" "<<x<<" "<<y<<endl;

    if(n1==0 && n2==0)
    {
        // cout<<"here!";
        return memo[n1][n2][x][y]=1;
    }

    if((x==k1 && n2==0) || (y==k2 && n1==0))
    return memo[n1][n2][x][y]=0;

    if(x==k1)
    return memo[n1][n2][x][y]= solve(n1,n2-1,0,y+1)%mod;

    if(y==k2)
    return memo[n1][n2][x][y]= solve(n1-1,n2,x+1,0)%mod;

    return memo[n1][n2][x][y]= (solve(n1,n2-1,0,y+1)+solve(n1-1,n2,x+1,0))%mod;
}
int main()
{
    fastio;
    memset(memo,-1,sizeof memo);
    int n1,n2;
    cin>>n1>>n2>>k1>>k2;
    solve(n1,n2,0,0);
    cout<<memo[n1][n2][0][0]<<endl;
}