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

int n,m;
bool isvalid(int x,int y){
    return x < n and x >= 0 and y < m and y >=0;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> a(n);
        rep(i,n,0)cin>>a[i];

        int gleft = 0;
        

        vector<ipair> dir = {{1,0},{-1,0},{0,-1},{0,1}};

        int x,y;

        rep(i,n,0)rep(j,m,0){
            if(a[i][j] == 'G')gleft++;
            if(a[i][j] != 'B')continue;

            for(auto d: dir){
                x = i + d.ff;
                y = j + d.ss;
                if(isvalid(x,y) && a[x][y] == '.')a[x][y] = '#';
            }
        }

        queue <ipair> Q;
        map<ipair,int> vis;

        // rep(i,n,0)cout<<a[i]<<endl;

        Q.push(mp(n - 1,m - 1));

        int f = 1;

        while(!Q.empty()){
            auto X = Q.front();
            Q.pop();
            if(vis[X])continue;
            vis[X]++;
            tie(x,y) = X;
            if(a[x][y] == 'B'){
                f = 0;
                break;
            }

            if(a[x][y] == '#')continue;

            if(a[x][y] == 'G')gleft--;

            int tx,ty;
            tx = x;
            ty = y;
            for(auto d: dir){
                x = tx;
                y = ty;
                x += d.ff;
                y += d.ss;
                if(isvalid(x,y) && vis[mp(x,y)] == 0 && a[x][y] != '#')
                Q.push(mp(x,y));
            }
        }

        // cout<<f<<" "<<gleft<<endl;

        if(f && gleft == 0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}