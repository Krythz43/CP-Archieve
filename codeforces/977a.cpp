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

int main()
{
    fastio;
    int n;
    cin>>n;
    vi a(n+1);
    rep(i,n+1,1)cin>>a[i];

    map <int,int> M;
    rep(i,n+1,1){
        M[a[i]]=M[a[i]-1]+1;
    }

    lli ans=0,tans;

    rep(i,n+1,1){
        if(M[a[i]]>ans){
            ans=M[a[i]];
            tans=a[i];
        }
    }

    cout<<ans<<endl;
    vi v;
    for(int i=n;i;i--){
        if(!ans)break;

        if(tans==a[i]){
            v.pb(i);
            tans--;
            ans--;
        }
    }

    reverse(all(v));
    printarray(v,v.size())
}