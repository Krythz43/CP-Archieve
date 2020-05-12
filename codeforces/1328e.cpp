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


int n,m;
const int S = 2e5+5;

vi adj[S];
vi parent(S),depth(S);


vector <int> height,euler,first,segtree;

void dfs(int x, int h, int p){
    parent[x] = p;
    depth[x] = depth[p] + 1;

    euler.push_back(x);
    height[x] = h;
    for(auto to: adj[x]){
        if(to == p) continue;
        dfs(to,h+1,x);
        euler.push_back(x);
    }
}


int N;

void build(int node, int b, int e) {
    if (b == e) {
        segtree[node] = euler[b];
    } else {
        int mid = (b + e) / 2;
        build(node << 1, b, mid);
        build(node << 1 | 1, mid + 1, e);
        int l = segtree[node << 1], r = segtree[node << 1 | 1];
        segtree[node] = (height[l] < height[r]) ? l : r;
    }
}


int query(int node, int b, int e, int L, int R) {
    if (b > R || e < L)
        return -1;
    if (b >= L && e <= R)
        return segtree[node];
    int mid = (b + e) >> 1;
    int left = query(node << 1, b, mid, L, R);
    int right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return height[left] < height[right] ? left : right;
}

void init(){

    for(int i = 0; i < euler.size() ; i++){
        if(first[euler[i]] != -1)continue;
        first[euler[i]] = i;
    }

    N = euler.size();
    segtree.resize(4*N + 5);
    build(1,0,N-1);
}



int main()
{
    fastio;
    cin>>n>>m;

    height.resize(n+5);
    first.resize(n+1,-1);

    rep(i,n-1,0){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y),adj[y].pb(x);
    }

    dfs(1,1,1);
    init();

    // printarray(parent,n+1)
    while(m--){
        int k;
        cin>>k;
        vinput(a,k);
        int deep = 1;
 
        rep(i,k,0){
            if(depth[deep] < depth[a[i]])deep = a[i];
            a[i] = parent[a[i]];
        }

        int f = 1;

        // printarray(a,k)

        rep(i,k,0){
            int l,r;
            l = deep;
            r = a[i];

            l = first[l];
            r = first[r];
            if(l > r)swap(l,r);
            auto lca = query(1,0,N-1,l,r);

            // cout<<lca<<endl;

            if(lca != deep && lca != a[i]){
                f = 0;
                break;
            }
        }

        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}