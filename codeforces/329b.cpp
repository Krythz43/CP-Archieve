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

bool isvalid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
}

int main()
{
    fastio;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,n,0)cin>>s[i];
    vector<vi > a(n,vector<int> (m,inf/2));
    int x,y,w=0;
    rep(i,n,0)rep(j,m,0)if(s[i][j] == 'E')x=i,y=j;

    map<ipair,int> M;
    queue <pair<ipair,int> > Q;
    Q.push(mp(mp(x,y),w));

    pair<ipair,int> curr;

    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        if(M.count(curr.ff))continue;
        M[curr.ff]++;
        x = curr.ff.ff;
        y = curr.ff.ss;
        w = curr.ss;

        a[x][y] = w;

        if(isvalid(x+1,y))if(s[x+1][y] != 'T')Q.push(mp(mp(x+1,y),w+1));
        if(isvalid(x-1,y))if(s[x-1][y] != 'T')Q.push(mp(mp(x-1,y),w+1));
        if(isvalid(x,y+1))if(s[x][y+1] != 'T')Q.push(mp(mp(x,y+1),w+1));
        if(isvalid(x,y-1))if(s[x][y-1] != 'T')Q.push(mp(mp(x,y-1),w+1));
    }

    int ans = 0, min;
    rep(i,n,0)rep(j,m,0)if(s[i][j] == 'S')min=a[i][j];

    // displaymatrix(a,n,m)

    // cout<<min<<endl;

    rep(i,n,0)rep(j,m,0)
    if(s[i][j] != 'S' && s[i][j] != 'T' && s[i][j] != 'E' && s[i][j] != '0'){
        if(a[i][j] <= min){
            ans += s[i][j]-48;
            // cout<<"Updating at "<<i<<','<<j<<endl;
        }
    }

    cout<<ans<<endl;
}