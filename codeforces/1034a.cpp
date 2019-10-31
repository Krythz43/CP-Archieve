#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define N 15001000
#define LB lower_bound
#define M 1000000007
#define UB upper_bound
#define MP make_pair
#define LD long double
#define F first
#define S second

int main()
{
    LL a[300001],i,j,l,m,n,x,y,z,k,t,f;
    bool pr[N];
    int ct[N];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    fill(pr,pr+N,true);
    fill(ct,ct+N,0);
    cin>>a[0];
    x=a[0];
    for(i=1;i<n;i++)
    {
        cin>>a[i];
        x=__gcd(x,a[i]);
    }
    for(i=0;i<n;i++)
    {
        a[i]/=x;
        ct[a[i]]++;
    }
    if(ct[1]==n)
    {
        cout<<-1<<endl;
            return 0;
    }
    y=n;
    for(i=2;i<N;i++)
        if(pr[i])
        {
            x=ct[i];
            for(j=i+i;j<N;j+=i)
            {
                pr[j]=false;
                x+=ct[j];
            }
            y=min(y,n-x);
        }
    cout<<y;    
}