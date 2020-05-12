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

using cd = complex <double>;
const double PI = acos(-1);


void fft(vector<cd> &a, bool invert){
    int n = a.size();
    if(n==1)return;

    vector<cd> a0(n/2),a1(n/2);
    for(int i = 0; 2*i<n;i++){
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2*PI/n*(invert?-1:1);
    cd w(1),wn(cos(ang),sin(ang));

    for(int i=0;2*i<n;i++){
        a[i] = a0[i] + w*a1[i];
        a[i+n/2] = a0[i] - w*a1[i];
        if(invert){
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vlli multiply(vlli const &a, vlli const &b){
    int n=1;
    while(n<a.size()+b.size())n<<=1;
    vector<cd> fa(all(a)),fb(all(b));
    fa.resize(n);
    fb.resize(n);

    fft(fa,false);
    fft(fb,false);

    rep(i,n,0)fa[i]*=fb[i];
    fft(fa,true);
    vlli res(n);
    rep(i,n,0)res[i]=round(fa[i].real());

    return res; 
}

int main()
{
    fastio;
    lli n,m,p;
    cin>>n>>m>>p;
    vinput(a,n);
    vinput(b,m);

    int ans1 = 0, ans2 = 0;

    rep(i,n,0)if(a[i]%p == 0)ans1++;else break;
    rep(i,m,0)if(b[i]%p == 0)ans2++;else break;
    cout<<ans1 + ans2<<endl;
}