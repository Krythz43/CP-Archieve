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
    lli u,v;
    cin>>u>>v;
    if(u > v){cout<<-1<<endl;return 0;}
    if((v-u)%2){cout<<-1<<endl;return 0;}

    if(u == v){
        if(u == 0)cout<<0<<endl;
        else cout<<1<<endl<<u<<endl;
        return 0;
    }

    lli ans = (v - u)/2;
    if(u&ans){
        cout<<3<<endl;
        cout<<ans<<" "<<ans<<" "<<u<<endl;
    }   
    else{
        cout<<2<<endl;
        cout<<(ans^u)<<" "<<ans<<endl;
    }
}