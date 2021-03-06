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
        vector<lli> a(32,0);
        a[0] = 1;
        lli d,m;
        cin>>d>>m;
        rep(i,32,1){
            if(d<=a[i-1])break;
            a[i]=min(d,(1LL<<(i+1))-1LL);
            // cout<<i<<' '<<a[i]<<endl;
        }

        for(int i=31;i>0;i--){
            if(!a[i])continue;
            a[i]-=a[i-1];
        }

        // printarray(a,32)

        lli ans=0;
        lli prod=1;
        rrep(i,31){

            if(a[i] == 0){
                prod = 1;
                continue;
            }
            prod=prod*(a[i]+1)%m;
            // ans=(ans+ prod) %m;
        }
        prod=(prod+m-1)%m;
        cout<<prod<<endl;
    }
}