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

map<int,int> M;

vector<int> pf(int x){
    vi ans;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0){
            ans.pb(i);
            while(x%i == 0)x/=i;
        }
    }
    if(x>1)ans.pb(x);
    return ans;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    vi dp(n+1);
    dp[1] = 1;
    vi pfs = pf(a[0]);
    rep(i,pfs.size(),0)M[pfs[i]]=1;

    rep(i,n+1,2){
        pfs = pf(a[i-1]);
        rep(j,pfs.size(),0)dp[i]=max(dp[i],dp[M[pfs[j]]]+1);
        rep(j,pfs.size(),0)M[pfs[j]]=i;
    }
    cout<<*max_element(all(dp))<<endl;
}