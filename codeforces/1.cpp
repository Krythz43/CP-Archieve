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

bool isprime(int n){
    if(n==2)return true;
    if(n%2==0 || n==1)return false;
    for(int i=3;i<=sqrt(n);i+=2){
        if(n%i == 0)return false;
    }
    return true;
}
int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    lli sum=0,cs=0;
    rep(i,n,0){
        int x=a[i]>0?a[i]:-a[i];
        if(x%2)cs++;
        sum+=a[i]/2;
    }

    rep(i,n,0){
        int x=a[i]>0?a[i]:-a[i];
        if(x%2){
            if(sum==0 || x%2 == 0)cout<<a[i]/2;
            else if(sum > 0){
                if(a[i]>=0)cout<<a[i]/2;
                else {cout<<a[i]/2-1;sum--;}
            }
            else{
                if(a[i]>=0){cout<<a[i]/2+1;sum++;}
                else cout<<a[i]/2;   
            }
        }
        else cout<<a[i]/2;
        nl;
    }
}