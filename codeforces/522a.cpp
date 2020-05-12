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


string to_lower(string s){
    string ret="";
    rep(i,s.length(),0){
        if(isupper(s[i]))ret+=tolower(s[i]);
        else ret+=s[i];
    }
    return ret;
}
int main()
{
   fastio;
   map<string,int> M;
   M["polycarp"] = 1;
   int n;
   cin>>n;
   int ans = 1;
   while(n--){
       string s1,s2,s3;
       cin>>s1>>s2>>s3;
       s3=to_lower(s3);
       s1=to_lower(s1);
       int cur = M[s3]+1;
       M[s1] = cur;
       ans=max(ans,cur);
   }

   cout<<ans<<endl;
}