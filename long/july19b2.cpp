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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vi a(n);
 
        rep(i,n,0)
        cin>>a[i];
        int sum=0,c=0,flag=1;

        int counter=0;
 
        rep(i,n,0)
        {
            rep(j,n,i)
            {
                counter++;

                flag=1;
                rep(k,j+1,i)
                {
                    sum=0;
                    rep(q,j+1,k)
                    {
                        cout<<a[q]<<" ";
                        sum+=a[q];
                        cout<<"\ncounter "<<counter<<" is claiming sum of"<<sum<<endl;
                        if(sum%m!=0)
                        {
                            flag=0;
                    }                      
                    }
                }
                if(flag)
                c++;            
            }
        }
        cout<<c<<endl;
    }
} 