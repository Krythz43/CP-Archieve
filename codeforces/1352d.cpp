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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vinput(a,n);

        lli movs = 0,A = 0,B = 0;
        lli t1=0,prev=0;
        lli p1 = 0,p2 = n-1;

        int turn = 1;
        while(p1 <= p2){
            movs++;
            prev = t1;
            t1 = 0;

            if(turn){
                while(t1 <= prev && p1 <= p2){
                    t1 += a[p1];
                    p1++;
                }
                A += t1;
            }
            else{
                while(t1 <= prev && p1 <= p2){
                    t1 += a[p2];
                    p2--;
                }
                B += t1;
            }
            turn ^= 1;
        }

        cout<<movs<<" "<<A<<" "<<B<<endl;
    }
}