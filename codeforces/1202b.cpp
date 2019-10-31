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

int main()
{
    fastio;
    string s;
    cin>>s;
    int  a[10][10][10][10];
    memset(a,-1,sizeof a);

    rep(i,10,0){
        rep(j,10,0){
            rep(k,10,0){
                int head=k;
                vector<bool> vis(10,false);
                queue <ipair> q;
                q.push({(k+i)%10,1});
                q.push({(k+j)%10,1});
                while(!q.empty()){
                    ipair X=q.front();
                    q.pop();
                    if(vis[X.ff])continue;
                    vis[X.ff]=true;
                    a[i][j][k][X.ff]=X.ss;
                    q.push({(X.ff+i)%10,X.ss+1});
                    q.push({(X.ff+j)%10,X.ss+1});
                }
            }
        }
    }

    // rep(i,10,0){
    //     cout<<a[0][1][4][i]<<" ";
    // }
    // nl;nl;


    rep(i,10,0){
        rep(j,10,0){
            lli ans=0;
            int f=1;
            rep(k,s.length(),1){
                if(a[i][j][s[k-1]-48][s[k]-48]==-1){
                    cout<<-1<<" ";
                    f=0;
                    break;
                }
                else{
                    ans+=a[i][j][s[k-1]-48][s[k]-48];
                }
            }

            if(f)cout<<ans+1-s.length()<<" ";
        }
        cout<<endl;
    }
}