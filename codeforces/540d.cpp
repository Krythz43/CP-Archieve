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

typedef long double ld;
 
ld a[105][105][105];
 
int main() {
    int R, S, P;
    cin >> R >> S >> P;
 
    a[R][S][P] = 1;
    for (int sum = R + S + P; sum > 0; sum--) {
        for (int r = R; r >= 0; r--) {
            for (int s = S; s >= 0; s--) {
                int p = sum - r - s;
                if (p < 0 || p > P) continue;
                if (r == 0 && s == 0) continue;
                if (r == 0 && p == 0) continue;
                if (s == 0 && p == 0) continue;
                ld cur = a[r][s][p];
                int waysR = r*s;
                int waysS = s*p;
                int waysP = p*r;
                int totalWays = waysR + waysS + waysP;
                if (r>0)a[r - 1][s][p]+=cur*waysP/totalWays;
                if (s>0)a[r][s - 1][p]+=cur*waysR/totalWays;
                if (p>0)a[r][s][p - 1]+=cur*waysS/totalWays;
            }
        }
    }
 
    ld ansR = 0;
    ld ansS = 0;
    ld ansP = 0;
    for (int r=1;r <= R; r++) ansR += a[r][0][0];
    for (int s=1;s <= S; s++) ansS += a[0][s][0];
    for (int p=1;p <= P; p++) ansP += a[0][0][p];

    cout<< fixed << setprecision(20) << ansR << " " << ansS << " " << ansP << endl;
}