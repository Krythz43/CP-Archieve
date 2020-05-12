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

int n,k;
vector <string> num = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector <string> a;
int dp[2005][2005][10];

int cal[2005][10];

int f = 0;
vector<int> ans;

void Cal(int i, int j){
    int c = 0;
    rep(p,7,0)
    if(a[i][p] != num[j][p]){
        if(a[i][p] == '0')c++;
        else{
            cal[i][j] = inf;
            return;
        }
    }

    cal[i][j] =  c;
}

int solve(int idx,int left, int x){
    if(idx == n){
        if(left == 0){
            // cout<<"magic is happening!"<<endl;
            return 1;
        }
        else return 0;
    }

    int & ans = dp[idx][left][x];
    if(ans != -1)return ans;

    ans = 0;

    if(cal[idx][x] == inf || cal[idx][x] > left)return ans;
    left -= cal[idx][x];

    rep(i,10,0)ans |= solve(idx + 1,left,i);
    return ans;
}

int getans(int idx,int left){

    if(n == idx)return 1;
    int f = -1;

    for(int i = 9; i>= 0 ; i--){
        if(dp[idx][left][i] == 1){
            f = i;
            break;
        }
    }

    if(f == -1)return -1;
    ans.pb(f);
    return f = getans(idx+1,left - cal[idx][f]);
}

int main(){
    fastio;
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    memset(cal,0,sizeof cal);
    a.resize(n);
    rep(i,n,0)cin>>a[i];
    rep(i,n,0)rep(j,10,0)Cal(i,j);

    rep(i,10,0)solve(0,k,i);

    // rep(i,n,0)rep(j,10,0)cout<<cal[i][j]<<endl;

    int f = getans(0,k);

    if(f == -1)cout<<-1;
    else rep(i,n,0)cout<<ans[i];
    nl;
}