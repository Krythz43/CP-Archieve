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

const lli mod = 998244353;
const int S = 5e5+5;
 
lli fact[S];
lli inv[S];

lli multi(lli x,lli n){
    if(n == 0)return 1;
    if(n==1)return x%mod;
    lli ans = multi((x*x)%mod,n/2);
    if(n%2)ans=(ans*x)%mod;
    return ans;
}

void precal()
{
  lli i;
  fact[0] = 1;
  inv[0] = multi(fact[0],mod-2);
  for(i=1;i<S;i++)
  {
    fact[i] = (i*fact[i-1])%mod;
    inv[i] = multi(fact[i],mod-2);
  }
}

lli ncr(lli x,lli y)
{
  if(x<y || x<0 || y<0)
    return 0;
  lli temp = fact[x];
  temp = (temp*inv[y])%mod;
  temp = (temp*inv[x-y])%mod;
  return temp;
}

int main()
{
    fastio;
    int n,k;
    cin>>n>>k;
    precal();

    lli ans = 0;

    rep(i,n + 1,1){
        if(n/i - 1 < k -1)break;
        ans = (ans + ncr(n/i - 1,k - 1))%mod;
    }

    cout<<ans<<endl;
}
