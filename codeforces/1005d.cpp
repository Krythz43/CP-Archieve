#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

int main()
{
    fastio;
    string s;
    cin>>s;
    int l=s.length();
    vi a(l);
    rep(i,l,0)
    a[i]=s[i]-48;

    int ans=0;

    vector<int>q;

    rep(i,l,0)
    {
        int f=1;
        if(a[i]%3==0)
       { 
           ans++;
        q.clear();
       }
       else
       {
           int z=q.size();

           rep(j,z,0)
           {
               q[j]+=a[i];
            //    cout<<q[j]<<"checking for"<<a[i]<<endl;

               if(q[j]%3==0)
               {
                   ans++;
                   q.clear();
                   f=0;
                   break;
               }
           }

           if(f)
           q.pb(a[i]);
       }
    }

    cout<<ans;
}