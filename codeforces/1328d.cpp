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

        lli mn=a[0],mx=a[0];
        rep(i,n,0){mn=min(mn,a[i]);mx=max(mx,a[i]);}
        if(mn==mx){
            cout<<1<<endl;
            rep(i,n,0){
                cout<<"1 ";
            }
            nl;
            continue;
        }
        if(n%2 == 0){
            cout<<2<<endl;
            rep(i,n/2,0)cout<<"1 2 ";
            nl;
        }
        else{
            int f=0;
            rep(i,n,0)if(a[i] == a[i+1]){
                f=1;
                break;
            }

            if(!f && a[0] == a[n-1]){
                cout<<2<<endl;
                rep(i,n/2,0)cout<<"1 2 ";
                cout<<1<<endl;
            }
            else if(!f){
                cout<<3<<endl;
                rep(i,n/2,0)cout<<"1 2 ";
                cout<<3<<endl;
            }
            else{
                int cur = 0;
                cout<<2<<endl;
                rep(i,n,0){
                    cout<<cur+1<<" ";
                    if(f && a[i] == a[i+1]){
                        cout<<cur+1<<" ";
                        f=0;
                        i++;
                    }
                    cur=(cur^1);
                }
                nl;
            }
        }

    }
}