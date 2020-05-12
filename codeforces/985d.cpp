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

lli n,h;
lli X;

bool F(lli mid){
    lli x = max((mid-h+2)/2,0LL);
    // mid-x to 1 
    return x*(h+h-1+x)/2+(mid-x)*(mid-x+1)/2 >=n;
}

bool F2(lli x){
    lli N=h+1+(x-1)/2;

    lli tot=(N*(N+1))-h*(h+1);
    if((x-1)%2)tot+=N;
    cout<<"Generated "<<x<<" :"<<tot<<endl;
    return tot>=X;
}


int main()
{
    fastio;
    cin>>n>>h;
    lli hi=sqrt(1e19),lo=1;

    lli mid;
    while(hi-lo>0){
        mid=(lo+hi)/2;
        if(F(mid))hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<endl;
}