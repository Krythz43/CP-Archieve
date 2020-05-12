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

const lli S = 1e5+5;

int main()
{
    fastio;
    int n,k;
    cin>>n>>k;
    vinput(a,n);
    map <lli,lli> need,donr;
    lli buf=0;

    rep(i,n,0){
        lli temp = a[i],co,to,req=1,don=1;
        for(int j=2;j<=sqrt(temp);j++){
            if(temp%j == 0){
                co=0;
                while(temp%j == 0){
                    co++;
                    temp/=j;
                }
                co%=k;
                if(co!=0){
                    to = co;
                    co=k-co;
                    while(co--){
                        if(req>S)break;
                        req*=j;
                        if(req>S)break;
                    }

                    while(to--){
                        if(don>S)break;
                        don*=j;
                        if(don>S)break;
                    }
                }
            }
        }
        if(temp>1){
            co = k-1;
            to = 1;
            while(co--){
                if(req>S)break;
                req*=temp;
                if(req>S)break;
            }

            while(to--){
                if(don>S)break;
                don*=temp;
                if(don>S)break;
            }
        }

        // cout<<i<<" "<<req<<" "<<don<<endl;

        if(req < S){
            need[req]++;
        }

        if(don<S){
            donr[don]++;
        }

        if(req<S && don<S && req == don){
            buf++;
        }
    }
    lli ans=0;

    // cout<<"needed"<<endl;
    for(auto x: need){
        // cout<<x.ff<<" "<<x.ss<<endl;
        if(donr.count(x.ff)){
            ans+=x.ss*donr[x.ff];
        }
    }
    // cout<<"donors"<<endl;
    // for(auto x: donr){
        // cout<<x.ff<<" "<<x.ss<<endl;
    // }
    cout<<(ans-buf)/2<<endl;
}