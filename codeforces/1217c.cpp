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
        string s;
        cin>>s;
        int n=s.length();

        vi a(n);
        a[0]=-1;
        rep(i,n-1,0){
            if(s[i]=='1')a[i+1]=i;
            else a[i+1]=a[i];
        }

        lli ans=0;

        for(int i=n-1;i>=0;i--){
            int zes=0;
            for(int j=0;j<20;j++){
                if(i-j<0)break;
                if(s[i-j]=='1'){
                    zes|=(1<<j);
                    if(i-zes>=a[i-j]){
                        ans++;
                        // cout<<i<<" "<<i-j<<endl;
                    }
                }
            }
        }

        cout<<ans<<endl;
    }
}