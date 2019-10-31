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

lli cbrt(lli x){
    lli hi = std::cbrt(x)+100, lo=0;
    while(hi-lo>1){
        lli mid=(hi+lo)/2;
        if(mid*mid*mid>x)hi=mid;
        else lo=mid;
    }
    if(lo*lo*lo == x)return lo;
    else return hi;
}

int main()
{
    fastio;
    int n;
    cin>>n;
   while(n--){ 
    lli a,b;
    cin>>a>>b;
    lli c=a*b;
    lli root=cbrt(c);
    lli A=a,B=b;
//     map<lli,lli> M;

//     for(lli i=2;i<=sqrt(a);i++){
//         if(a%i == 0){
//             lli co=0;
//             while(a%i == 0){
//                 co++;
//                 a/=i;
//             }
//             M[i]+=co;
//         }
//     }
//     if(a>1)M[a]++;

//   for(lli i=2;i<=sqrt(b);i++){
//         if(b%i == 0){
//             lli co=0;
//             while(b%i == 0){
//                 co++;
//                 b/=i;
//             }
//             M[i]+=co;
//         }
//     }
//     if(b>1)M[b]++;


//     lli gcd;
//     for(auto x:M){
//         gcd=x.ss;
//         break;
//     }
//     lli root=1;
//     for(auto x: M){
//         // cout<<"fac "<<x[i].ff<<" "<<x[i].ss<<endl;
//         if(x.ss%3 != 0){
//             cout<<"No"<<endl;
//             goto done;
//         }
//         else x.ss/=3;
//         gcd=__gcd(x.ss,gcd);
//         root*=pow(x.ff,x.ss);
//     }

    // cout<<root<<" "<<a*b<<endl;
    if(A%root == 0 && B%root==0 && root*root*root == a*b)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    done:;
    }
}