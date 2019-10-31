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

const lli S=100005;
lli n,m,q,l,r,cnt=0;
vlli mod(S);
vlli a(S);

int phi(int x)
{
    int res=x;
    for (int i=2;i*i<=x;i++)
    {
        if (x%i==0)
        {
            res-=res/i;
            while (x%i==0) x/=i;
        }
    }
    if (x>1) res-=res/x;
    return res;
}

void precal(lli m)
{
    mod[++cnt]=m;
    if(m==1)return;
    precal(phi(m));
}

lli multi(lli x,lli n,lli mod){
    if(n==0)return 1;
    x%=mod;
    if(n==1)return x;
    lli ans=multi(x*x%mod,n/2,mod);
    if(n%2)ans=ans*x%mod;
    return ans;
}

int fast_pow(int a,int x,int mod)
{
    int ans=1;
    for (;x;x>>=1,a=1ll*a*a>=mod?1ll*a*a%mod+mod:1ll*a*a%mod)
        if (x&1) ans=1ll*a*ans>=mod?1ll*a*ans%mod+mod:1ll*a*ans%mod;
    return ans; 
} 


int solve(int l,int tim)
{
    if (mod[tim]==1) return 1;
    if (l==r) return a[l]<mod[tim]?a[l]:a[l]%mod[tim]+mod[tim];
    return fast_pow(a[l],solve(l+1,tim+1),mod[tim]);
}

int main()
{
    fastio;
    cin>>n>>m;
    precal(m);
    rep(i,n+1,1)cin>>a[i];
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<solve(l,1)%m<<endl;
    }
}