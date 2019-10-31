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
    int n;
    cin>>n;
    vinput(a,n);

    map<int,int> M,M1,M2;
    int p1=0,p2=n-1;
    int z=0;
    rep(i,n,0){
        if(M.count(a[i])){
            if(M[a[i]]==1)
            z++;
        }
        M[a[i]]++;
    }

    lli ans=n;
    if(z==0){
        cout<<0<<endl;
        return 0;
    }

    rep(i,n,0){
        M2=M;
        int cu=z;
        rep(j,n,i){
            M2[a[j]]--;
            if(M2[a[j]]==1)
            cu--;
            if(cu==0){
                ans=min(ans,(lli)(j-i+1));
                break;
            }
        }
        if(M1.count(a[i])){
            break;
        }
        M1[a[i]]++;
    }

    cout<<ans<<endl;
}