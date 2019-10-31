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

const lli mod=1e9+7;

lli multi(lli x,lli n){
    if(n==0)return 1;
    if(n==1) return x%mod;
    lli ans = multi(x*x%mod,n/2)%mod;
    if(n%2)ans=ans*x%mod;
    return ans;
}

int main()
{
    fastio;
    lli x,n;
    cin>>x>>n;

    vlli pf;
    
    for (long long d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            pf.push_back(d);
            while (x % d == 0)x /= d;
        }
    }
    if (x > 1)
        pf.push_back(x);

    // printarray(pf,pf.size())

    lli ans=1,m;

    rep(i,pf.size(),0){
        lli c=0,t=pf[i];
        m=n;
        while(m){
            c+=m/t;
            m/=t;
        }
        ans=ans*multi(t,c)%mod;
    }

    cout<<ans<<endl;
}