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

lli n,k,p;
vlli a, keys;

// vector<pair<lli, ipair>> x;

int main()
{
    fastio;
    cin>>n>>k>>p;
    a.resize(n);
    keys.resize(k);
    ainput(a,n);
    ainput(keys,k);

    SO(a);
    SO(keys);

    lli ans = LLONG_MAX;

// printarray(a,n)
//     printarray(keys,k)

    rep(i,k - n + 1,0){
        lli temp = 0;
        rep(j,n,0){
            temp = max(temp, abs(keys[i + j] - a[j]) + abs(p - keys[i + j]));
        }

        // cout<<i<<" "<<temp<<endl;
        ans = min(ans, temp);
    }

    cout<<ans<<endl;
}