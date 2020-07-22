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
#define forn(i, n) for(int i = 0; i < int(n); i++) 


int main(){
    int n;
    cin>>n;
    vlli x(n), y(n);
    rep(i,n,0)cin>>x[i]>>y[i];
    vinput(c,n);
    vinput(k,n);
    n++;

    vector<int> p(n, -1);
    vector<int> d(n, int(1e9));
    vector<bool> used(n);
    
    forn(i, n - 1){
        d[i] = c[i];
        p[i] = n - 1;
    }
    used[n - 1] = true;
    
    long long ans = 0;
    vector<int> vv;
    vector<pair<int, int>> ee;
    
    forn(_, n - 1){
        int v = -1;
        forn(i, n) if (!used[i] && (v == -1 || d[v] > d[i]))
            v = i;
        
        if (p[v] == n - 1)
            vv.push_back(v + 1);
        else
            ee.push_back(make_pair(v + 1, p[v] + 1));
        ans += d[v];
        
        used[v] = true;
        forn(i, n) if (!used[i]){
            long long dist = (k[v] + k[i]) * 1ll * (abs(x[v] - x[i]) + abs(y[v] - y[i]));
            if (dist < d[i]){
                d[i] = dist;
                p[i] = v;
            }
        }
    }
    
    printf("%lld\n", ans);
    printf("%d\n", int(vv.size()));
    for (auto it : vv)
        printf("%d ", it);
    puts("");
    printf("%d\n", int(ee.size()));
    for (auto it : ee)
        printf("%d %d\n", it.first, it.second);
}