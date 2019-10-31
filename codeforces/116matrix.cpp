#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

lli mod=1e9+7;

vector <vlli> multiply(vector <vlli> a, vector <vlli>b) 
{ 
    vector<vlli> mul(2,vlli(2)); 
    for (lli i = 0; i < 2; i++) 
    { 
        for (lli j = 0; j < 2; j++) 
        { 
            mul[i][j] = 0; 
            for (lli k = 0; k < 2; k++) 
            mul[i][j] += (a[i][k]*b[k][j])%mod; 
        } 
    } 
    for (lli i=0; i<2; i++) 
    for (lli j=0; j<2; j++) 
    (a[i][j] = mul[i][j])%mod;

    return a;
} 

vector<vlli> power(vector <vlli> F, lli n) 
{ 
    vector<vlli> M(2,vlli(2));
    M[0][0]=2;
    M[0][1]=1;
    M[1][0]=3;
    M[1][1]=0;
    if (n==1) 
    return M;
    F=power(F, n/2);   
    F=multiply(F, F);   
    if (n%2 != 0) 
    F=multiply(F, M); 
    return F ; 
}

lli solve(lli n) 
{ 
    
    vector<vlli> F(2,vlli(2));
    F[0][0]=2;
    F[0][1]=1;
    F[1][0]=3;
    F[1][1]=0;
    F=power(F, n); 

    // displaymatrix(F,2,2)
    return (F[1][1])%mod;

} 

int main()
{
    fastio;
    lli n;
    cin>>n;
    cout<<solve(n)<<endl;
}