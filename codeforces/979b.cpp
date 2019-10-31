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
    lli n,a=0,b=0,c=0;
    cin>>n;
    map <char,lli> M;

    string s;
    cin>>s;
    rep(i,s.length(),0){
        M[s[i]]++;
        a=max(M[s[i]],a);
    }

    M.clear();
    cin>>s;
    rep(i,s.length(),0){
        M[s[i]]++;
        b=max(M[s[i]],b);
    }

    cin>>s;
    M.clear();
    rep(i,s.length(),0){
        M[s[i]]++;
        c=max(M[s[i]],c);
    }

    // cout<<a<<" "<<b<<" "<<c<<" "<<s.length()<<endl;

    

    if(n==1){
        if(a==s.length())a--;
        else a++;
        if(b==s.length())b--;
        else b++;
        if(c==s.length())c--;
        else c++;
    }
    else{
        a=min((lli)s.length(),a+n);
        b=min((lli)s.length(),b+n);
        c=min((lli)s.length(),c+n);
    }

    // cout<<a<<" "<<b<<" "<<c<<endl;

    lli a1=a,b1=b,c1=c;

    if(a==b || b==c || a==c){
        if(a<b)swap(a,b);
        if(a<c)swap(a,c);
        if(b<c)swap(b,c);

        if(a==b){
            cout<<"Draw"<<endl;
            return 0;
        }
    }

    a=a1,b=b1,c=c1;

    if(a>b && a>c)cout<<"Kuro"<<endl;
    else if(b>c)cout<<"Shiro"<<endl;
    else cout<<"Katie"<<endl;
}