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

const int S = 25000;

int n;
int x[S],y[S],dx[S],dy[S];
double v[S]; 

double solve(int i,int j){
    double intersect = dx[j]*dy[i] - dx[i]*dy[j];

    if(intersect != 0){
        // They intersect for sure

        double l1,l2;

        l1 = x[i]*dy[i] + y[j]*dx[i] - y[i]*dx[i] - x[j]*dy[i];
        l2 = x[i]*dy[j] + y[j]*dx[j] - y[i]*dx[j] - x[j]*dy[j];

        l1 /= (intersect*v[j]);
        l2 /= (intersect*v[i]);

        if(min(l1,l2) < 0)return -1;
        return max(l1,l2);

    }
    else{
        // Parallel ones

        if((x[j] - x[i])*dy[i] != (y[j] - y[i])*dx[i]) return -1;

        double a = (x[i]*dx[i] + y[i]*dy[i]);
        double b = (x[j]*dx[i] + y[j]*dy[i]);

        double v1 = (dx[i]*dx[i] + dy[i]*dy[i])*v[i];
        double v2 = (dx[j]*dx[i] + dy[i]*dy[j])*v[j];

        if(v1*(b - a) > 0 && v2*(a - b) > 0)return (b - a)/(v1 - v2); // Meet in between
        else if(v1*(b - a) > 0) return (b - a)/v1; // Meet at j;
        else if(v2*(a - b) > 0) return (a - b)/v2; // Meet at i;
        return -1; // Never meet at all;
    }
}

int main()
{
    fastio;
    cin>>n;
    rep(i,n,0){
        cin>>x[i]>>y[i]>>dx[i]>>dy[i]>>v[i];
        v[i] /= sqrt(dx[i]*dx[i] + dy[i]*dy[i]);
    }  

    double ans = -1;

    rep(i,n,0)rep(j,n,i + 1){
        double temp = solve(i,j);
        if(temp >= 0){
            if(ans < 0)ans = temp;
            else ans = min(ans,temp);
        }
    }

    if(ans < 0)cout<<"No show :("<<endl;
    else cout<<fixed<<setprecision(20)<<ans<<endl;
}