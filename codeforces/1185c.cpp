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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    lli x;
    lli sum=0,tsum;
    int tf;
    vi hash(105);

    rep(i,n,0){
        tf=0;
        cin>>x;
        sum+=x;
        tsum=sum;
        int c=0,curr=100;
        while(tsum>m){
            if(tsum-hash[curr]*curr>m){
                tf+=hash[curr];
                tsum-=hash[curr]*curr;
                curr--;
            }
            else{
                c=(tsum-m)/curr;
                if((tsum-m)%curr)c++;
                tf+=c;
                tsum-=c*curr;
            }
        }
        hash[x]++;
        cout<<tf<<" ";
    }
    nl;
}