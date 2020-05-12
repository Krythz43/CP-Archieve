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


lli n,x;
vector<lli> a;

bool F(lli z){
    if(z == 0)return true;
    return x <= a[z - 1]/z; 
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        a.clear();
        cin>>n>>x;
        a.resize(n);
        ainput(a,n);
        SO(a);
        reverse(all(a));
        rep(i,n,1)a[i]+=a[i-1];
        lli hi = n,lo=0,mid;

        // printarray(a,n)

        while(hi-lo>1){
            // cout<<hi<<" x "<<lo<<endl;
            mid=(hi+lo)/2;
            if(F(mid))lo=mid;
            else hi=mid;
        }
        if(F(hi))cout<<hi<<endl;
        else cout<<lo<<endl;
    }
}