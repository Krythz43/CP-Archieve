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
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int wx,wy,rx,ry,rp;
char m;

int main()
{
    fastio;
    cin>>wx>>wy;
    vector<vi > a(wx+1,vi (wy+1,1));

    while(cin>>rx)
    {
        cin>>ry>>m;
        if(m=='N')rp=0;
        else if(m=='W')rp=1;
        else if(m=='S')rp=2;
        else rp=3;
        bool fall=false;

        string s;
        cin>>s;
        rep(i,s.length(),0)
        {
            if(s[i]=='L')rp=(rp+1)%4;
            else if(s[i]=='R')rp=(rp-1+4)%4;
            else
            {
                if(rp==0)
                {
                    if(ry+1>wy)
                    {
                        if(a[rx][ry])
                        {
                            a[rx][ry]=0;
                            fall=true;
                            break;
                        }
                    }
                    else
                    {
                        ry++;
                    }
                }
                else if(rp==3)
                {
                    if(rx+1>wx)
                    {
                        if(a[rx][ry])
                        {
                            a[rx][ry]=0;
                            fall=true;
                            break;
                        }
                    }
                    else
                    {
                        rx++;
                    }
                }
                else if(rp==2)
                {
                    if(ry-1<0)
                    {
                        if(a[rx][ry])
                        {
                            a[rx][ry]=0;
                            fall=true;
                            break;
                        }
                    }
                    else
                    {
                        ry--;
                    }
                }
                else
                {
                    if(rx-1<0)
                    {
                        if(a[rx][ry])
                        {
                            a[rx][ry]=0;
                            fall=true;
                            break;
                        }
                    }
                    else
                    {
                        rx--;
                    }
                }
            }
            
        }

        cout<<rx<<" "<<ry<<" ";
        if(rp==0)cout<<"N";
        else if(rp==1)cout<<"W";
        else if(rp==2)cout<<"S";
        else cout<<"E";

        if(fall==true)
        cout<<" LOST";
        nl;
    }
}