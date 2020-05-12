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
    return x < n && x>=0 && y<m && y >=0;
}
int main()
{
    fastio;
    cin>>n>>m;
    vi fr(n,5000),lr(n,-1),fc(m,5000),lc(m,-1);

    vector<string> s(n);
    rep(i,n,0)cin>>s[i];

    rep(i,n,0)rep(j,m,0)if(s[i][j] == '#'){
        fr[i] = min(fr[i],j);
        fc[j] = min(fc[j],i);

        lr[i] = max(lr[i],j);
        lc[j] = max(lc[j],i);
    }

    int f = 1;

    int C,R;
    C = R = 0;
    rep(i,n,0){
        rep(j,m,0)if(s[i][j] == '#') C = R = 1;
    }

    rep(i,n,0){
        if(lr[i] == -1)continue;
        rep(j,lr[i],fr[i])if(s[i][j] == '.'){
            f = 0;
            break;
        }
    }

    if(f)rep(j,m,0){
        if(lc[j] == -1)continue;
        rep(i,lc[j],fc[j])if(s[i][j] == '.'){
            f = 0;
            break;
        }
    }

    if(f && C){
        rep(i,n,0)R &= (lr[i] != -1);
        rep(i,m,0)C &= (lc[i] != -1);
    }

    if(R == 0 && C == 1)f = 0;
    if(R == 1 && C == 0)f = 0;

    if(!f){
        cout<<-1<<endl;
        return 0;
    }

    int a[n][m];
    memset(a,-1,sizeof a);

    int ans = 0;

    queue<ipair> Q;
    int x,y;

    rep(i,n,0)rep(j,m,0){
        if(s[i][j] == '#' && a[i][j] == -1){
            ans++;
            Q.push(mp(i,j));

            while(!Q.empty()){
                auto X = Q.front();
                Q.pop();
                tie(x,y) = X;
                if(a[x][y] != -1)continue;
                a[x][y] = ans;

                if(isvalid(x+1,y))if(a[x+1][y] == -1 && s[x+1][y] == '#')Q.push(mp(x+1,y));
                if(isvalid(x-1,y))if(a[x-1][y] == -1 && s[x-1][y] == '#')Q.push(mp(x-1,y));
                if(isvalid(x,y+1))if(a[x][y+1] == -1 && s[x][y+1] == '#')Q.push(mp(x,y+1));
                if(isvalid(x,y-1))if(a[x][y-1] == -1 && s[x][y-1] == '#')Q.push(mp(x,y-1));
            }
        }
    }

    int k = 0;
    cout<<ans<<endl;
}