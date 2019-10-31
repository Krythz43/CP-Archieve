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
const lli mod=998244353;

bool comp(llipair a, llipair b){
    return a.ss<b.ss;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    vector<llipair> a(n);
    rep(i,n,0)cin>>a[i].ff>>a[i].ss;

    vector<lli> fac(n+3,1);
    rep(i,n+2,1)fac[i]=(fac[i-1]*i)%mod;

    SO(a);

    int y=1,f=0;
    lli ans1=1;

    rep(i,n,1){
        if(a[i].ff!=a[i-1].ff){
            ans1=(ans1*fac[y])%mod;
            y=1;
        }
        else y++;
    }

    for (int i = 1; i < n; i++){
        if (a[i].first < a[i - 1].first || a[i].second < a[i - 1].second)
                f = 0;
    }

    ans1=(ans1*fac[y])%mod;

    
    SOP(a,comp);
    lli ans2=1;
    y=1;
    rep(i,n,1){
        if(a[i].ss!=a[i-1].ss){
            ans2=(ans2*fac[y])%mod;
            y=1;
        }
        else y++;
    }
    ans2=(ans2*fac[y])%mod;
    // cout<<ans1<<' '<<ans2<<endl;
    ans1=(ans1+ans2)%mod;

    lli ans3=1;
    map<ipair,int> M;
    rep(i,n,0)M[a[i]]++;


    if(f){
        for(auto x:M){
            if(x.ss!=1){
                ans3=(ans3*fac[x.ss])%mod;
            }
        }
        ans1=(ans1-ans3)%mod;
    }
    cout<<ans1<<" "<<ans2<<' '<<ans3<<" "<<f<<endl;

    cout<<((fac[n]-ans1)%mod+mod)%mod<<endl;
}