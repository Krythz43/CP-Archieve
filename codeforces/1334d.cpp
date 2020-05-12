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
// #define endl '\n'


vector <lli> ans;
lli n,l,r;

void add_layer(lli x){
    if(x == n){
        // cout<<"here"<<endl;
        ans.pb(1);
        return;
    }
    for(lli i = x+1;i<=n;i++){
        ans.pb(x);
        ans.pb(i);
    }
}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        ans.clear();
        cin>>n>>l>>r;
        lli st = -1;
        lli sum = 0;

        rep(i,n+1,1){
            sum += 2*n - 2*i;
            if(i == n)sum++;
            // cout<<"layer "<<i<<" "<<sum<<endl;
            if(sum >= l){
                // cout<<"entered"<<endl;
                if(st == -1){
                    st = sum - 2*n + 2*i;
                    if(n == i)st--;
                }
                add_layer(i);
            }
            if(sum >= r)break;
        }
        // cout<<"check for layer completed"<<endl;

        // cout<<"startin at "<<st<<endl;

        for(lli i = st;i <= r; i++){
            if(i < l)continue;
            cout<<ans[i-st-1]<<" ";
        }
        nl;
    }
}