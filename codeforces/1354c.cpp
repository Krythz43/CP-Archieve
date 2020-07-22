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

const long double PI = 3.14159265358979323846;

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        long double  n;
        cin>>n;
        long double angle = 360/((long double)2.0 * n);

        // cout<<"anglr "<<angle<<endl;
        // long double x = sin(angle*PI/180);
        long double ans = 1.0;
        rep(i,n/2-1,0){
            ans += 2*sin((i+1)*angle*PI/180);
        }

        cout<<std::fixed<<std::setprecision(20)<<ans<<endl; 
    }
}