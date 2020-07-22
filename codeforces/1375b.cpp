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
        int n,m;
        cin>>n>>m;
        int a[n][m];

        rep(i,n,0)rep(j,m,0)cin>>a[i][j];
        int f = 1;

        rep(i,n,0)
        rep(j,m,0){
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                if(i == 0){
                    if(j == 0 || j == m - 1){
                        if(a[i][j] > 2)f = 0;
                        a[i][j] = 2;
                    }
                    else{
                        if(a[i][j] > 3)f = 0;
                        a[i][j] = 3;
                    }
                }
                else if(j == 0){
                    if(i == 0 || i == n - 1){
                        if(a[i][j] > 2)f = 0;
                        a[i][j] = 2;
                    }
                    else{
                        if(a[i][j] > 3)f = 0;
                        a[i][j] = 3;
                    }
                }

                else if(i == n - 1){
                    if(j == 0 || j == m - 1){
                        if(a[i][j] > 2)f = 0;
                        a[i][j] = 2;
                    }
                    else{
                        if(a[i][j] > 3)f = 0;
                        a[i][j] = 3;
                    }
                }
                else if(j == m - 1){
                    if(i == 0 || i == n - 1){
                        if(a[i][j] > 2)f = 0;
                        a[i][j] = 2;
                    }
                    else{
                        if(a[i][j] > 3)f = 0;
                        a[i][j] = 3;
                    }
                }
            }
            else{
                if(a[i][j] > 4)f = 0;
                a[i][j] = 4;
            }
        }

        if(f){
            cout<<"YES"<<endl;
            rep(i,n,0){
                rep(j,m,0)cout<<a[i][j]<<" ";nl;
            }
        }
        else cout<<"NO"<<endl;
    }
}