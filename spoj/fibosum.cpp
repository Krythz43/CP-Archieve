#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<lli>
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
// #define endl '\n'

#define MOD 1000000007

vector <vi> multi(vector <vi> a,vector <vi> b)
{
    vector<vi > multiply(2,vi(2));
    lli sum=0;
    rep(i,2,0)
    rep(j,2,0)
    {
      rep(k,2,0)
      sum= (sum+ a[i][k]*b[k][j]%MOD)%MOD;
      multiply[i][j] = sum%MOD;
      sum = 0;
    }
    return multiply;
    // return
}

vector <vi> matrix_expo(vector <vi> a,lli n)
{
    if(n==1)
    return a;
    vector<vi> b=a,z=matrix_expo(a,n/2);
    a=multi(z,z);
    if(n%2)
    a=multi(a,b);
    return a;
}

lli fibo(lli x)
{
    vector<vi> a{{1,1},{1,0}};
    a=matrix_expo(a,x);

    return a[0][1];
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m;
        cin>>m>>n;
        m--;
        lli ans=fibo(n+2)%MOD;
        ans=(ans-fibo(m+2)%MOD+MOD)%MOD;
        cout<<ans<<endl;
    }
}