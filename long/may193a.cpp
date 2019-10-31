#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false)
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
#define priority_queue pq;
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i];} cout<<endl

int main()
{
    int t;
    fastio;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int sa,sb;

        if(n%2==0)
        {
            vi a(n/2),b(n/2);

            rep(i,n,0)
            {
                if(i%2==0)
                cin>>a[i/2];
                else
                cin>>b[i/2];
            }

            
            std::sort(a.begin(),a.begin()+n/2);
            std::sort(b.begin(),b.begin()+n/2);
            sa=std::accumulate(a.begin(),a.begin()+n/2,0);
            sb=std::accumulate(b.begin(),b.begin()+n/2,0);

           // printarray(a,n/2);
           // printarray(b,n/2);

            int bp=0;
            int ap=n/2-1;

            while(1)
            {
                if(k==0 || ap<0 || bp==n/2)
                break;
                else
                {
                    if(b[bp]>a[ap])
                    break;

                    sa+=(b[bp]-a[ap]);
                    sb+=(a[ap]-b[bp]);
                }
                ap--;
                bp++;
                k--;
            }
        }
        else
        {
            vi a(n/2+1),b(n/2);

            rep(i,n,0)
            {
                if(i%2==0)
                cin>>a[i/2];
                else
                cin>>b[i/2];
            }

            std::sort(a.begin(),a.begin()+n/2+1);
            std::sort(b.begin(),b.begin()+n/2);
            sa=std::accumulate(a.begin(),a.begin()+n/2+1,0);
            sb=std::accumulate(b.begin(),b.begin()+n/2,0);

            int bp=0;
            int ap=n/2;

            while(1)
            {
                if(k==0 || ap<0 || bp==n/2)
                break;
                else
                {
                    if(b[bp]>a[ap])
                    break;
                    
                    sa+=(b[bp]-a[ap]);
                    sb+=(a[ap]-b[bp]);
                }
                ap--;
                bp++;
                k--;
            }
        }

      //  cout<<sa<<" "<<sb<<endl;
        
        if(sb>sa)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}