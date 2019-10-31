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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        string s1,s2;
        s1=s2="";
        vi hash(26,0);
        rep(i,n,0)
        hash[s[i]-97]++;
        for(int i=0;i<26;i++){
            while(hash[i]--)
            if(i%2)s1+=(char)(97+i);
            else s2+=(char)(97+i);
        }
        int f=1,f1=1,f2=1;
        s=s1+s2;
        rep(i,s.length()-1,0){
            int t=s[i]-s[i+1];
            // cout<<t<<" ";
            if(t==1 || t==-1){
                f1=0;
                break;
            }
        }
        s=s2+s1;
        rep(i,s.length()-1,0){
            int t=s[i]-s[i+1];
            // cout<<t<<" ";
            if(t==1 || t==-1){
                f2=0;
                break;
            }
        }
        f=f1+f2;
        string ans;
        if(f1)
        ans=s1+s2;
        if(f2)
        ans=s2+s1;

        if(f){
            cout<<ans<<endl;
        }
        else{
            cout<<"No answer"<<endl;
        }
    }
}