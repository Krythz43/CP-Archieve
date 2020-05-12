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

lli n,m;
vi pos;

void solve(vlli a,vlli b)
{
    lli x = a[0];
    vlli c(n);
    SO(b);
    rep(i,n,0){
        lli add = 0;
        if(b[i] < x){
            add = b[i]+m-x;
        }
        else add = b[i]-x;
        rep(i,n,0)c[i]=(a[i]+add)%m;
        SO(c);
        int f=1;
        rep(i,n,0)if(c[i]!=b[i]){
            f=0;break;
        }
        if(f)pos.pb(add);
    }
}

int main()
{
    fastio;
    cin>>n>>m;
    vinput(a,n);
    vinput(b,n);
    solve(a,b);
    SO(pos);
    cout<<pos[0]<<endl;
}
