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
    rep(Q,t+1,1){
        lli n,m;
        cin>>n>>m;
        vinput(a,n);
        // lli x=1;
        // lli maxe=0;
        // rep(i,n,0)maxe=max(maxe,a[i]);

        lli ans=-1;
        rep(i,1000,0){
            lli sum=0;
            rep(j,n,0)sum+=(a[j]^i);
            if(sum<=m)ans=i;
        }
        cout<<"Case #"<<Q<<": ";
        cout<<ans<<endl;

        // while(x<maxe)x<<=1;
        // if(x!=maxe)x>>=1;

        // lli ans=0,sum=0,to;
        // while(x){
        //     lli osum=0,zsum=0;
        //     rep(i,n,0){
        //         to=(x&a[i]);
        //         if(to==0)osum+=x;
        //         else zsum+=x;

        //     }
        //     // cout<<x<<" "<<" "<<ans<<" "<<sum<<" "<<osum<<" "<<zsum<<endl;
        //     osum+=sum;
        //     zsum+=sum;
        //     if(osum<=m && zsum<=m){
        //         if(osum<zsum)sum=zsum;
        //         else{
        //             sum=osum;
        //             ans+=x;
        //         }
        //     }else if(osum<=m){
        //         sum=osum;
        //         ans+=x;
        //     }
        //     else sum=zsum;

        //     x>>=1;
        // }

        // int f=0;
        // lli tsum=0;
        // rep(i,n,0){
        //     tsum+=(ans^a[i]);
        // }
        // // cout<<ans<<" "<<tsum<<endl;
        // 
        // if(tsum<=m){
        //     // x=1;
        //     // lli itr=1;
        //     // while(itr<m)itr<<=1;
        //     // if(itr!=m)itr>>=1;

        //     // while(x<maxe)x<<=1;
        //     // if(x!=maxe)x>>=1;

        //     // while(x<itr){
        //     //     if(tsum+itr*n<=m){
        //     //         // cout<<"stuck"<<endl;
        //     //         ans+=itr;
        //     //         tsum+=itr*n;
        //     //     }
        //     //     itr>>=1;
        //     // }

        //     cout<<ans<<endl;
        // }
        // else cout<<-1<<endl;
    }
}