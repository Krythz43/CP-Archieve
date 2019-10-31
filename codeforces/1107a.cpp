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
#define endl '\n'

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool ok=true;

        if(s.size()<3)
        ok=false;
        else if(s.size()==3)
        {
            if(s[2]>s[1] && s[1]>s[0])
            {
                cout<<"YES"<<endl;
                cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
                // return 0;
            }
            else
            ok=false;
        }
        else if(s.size()==4)
        {
            if(s[1]>s[0])
            {
                cout<<"YES"<<endl;
                cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<s[3]<<endl;
                // return 0;
            }
            else
            ok=false;
        }
        else if(s.size()==5)
        {
            if(s[1]>s[0])
            {
                cout<<"YES"<<endl;
                cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<s[3]<<s[4]<<endl;
            }
            else if(s[3]>s[1])
            {
                cout<<"YES"<<endl;
                cout<<s[0]<<" "<<s[1]<<s[2]<<" "<<s[3]<<s[4]<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;
            cout<<s[0]<<" "<<s[1]<<s[2]<<" ";
            rep(i,n,3)
            cout<<s[i];
            nl;
        }

        if(!ok)
        cout<<"NO"<<endl;


        

    }
}