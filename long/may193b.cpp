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

double px,py,pz,qx,qy,qz,cx,cy,cz,dx,dy,dz,r,tr;

double ax,ay,az,bx,by,bz,ex,ey,ez,d,epl=1e-9,num,den;

bool dist(double t)
{
    ax=px-qx-dx*t;
    ay=py-qy-dy*t;
    az=pz-qz-dz*t;

   // cout<<ax<<" "<<ay<<" "<<az<<endl;

    ex=(ay*bz-az*by);
    ey=(az*bx-ax*bz);
    ez=(ax*by-bx*ay);

 //   cout<<bx<<" "<<by<<" "<<bz<<endl;
   // cout<<ex<<" "<<ey<<" "<<ez<<endl;

    den=sqrt(ax*ax+ay*ay+az*az);
    num=sqrt(ex*ex+ey*ey+ez*ez);

    tr=num/den;
   // cout<<t<<" "<<tr<<endl;
    return(tr>r);
}

int main()
{
    int t;
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
        bx=px-cx;
        by=py-cy;
        bz=pz-cz;
        double low=0,high=1000000000000,mid;

     //  cout<<high<<endl<<low<<endl;

        while(high-low>epl)
        {
            mid=(high+low)/2;
            if(dist(mid))
                high=mid;
            else
                low=mid;
        }
      //  cout<<high<<endl<<low<<endl;
        cout<<std::setprecision(15)<<std::fixed<<high<<endl;
     //   cout<<dist(1)<<endl;
    }
}