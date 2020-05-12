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
#define inf LLONG_MAX
#define endl '\n'

const int S = 1e5+5;
vector<int> adj[S];
int a[S][3];
vi order = {0,1,2};
lli ans = inf, temp;

vector<int> fans, res;

void dfs(int x,int p, int val){
    temp += a[x][order[val]];
    res[x] = order[val] + 1;
    for(auto y: adj[x]){
        if(y == p)continue;
        dfs(y,x,(val+1)%3);
    }
}

int main()
{
    fastio;
    int n;
    cin>>n;
    int x,y;

    rep(j,3,0)rep(i,n,0)cin>>a[i][j];
    res.resize(n);


    rep(i,n-1,0){
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y),adj[y].pb(x);
    }

    rep(i,n,0)if(adj[i].size() >  2){
        cout<<-1<<endl;
        return 0;
    }

    int st,nxt;
    rep(i,n,0)if(adj[i].size() == 1){
        st = i;
        break;
    }

    do{
        temp = a[st][order[0]];
        res[st] = order[0]+1;

        dfs(adj[st][0],st,1);
        if(ans>temp){
            ans = temp;
            fans = res;
        }
        // cout<<"permutation "<<temp<<endl;
        // printarray(res,n)
    }while(next_permutation(all(order)));

    cout<<ans<<endl;
    printarray(fans,n)
}