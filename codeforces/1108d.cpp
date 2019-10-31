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
    int ans=0;
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=1;i<n;)
    {
        if(s[i]==s[i-1])
        {
            int t=0;   //0 prints c1 while 1 prints c2;
            char c1,c2;
            if(s[i]=='R')
            {
                c1='B';
                c2='G';
            }
            else if(s[i]=='B')
            {
                c1='R';
                c2='G';
            }
            else
            {
                c1='B';
                c2='R';
            }

            int j=i;
            while(j<n)
            {
                if(j==n-1)
                {
                    int k=i;
                    while(k<n)
                    {
                        ans++;
                        s[k]=c1;
                        k+=2;
                    }
                    break;
                }
                if(s[j]!=s[i])
                {
                    if(s[j]==c1)
                    t=1;
                    else
                    t=0;

                    if((j-i)%2==0)
                    {
                        int k=i;
                        while(k<j)
                        {
                            ans++;
                            s[k]=c1;
                            k+=2;
                        }
                        break;
                    }
                    else
                    {
                    int k=j-1;
                    while(k>=i)
                    {
                        if(t)
                        s[k]=c2;
                        else
                        s[k]=c1;

                        t=(t^1);
                        ans++;
                        k--;
                    }
                    break;}
                }
                j++;
            }
            i=j;


        }
        else
        i++;
    }

    cout<<ans<<endl;
    cout<<s<<endl;
}