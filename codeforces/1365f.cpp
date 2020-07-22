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
       int n;
       cin>>n;
       vinput(a,n);
       vinput(b,n);

       map<ipair,int> M;
       int x,y;
       if(n % 2 && a[n/2] != b[n/2]){
           cout<<"No"<<endl;
           continue;
       }

       rep(i,n/2,0){
           x = a[i],y = a[n - 1 - i];
           if(x > y)swap(x,y);
           M[{x,y}]++;
       }

       rep(i,n/2,0){
           x = b[i],y = b[n - 1 - i];
           if(x > y)swap(x,y);
           M[{x,y}]--;
       }

       int f = 1;

       for(auto x: M)if(x.ss)f = 0;
       if(f)cout<<"Yes"<<endl;
       else cout<<"No"<<endl;
   }
}