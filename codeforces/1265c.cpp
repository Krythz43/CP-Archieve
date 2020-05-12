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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vinput(a,n);

        vi g(3,0);
        int p=0;

        vector <int> z;
        int c=1;

        rep(i,n,1){
            if(a[i]!=a[i-1]){
                z.pb(c);
                c=1;
            }
            else c++;
        }
        z.pb(c);

        lli tot;
        g[0]=c=tot=z[0];
        p=1;
        int l = z.size();
        // printarray(z,l)

        rep(i,l,1){
            if(p==2){
                if(tot + z[i] >n/2)break;
                else{
                    g[p]+=z[i];
                    tot+=z[i];
                }
            }
            else{
                if(g[1]<=g[0]){
                    g[p]+=z[i];
                    tot+=z[i];
                }
                else{ 
                    p++;
                    if(tot + z[i] >n/2)break;
                    else{
                        g[p]+=z[i];
                        tot+=z[i];
                    }
                }
            }
        }
        // cout<<"tot:"<<tot<<endl;

        // cout<<g[0]<<" "<<g[1]<<" "<<g[2]<<endl;
        // cout<<"ans :";

        if(
            (g[0] && g[1] && g[2] && g[0] < g[1] && g[0] < g[2] && g[0]+g[1]+g[2]<=n/2)
        ){
            cout<<g[0]<<" "<<g[1]<<" "<<g[2]<<endl;
        }
        else cout<<"0 0 0"<<endl;
    }
}