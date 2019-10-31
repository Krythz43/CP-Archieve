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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

lli mod=1e9+7;
lli n,f1,f2,f3,c;

lli multi (lli x,lli n)
{
    if(n==0)
    return 1LL;
    x%=mod;
    if(n==1)
    return x;
    lli ans=multi(x*x%mod,n/2)%mod;
    if(n%2)
    ans=ans*x%mod;
    // cout<<x<<" "<<n<<" "<<ans<<endl;
    return ans%mod;
}

vector<vector<lli>> multiply(vector<vector<lli>> a, vector<vector<lli>> b) 
{ 
    vector<vector<lli>> mul(3,vector<lli>(3,0));
    for (lli i = 0; i < 3; i++) 
    for (lli j = 0; j < 3; j++) 
    for (lli k = 0; k < 3; k++) 
    mul[i][j] += ((a[i][k]%mod)*(b[k][j]%mod))%mod; 

    return mul;
} 

vector<vector<lli>> power(vector<vector<lli>> F, lli n) 
{ 
    vector<vector<lli>> M={{1,1,1}, {1,0,0}, {0,1,0}};
    if (n==1) 
    return F; 
    F=power(F, n/2); 
    F=multiply(F, F); 
    if(n%2!=0) 
    F=multiply(F, M); 
    return F;
} 

vector<vector<lli>> findNthTerm(lli n) 
{ 
    vector<vector<lli>> F={{1,1,1}, {1,0,0}, {0,1,0}};
  
    F=power(F, n); 

    // cout<<F[0][0]<<" "<<F[0][1]<<" "<<F[0][2]<<endl;
    return F;
} 
  
int main()
{
    fastio;
    cin>>n>>f1>>f2>>f3>>c;
    n%=mod;
    f1%=mod;
    f2%=mod;
    f3%=mod;
    c%=mod;
    vector<vector<lli>> F=findNthTerm(n-3);
    lli ans=multi(f3,F[0][0])%mod;
    ans=(ans*multi(f2,F[0][1]))%mod;
    ans=(ans*multi(f1,F[0][2]))%mod;
    mod--;
    F=findNthTerm(n-3);
    lli rel=0;
    rep(i,3,0)
    rel=(rel+(3-i)*F[0][i])%mod;
    rel=(rel-(n%mod)+mod)%mod;
    mod++;
    lli r=multi(c,rel)%mod;
    // cout<<ans<<" "<<r<<endl;
    cout<<(r*ans)%mod<<endl;
}