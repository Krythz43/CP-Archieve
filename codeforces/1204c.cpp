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
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)if(a[i][j]==INT_MAX)cout<<0<<" ";else cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n;
    lli adj[105][105];
    cin>>n;
    string s;
    rep(i,105,0)rep(j,105,0)adj[i][j]=inf;

    rep(i,n,0){
        cin>>s;
        rep(j,n,0)if(s[j]=='1')adj[i+1][j+1]=1;else adj[i+1][j+1]=inf;
    }

    // displaymatrix(adj,4,4)

    for (int k = 0; k < 105; k++)    
    for (int i = 0; i < 105; i++)  
    for (int j = 0; j < 105; j++)
    if (adj[i][k] + adj[k][j] < adj[i][j])  adj[i][j] = adj[i][k] + adj[k][j];

    // nl;
    // displaymatrix(adj,4,4)

    int m;
    cin>>m;
    vinput(a,m);
    vlli ans;
    ans.pb(a[0]);

    int j;

    for(int i=0;i<m;){

        if(i==m-1){
            ans.pb(a[m-1]);
            break;
        }

        lli nom=a[i+1],dis=adj[a[i]][a[i+1]];

        // cout<<"search "<<i<<" "<<a[i]<<" "<<nom<<" "<<dis<<endl;

        for(j=i+2;j<m;){
            if(a[i]==a[j]){j--;break;}
            // cout<<"dis "<<adj[a[j-1]][a[j]]+dis<<' '<<adj[a[i]][a[j]]<<" "<<a[j-1]<<' '<<a[i]<<endl;
            if(adj[a[j-1]][a[j]]+dis == adj[a[i]][a[j]]){
                dis+=adj[a[j-1]][a[j]];
                nom=a[j];
                j++;
            }
            else{
                j--;
                break;
            }
        }
        ans.pb(nom);
        i=j;
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size(),0)cout<<ans[i]<<" ";
    nl;
}