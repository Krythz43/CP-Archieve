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
        vi pos[201];
        vinput(a,n);

        int c[n+5][201];
        
        rep(i,n,0){
            pos[a[i]].pb(i+1);
            rep(k,201,1)c[i+1][k]=c[i][k];
            c[i+1][a[i]]++;
        }

        int ans=0;

        rep(i,201,1){
            ans=max(ans,(int)pos[i].size());

            if(pos[i].size()<2)continue;
            int l=0;
            int r=pos[i].size()-1;
            int temp=2;
            while(l<r)
            {
                int mx=0;
                rep(j,201,1){
                    mx=max(mx,c[pos[i][r]-1][j]-c[pos[i][l]][j]);
                }
                ans=max(ans,temp+mx);
                l++;r--;
                temp+=2;
            }
        }
        cout<<ans<<endl;
    }
}