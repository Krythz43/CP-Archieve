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
    /*
    2 = 2
    3 = 3
    4 = 2!2!3!
    5 = 5
    6 = 3!*5!
    7! = 7!
    8! = 2!2!2!7!
    9! = 3*3*2*2*2!7!
    */

    map<int,int> M;
    lli n;
    cin>>n;
    cin>>n;
    while(n){
        int x = n%10;
        if(x == 2 || x == 3|| x == 5 || x == 7)M[x]++;
        else if(x == 4)M[2]+=2,M[3]++;
        else if(x == 6){
            M[3]++;
            M[5]++;
        }
        else if(x == 8){
            M[2]+=3;
            M[7]++;
        }
        else if(x == 9){
            M[3]+=2;
            M[2]++;
            M[7]++;
        }
        n/=10;
    }

    for(int i = 7 ; i>1 ;i--){
        if(M.count(i)){
            string r(M[i],i+'0');
            cout<<r;
        }
    }
    nl;
}
