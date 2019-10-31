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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int hashU[26],hashL[26];
    memset(hashU,0,sizeof hashU);
    memset(hashL,0,sizeof hashL);
    rep(i,n,0){
        if(isupper(s[i]))hashU[s[i]-65]++;
        else hashL[s[i]-97]++;
    }

    int k=0;
    rep(i,26,0)if(hashL[i])k++;
    rep(i,26,0)if(hashU[i])k++;
    int lo=1,hi=n,mid;
    function<bool(int)> F=[&](int d)->bool{
        map<char,int> M;
        int iq=0;        
        int p1=0,p2=d-1;
        for(int i=0;i<=p2;i++){
            if(M.count(s[i])==0)iq++;
            M[s[i]]++;
        }
        int it=0;
        while(1){
            if(iq>=k)return true;
            M[s[p1]]--;
            if(M[s[p1]]==0)iq--;
            p1++;
            p2++;
            if(p2==n)break;
            M[s[p2]]++;
            if(M[s[p2]]==1)iq++;
        }
        return false;
    };

    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(F(mid))
        hi=mid;
        else
        lo=mid;
    }
    if(F(lo))cout<<lo<<endl;
    else cout<<hi<<endl;
}