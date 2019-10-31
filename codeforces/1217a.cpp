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

// int main()
// {
//     fastio;
//     int t;
//     cin>>t;
//     while(t--){
//         int s,i,e;
//         cin>>s>>i>>e;
//         // if(s<i){
//         //     int z=min(e,i-s);
//         //     s+=z;
//         //     e-=z;
//         // }

//         if(e==0){
//             if(s>i)cout<<1<<endl;
//             else cout<<0<<endl;
//             continue;
//         }

//         int ans=(i+e-s)/2;
//         ans=max(0,e-ans);
//         cout<<ans<<endl;
//     }
// }

int s,i,e;

bool F(int x){
    return s+x>i+e-x;
}

int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>s>>i>>e;
        int hi=e,lo=0,mid;
        
        while(hi-lo>1){
            mid=(hi+lo)/2;
            if(F(mid))hi=mid;
            else lo=mid;
        }

        if(F(lo))hi=lo;

        if(F(e)==false)cout<<0<<endl;
        else cout<<e-hi+1<<endl;
    }
}