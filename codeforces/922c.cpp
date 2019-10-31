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
// #define endl '\n'

int main()
{
    fastio;
    lli n,k;
    cin>>n>>k;
    map<int,int> M;
    // int maxe=0;
    // for(int i=1;i<10000;i+=2){
    //     int f=1;
    //     cout<<"calculating "<<i<<endl;
    //     // cout<<i<<":";
    //     rep(j,10000,1){
    //         M.clear();

    //         for(int k=1;k<=j;k++){
    //             if(M.count(i%k)){
    //                 f=0;
    //                 break;
    //             }
    //             M[i%k]++;
    //         }
    //         if(f){
    //         // cout<<" "<<j;
    //         maxe=max(maxe,j);
    //         }
    //     }
    //     // nl;
    // }

    if(n%2==0){
        if(k==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    else{
        rep(i,min(100*1LL,k+1),1){
            if(M.count(n%i)){
                cout<<"No"<<endl;
                return 0;
            }
            M[n%i]++;
        }
        cout<<"Yes"<<endl;
    }

    // cout<<maxe<<endl;
}