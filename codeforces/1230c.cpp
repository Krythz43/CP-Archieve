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


vector <int> a[9];
vector<ipair> edge;
int n,x,y,m;
map<ipair,int> M;

lli F(vector <int> c){
    lli co=0,ans=0;
    M.clear();

    rep(i,7,0)rep(j,7,1){
        if(c[i]==7)c[i]=j;
        else continue;
        M.clear();
        co=0;
        for(auto x: edge){
            if(!M.count({c[x.ff-1],c[x.ss-1]})){
                co++;
                M[{c[x.ff-1],c[x.ss-1]}]++;
                M[{c[x.ss-1],c[x.ff-1]}]++;
            }
        }
        ans=max(ans,co);

    }

    return ans;
}

int main()
{
    fastio;
    cin>>n>>m;
    rep(i,m,0){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        edge.pb({x,y});
    }

    if(n<7){
        cout<<m<<endl;
        return 0;
    }

    lli ans=0;
    vector <int> c = {1,2,3,4,5,6,7};

    do{
        ans=max(ans,F(c));
    }while(next_permutation(all(c)));

    cout<<ans<<endl;

}