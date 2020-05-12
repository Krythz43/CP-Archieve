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

int n;
vector<pair<ipair,ipair>> ans;
vector<ipair> extra;

const int S = 1e3 + 5;

vi parent(S,0),height(S);

void make(int x){
    parent[x] = x;
    height[x] = 0;
}


int find(int x){
    if(x == parent[x])return x;
    return parent[x] = find(parent[x]);
}

void Union(int a,int b){
    int A=a,B=b;
    a = find(a);
    b = find(b);
    if(a != b){
        if(height[a] < height[b])swap(a,b);
        parent[b] = a;
        if(height[a] == height[b])height[a]++;
    }
    else extra.pb(mp(A,B));
}


int main()
{
    fastio;
    int n;
    cin>>n;
    rep(i,n+1,1)make(i);

    int x,y;
    rep(i,n-1,0){
        cin>>x>>y;
        Union(x,y);
    }

    // printarray(parent,n+1)

    rep(i,n+1,2)if(find(i) != find(1)){
        ans.pb(mp(extra[ans.size()],mp(i,1)));
        Union(i,1);
    }

    cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x.ff.ff<<" "<<x.ff.ss<<" "<<x.ss.ff<<" "<<x.ss.ss<<endl;
    }
}