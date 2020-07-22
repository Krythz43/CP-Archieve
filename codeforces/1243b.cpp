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


// Hard Version


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<ipair> swaps;
        rep(i,n - 1,0){
            if(s[i] == t[i])continue;
            rep(j,n,i + 1){
                if(s[i] == s[j]){
                    swap(t[i],s[j]);
                    swaps.pb(mp(j + 1,i + 1));
                    break;
                }
            }

            if(s[i] == t[i])continue;
            rep(j,n,i + 1){
                if(t[i] == t[j]){
                    swap(s[i],t[j]);
                    swaps.pb(mp(i + 1,j + 1));
                    break;
                }
            }

            if(s[i] == t[i])continue;
            rep(j,n,i + 1){
                if(s[i] == t[j]){
                    swap(s[n-1],t[j]);
                    swap(t[i],s[n-1]);
                    swaps.pb(mp(n,j + 1));
                    swaps.pb(mp(n,i + 1));
                    break;
                }
            }

            if(s[i] == t[i])continue;
            rep(j,n,i + 1){
                if(t[i] == s[j]){
                    swap(t[n-1],s[j]);
                    swap(s[i],t[n-1]);
                    swaps.pb(mp(j + 1,n));
                    swaps.pb(mp(i + 1,n));
                    break;
                }
            }

            if(s[i] != t[i])break;            
        }

        int f = 1;
        rep(i,n,0)if(s[i] != t[i]){
            f = 0;
            break;
        }

        if(f){
            cout<<"Yes"<<endl;
            cout<<swaps.size()<<endl;
            for(auto  x :swaps)cout<<x.ff<<" "<<x.ss<<endl;
        }
        else cout<<"No"<<endl;
    }
}

// Easy Version

// int main()
// {
//     fastio;
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         string s,t;
//         cin>>s>>t;
        

//         rep(i,n,0){
//             if(s[i] == t[i])continue;
//             rep(j,n,i + 1){
//                 if(s[i] == t[j] && t[i] == s[j]){swap(s[j],t[i]);break;}
//             }

//             if(s[i] == t[i])break;
//             rep(j,n,i + 1){
//                 if(s[i] == s[j] && t[i] == t[j]){swap(s[j],t[i]);break;}
//             }
//             break;
//         }

//         int f = 1;
//         rep(i,n,0)if(s[i] != t[i]){
//             f = 0;
//             break;
//         }

//         if(f)cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }