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

const lli SIZE = 5e5 + 5;
int n,m;
lli timer = 0;
vector<lli> H[SIZE];
vector<lli> val[SIZE];

vlli pow2(30);
vlli in(SIZE),out(SIZE);
vlli adj[SIZE];

string s;

void dfs(int v, int h){
    in[v] = ++timer;
    H[h].pb(timer);
    val[h].pb(val[h].back()^(pow2[s[v - 1] - 'a']));

    for(auto x: adj[v])dfs(x,h + 1);
    out[v] = ++timer;
}

int main()
{
    fastio;
    cin>>n>>m;
    int x;
    pow2[0] = 1;
    rep(i,pow2.size(),1)pow2[i] = 2*pow2[i - 1];

    rep(i,n - 1,0){
        cin>>x;
        adj[x].pb(i + 2);
    }

    rep(i,SIZE,0){
        H[i].resize(1);
        val[i].resize(1);
    }

    cin>>s;

    dfs(1,1);

    int v,h;
    while(m--){
        cin>>v>>h;

        // cout<<"Query "<<m<<endl;

        lli l = lower_bound(all(H[h]),in[v]) - H[h].begin() - 1;
        lli r = lower_bound(all(H[h]),out[v]) - H[h].begin() - 1;

        lli pal = val[h][r]^val[h][l];

        // cout<<"detected "<<r - l + 1<<" elements with l = "<<l
        //     <<"r = "<<r<<endl;

        // rep(i,r+1,l)cout<<H[h][i]<<" "<<val[h][i]<<endl;

        // cout<<pal<<endl;

        // cout<<H[1].size()<<endl;
        if(!(pal - (pal&-pal)))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}