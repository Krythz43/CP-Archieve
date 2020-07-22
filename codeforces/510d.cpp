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

const int S = 1e3 + 5;

lli n;
vlli l,c;
vlli prime;
lli dp[S][(1<<9)];
lli ans = inf;
vlli m(S);

lli solve(lli idx,lli mask){

    lli & ret  = dp[idx][mask];
    if(ret != -1)return ret;
    ret = inf;

    if(idx == n){
        if(mask == 0)ret = 0;
        return ret;
    }
    ret = min({ret,solve(idx+1,mask),solve(idx + 1,mask&m[idx]) + c[idx]});
    // cout<<"("<<idx<<","<<mask<<") = "<<ans<<endl;
    return ret;
}

int main()
{
    fastio;
    cin>>n;
    vlli C(n),L(n);
    ainput(L,n);
    ainput(C,n);

    rep(i,n,0)if(L[i] != 1){
        l.pb(L[i]),c.pb(C[i]);
    }
    else ans = min(ans,C[i]);

    n = l.size();

    rep(i,n,0){
        int t;
        t = l[i];

        prime.clear();
        for(int j = 2;j <=  sqrt(t);j++){
            if(t%j)continue;
            prime.pb(j);
            while(t%j == 0)t /= j;
        }

        if(t > 1)prime.pb(t);

        // for(auto x: prime)cout<<x<<" ";nl;

        rep(k,n,0){
            m[k] = 0;
            rep(j,prime.size(),0)if(l[k]%prime[j] == 0)m[k] |= (1 << j);
        }

        // rep(k,n,0)cout<<m[k]<<" ";nl;
        memset(dp, -1 ,sizeof dp);
        // cout<<prime.size()<<" "<<__builtin_popcount((1<<prime.size()) - 1)<<endl;

        // cout<<i<<" "<<ans<<" "<<c[i] + solve(0,(1<<prime.size()) - 1)<<endl;
        ans = min(ans,c[i] + solve(0,(1<<prime.size()) - 1));
    }

    if(ans == inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}