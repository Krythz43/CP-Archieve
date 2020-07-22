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

const int S = 1e + 5;
int n,m,k,x1,x2,y1,y2;

vector<string> a(S);
int up[S][S],down[S][S],left[S][S],right[S][S];

int main()
{
    fastio;
    cin>>n>>m>>k;
    rep(i,n,0)cin>>a[i];
    memset(up,0,sizeof up);
    memset(down,0,sizeof down);
    memset(left,0,sizeof left);
    memset(right,0,sizeof right);

    cin>>x1>>y1>>x2>>y2;
    if(x1 == x2 and y1 == y2)return cout<<0<<endl,0;
    
    // Up
    for(int i = 1;i < n;i++){
        for(int j = 0;j < m;j++){
            if(a[i - 1][j] != '#' and a[i][j] != '#')up[i][j] = up[i - 1][j] + 1;
        }
    }

    // Down
    for(int i = n - 2;i >= 0;i--){
        for(int j = 0;j < m;j++){
            if(a[i + 1][j] != '#' and a[i][j] != '#')down[i][j] = down[i + 1][j] + 1;
        }
    }

    // Left
    for(int j = 1;j < m;j++){
        for(int i = 0;i < n;i++){
            if(a[i][j - 1] != '#' and a[i][j] != '#')left[i][j] = left[i][j - 1] + 1;
        }
    }

    // right
    for(int j = 1;j < m;j++){
        for(int i = 0;i < n;i++){
            if(a[i][j - 1] != '#' and a[i][j] != '#')right[i][j] = right[i][j - 1] + 1;
        }
    }


}