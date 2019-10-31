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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    vector<int> num={4,8,15,16,23,42}; 
    vector<int> a(4); 
    rep(i,4,0)
    {
        cout<<"? "<<i+1<<" "<<i+2<<"\n"<<flush;
        cin>>a[i];
    }

    do{
        int f=1;
        rep(i,4,0)
        f&=(num[i]*num[i + 1]==a[i]);
        // rep(i,4,0)
        // cout<<(num[i]*num[i + 1])<<endl;
        // cout<<f<<endl;

        if(f)
        {
            cout<<"! "; 
            rep(i,6,0)
            cout<<num[i]<<" ";
            cout<<endl<<flush;
            break; 
        }
    }while(next_permutation(num.begin(),num.end())); 

    return 0;
}
