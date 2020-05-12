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
    lli n,k;
    cin>>n>>k;
    vinput(a,n);
    SO(a);
    vlli lef(n);
    vlli rig(n);
    lef[0]=rig[n-1]=0;
    rep(i,n,1){
        lef[i]=lef[i-1]+(a[i]-a[i-1])*i;
    }
    map<int,lli> M;
    rep(i,n,0)M[a[i]]++;

    for(int i=n-2;i>=0;i--){
        rig[i]=rig[i+1]+(a[i+1]-a[i])*(n-1-i);
    }

    lli z=1;
    lli tans=1;
    rep(i,n,1){
        if(a[i] == a[i-1])z++;
        else z=1;
        tans=max(z,tans);
    }

    if(tans>=k){
        cout<<0<<endl;
        return 0;
    }

    printarray(lef,n)
    printarray(rig,n)

    lli ans=min(lef[k-1],rig[n-k]);
    // cout<<ans<<endl;
    rep(i,n,0)ans=min(ans,lef[i]+rig[i]);
    cout<<ans<<endl;
}