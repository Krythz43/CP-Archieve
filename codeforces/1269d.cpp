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

vlli a;

int main()
{
    fastio;
    int n;
    cin>>n;
    a.resize(n);
    ainput(a,n);
    lli ans=0,lo=0,mid;
    lo = a[0];
    rep(i,n,1){
        if(a[i]%2 != a[i-1]%2){
            ans+=lo/2;
            lo=0;
        }
        lo+=a[i];
    }
    ans+=lo/2;

    lli ans1=0;

    // Flipping it

    vlli b(a[0]);
    rep(i,n,1){
        b[a[i]-1]++;
    }
    lli x = 0;
    for(int i=a[0]-1;i>=0;i--){
        x+=b[i];
        b[i]=x+1;
    }
    
    // reverse(all(b));
    // printarray(b,b.size())

    /// Flipped histo

    lo = b[0];
    rep(i,b.size(),1){
        if(b[i]%2 != b[i-1]%2){
            ans1+=lo/2;
            lo=0;
        }
        lo+=b[i];
    }
    ans1+=lo/2;
    // cout<<ans<<' '<<ans1<<endl;


    cout<<max(ans,ans1)<<endl;
}