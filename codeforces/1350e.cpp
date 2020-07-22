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

int n,m,q;

bool isvalid(int i,int j){
    return i<n && i>=0 && j>=0 && j<m;
}
int main()
{
    fastio;
    cin>>n>>m>>q;
    vector<string> a(n);
    rep(i,n,0)cin>>a[i];

    int blob[n][m];

    // memset(blob,-1,sizeof(blob));
    rep(i,n,0)rep(j,m,0)blob[i][j] = inf/2;

    rep(i,n,0)rep(j,m,0){
        if(isvalid(i+1,j))if(a[i][j] == a[i+1][j])blob[i+1][j] = 1;
        if(isvalid(i-1,j))if(a[i][j] == a[i-1][j])blob[i-1][j] = 1;
        if(isvalid(i,j+1))if(a[i][j] == a[i][j+1])blob[i][j+1] = 1;
        if(isvalid(i,j-1))if(a[i][j] == a[i][j-1])blob[i][j-1] = 1;
    }       

    queue<pair<int,ipair>> Q;

    rep(i,n,0)rep(j,m,0){
        if(blob[i][j] != 1)continue;

        if(isvalid(i+1,j))if(blob[i+1][j] == inf/2)Q.push(mp(2,mp(i+1,j)));
        if(isvalid(i-1,j))if(blob[i-1][j] == inf/2)Q.push(mp(2,mp(i-1,j)));
        if(isvalid(i,j+1))if(blob[i][j+1] == inf/2)Q.push(mp(2,mp(i,j+1)));
        if(isvalid(i,j-1))if(blob[i][j-1] == inf/2)Q.push(mp(2,mp(i,j-1)));
    }

    int x,y,w;
    pair<int,ipair> X;
    while(!Q.empty()){
        X = Q.front();
        Q.pop();
        w = X.ff;
        x = X.ss.ff;
        y = X.ss.ss;
        if(blob[x][y] != inf/2)continue;
        blob[x][y] = w;

        if(isvalid(x+1,y))if(blob[x+1][y] == inf/2)Q.push(mp(w+1,mp(x+1,y)));
        if(isvalid(x-1,y))if(blob[x-1][y] == inf/2)Q.push(mp(w+1,mp(x-1,y)));
        if(isvalid(x,y+1))if(blob[x][y+1] == inf/2)Q.push(mp(w+1,mp(x,y+1)));
        if(isvalid(x,y-1))if(blob[x][y-1] == inf/2)Q.push(mp(w+1,mp(x,y-1)));
    }

    int t;

    // displaymatrix(blob,n,m)

    while(q--){
        cin>>x>>y>>t;
        x--;
        y--;

        // cout<<t<<" "<<blob[x][y]<<endl;
        if(blob[x][y] > t)cout<<a[x][y]<<endl;
        else{
            t -= blob[x][y];
            // cout<<a[x][y]<<endl;
            if(t%2)cout<<a[x][y];
            else cout<<(a[x][y] == '1'?'0':'1');
            nl;
        }
    }

}