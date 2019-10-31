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


struct kry
{
    char text[105];
};

bool comp(kry a, kry b)
{
    return strlen(a.text)<strlen(b.text);
}

int main()
{
       int n;
       fastio;
       cin>>n;
       
       vector <kry> a(n);
       
       rep(i,n,0)
       {
         cin>>a[i].text;
       }

       sort(a.begin(),a.end(),comp);

       int f=1;

       for(int i=0;i<n-1;i++)
       {

         //  cout<<"comparing "<<a[i].text<<":"<<a[i+1].text<<endl;

           if(strlen(a[i].text)==strlen(a[i+1].text))
           {
               if(strcmp(a[i].text,a[i+1].text)==0)
               {

               }
               else
               {
                   f=0;
                   break;
               }
           }
           else
           {
               int l=strlen(a[i].text);
               int l2=strlen(a[i+1].text);
               int z=0;
               for(int j=0;j<=l2-l;j++)
               {
                   char r[l+1];
                   rep(o,l,0)
                   r[o]=a[i+1].text[o+j];
                   r[l]='\0';

                 //  cout<<"checking if substring "<<r<<" is present\n";

                   if(strcmp(a[i].text,r)==0)
                   {
                       z=1;
                   }
               }

               if(z==0)
               {
                   f=0;
                   break;
               }
           }
       }

       if(f)
       {
           cout<<"YES"<<endl;
           rep(i,n,0)
           cout<<a[i].text<<endl;
       }
       else
       cout<<"NO"<<endl;

       
}