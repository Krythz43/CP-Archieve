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
        lli n,k;
        cin>>n>>k;
        vinput(a,n);
        if(n == 1){
            if(a[0] == k)cout<<"yes"<<endl;
            else cout<<"no"<<endl;
            continue;
        }
        else if(n == 2){
            SO(a);
            if(a[0] == k)cout<<"yes"<<endl;
            else cout<<"no"<<endl;
            continue;
        }

        int f = 0;

        rep(i,n,0)if(k == a[i])f = 1;
        if(!f){
            cout<<"no"<<endl;
            continue;
        }



        if(a[0] == k)if(a[1] > k)a[1] = k;

        if(a.back() == k)if(a[n-2] > k)a[n-2] = k;

        rep(i,n-1,1)if(a[i] == k){
            if(a[i - 1] > k)a[i-1] = k;
            if(a[i+1] > k)a[i+1] = k;
        }

        vlli b;
        f = 0;
        rep(i,n-1,1){
            b.clear();
            
            b.pb(a[i]);
            b.pb(a[i-1]);
            b.pb(a[i+1]);
            SO(b);
            if(b[1] >= k){
                f = 1;
                break;
            }
        }
        if(f)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}