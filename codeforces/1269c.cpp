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
    lli n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int f=1;
    rep(i,n-k,0)if(s[i]!=s[i+k]){
        f=0;
        break;
    }

    if(f){
        cout<<n<<endl;
        cout<<s<<endl;
        return 0;
    }

    string s1 = s;
    for(int i=0;i<k;i++){
        for(int j=i+k;j<n;j+=k)s1[j]=s1[i];
    }
    
    if(s1>s){
        cout<<n<<endl<<s1<<endl;
        return 0;
    }

    rep(i,k,0){
        if(i == k-1){
            if(s[i] != '9'){
                s[i]=(char)(s[i]+1);
            }
        }
        for(int j=i;j<n;j+=k){
            s[j]=s[i];
        }
    }
    cout<<n<<endl;
    cout<<s<<endl;
}