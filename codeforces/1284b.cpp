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
    int t,N;
    vector<lli> mx,mn;
    cin>>t;
    N=t;
    vlli r;
    lli ans = 0;
    
    lli cor = 0;

    while(t--){
        int n;
        cin>>n;
        r.resize(n);
        ainput(r,n);
        int f = 0;
        lli mnn = INT_MAX,mxx= -1;
        rep(i,n,0){
            if(r[i]>mnn)f=1;
            mnn=min(mnn,r[i]);
            mxx=max(mxx,r[i]);
        }
        if(!f){
            mx.pb(mxx);
            mn.pb(mnn);
        }
        else ans+=(2*N-1);
        if(f)cor++;
    }
    ans-=(cor*(cor-1));

    if(!mx.empty()){
        N = mx.size();
        SO(mx);
        SO(mn);

        int p1=0,p2=0;
        while(p2!=N && p1!=N){
            if(mn[p1]<mx[p2]){
                ans+=(N-p2);
                p1++;
            }
            else p2++;
        }
    }
    cout<<ans<<endl;

}