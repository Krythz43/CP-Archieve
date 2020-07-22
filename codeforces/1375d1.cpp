
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

vlli a,ans,present;
int n;

bool solved(){
    rep(i,n,1)if(a[i] < a[i - 1])return false;
    return true;
}

int find_mex(){
    // cout<<"access"<<endl;
    rep(i,n + 1,0)present[i] = 0;

    rep(i,n,0)if(a[i] <= n)present[a[i]]++;
    rep(i,n + 1,0)if(present[i] == 0){
        // printarray(a,n)
        // cout<<"reutnr mex "<<i<<endl;
        return i;
    }
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ans.clear();
        a.resize(n);
        present.resize(n + 1);
        ainput(a,n);

        rep(i,n,0){
            if(a[i] == i)continue;

            for(int j = i + 1;j < n;)if(a[j] == i){
                // cout<<"i acc ";
                int mex = find_mex();
                // printarray(a,n)
                if(mex == i){
                    break;
                }

                if(mex < n && a[mex] != mex){
                    ans.pb(mex + 1);
                    a[mex] = mex;
                    if(mex == j)j++;
                }
                else{
                    ans.pb(j + 1);
                    a[j] = mex;
                    j++;
                }
            }else j++;

            ans.pb(i + 1);

            // cout<<"f acc ";

            int mex = find_mex();
            a[i] = mex;
        }

        cout<<ans.size()<<endl;
        printarray(ans,ans.size())

        // printarray(a,n)
    }
}