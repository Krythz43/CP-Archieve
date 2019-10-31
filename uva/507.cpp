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
lli llmax(lli a,lli b){if(a>b)return a; return b;}

int main()
{
    fastio;
    int t;
    cin>>t;
    rep(z,t,0)
    {
        int n;
        cin>>n;
        vi a(n+1);
        int lb=0,le=0,ce=0,cb=0,cl=0,maxs=-1,maxss=0;
        a[0]=a[n]=-1;
        rep(i,n,1)
        cin>>a[i];
        int maxe=*max_element(a.begin(),a.end());
        a[0]=a[n]=0;
        
        if(maxe<0)
        cout<<"Route "<<z+1<<" has no nice parts"<<endl;
        else
        {      
            int sum=0;
            rep(i,n,0)
            {
                sum+=a[i];
                maxs=max(maxs,sum);

                ce++;
                // cout<<sum<<" "<<cb<<" "<<ce<<" "<<le<<" "<<lb<<endl;
                if(sum<0)
                {
                    sum=0;
                    cb=ce;
                }
                else if(sum==maxs)
                {
                    if(maxss==maxs)
                    {
                        if(cl<ce-cb)
                        {
                            le=ce;
                            lb=cb;
                            cl=ce-cb;
                            maxss=maxs;
                        }                                          
                    }
                    else
                    {
                        le=ce;
                        lb=cb;
                        cl=ce-cb;
                        maxss=maxs;
                    }
                }
            }

            if(sum==maxs)
            {
                if(cl<ce-cb)
                {
                    le=ce;
                    lb=cb;
                    cl=ce-cb;
                }                        
            }

            if(lb==0)
            lb++;

            cout<<"The nicest part of route "<<z+1<<" is between stops "<<lb<<" and "<<le<<endl;
        }
    }
}

// 3
// 14
// -94
// -67
// 73
// 3
// 80
// 2
// -91
// -90
// -90
// 81
// 75
// 1
// 1
// 12
// -94
// -67
// 76
// 82
// -91
// -90
// -90
// 81
// 75
// 1
// 1
// 11
// 1
// 1
// 1
// -100
// 2
// 2
// -100
// 1
// 1
// 1
