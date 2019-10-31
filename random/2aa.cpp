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

struct mini
{
    lli a;
    lli b;
};

bool comp(mini a, mini b)
{
    return a.a<b.a;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        lli ans=n,sum=0;

        vector <mini> a(n);
        pq <lli> p;

        rep(i,n,0)
        {
            cin>>a[i].a>>a[i].b;
            sum+=a[i].b;
            p.push(a[i].b);
        }
        sort(a.begin(),a.end(),comp);
        
        for(int i=0;i<n;)
        {
        double avg=sum/(double)ans;
        
        while(a[i].a==-1)
        {
            if(i<n)
            i++;
            else
            {
                ans=0;
                break;
            }
        }
        if(!ans)
        break;

       // cout<<a[i].a<<" "<<avg<<endl;
        if(a[i].a>=avg)
        {
           // cout<<a[i].a<<" "<<avg<<endl;
            break;
        }
        else
        {
            if(a[i].b==p.top())
            {
                ans--;
                sum-=a[i].b;
                a[i].a=-1;
                i++;
            }
            else
            {
                lli w=p.top();
                sum-=w;
                ans--;

                rep(j,n,i+1)
                {
                    if(a[j].b==w)
                    {
                        a[j].a=-1;
                        break;
                    }
                }

            }
        }

        }

        cout<<ans<<endl;
    }
}