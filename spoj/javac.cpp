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
// #define endl '\n'

int main()
{
    fastio;
    string s;
    while(cin>>s)
    {
        int c=0,j=0;
        int n=s.length();
        rep(i,n,0)
        {
            if(s[i]=='_')
            c++;

            if(s[i]>='A' && s[i]<='Z')
            j++;
        }

        int f=0;

        rep(i,n,1)
        {
            if(s[i]==s[i-1] && s[i]=='_')
            f=1;
        }

        if(c && j || s[n-1]=='_' || s[0]<='Z' || f || s[0]=='_')
        {
            cout<<"Error!"<<endl;
            continue;
        }

        if(j==0)
        {
            int p=0;
            while(p<n)
            {
                // cout<<"here1"<<endl;
                if(s[p]=='_')
                {
                    cout<<(char)(s[p+1]-32);
                    p+=2;
                }
                else
                cout<<s[p++];
            }
        }
        else
        {
            int p=0;
            while(p<n)
            {
                // cout<<"here2"<<endl;
                if(s[p]<='Z')
                {
                    cout<<"_"<<(char)(s[p]+32);
                    p++;
                }
                else
                cout<<s[p++];
            }
        }
        nl;
    }
}