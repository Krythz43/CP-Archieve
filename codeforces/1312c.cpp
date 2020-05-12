#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
lli arr[900000];
lli fc = 0;
set <lli> st;
bool decomp(lli n,lli k)
{
    while(n > 0)
    {
        if(n%k == 0 || n%k == 1)
            n/=k;
        else
            return false;
    }
    return true;
}
bool decomp2(lli n, lli k)
{
    lli counter = 0;
    while(n > 0)
    {
        if(n%k == 1)
        {
            st.insert(counter);
            fc++;
        }
        counter++;
        n/=k;
    }
    return true;
}
int main()
{
    lli t;
    cin>>t;
    bool check = true;
    while(t--)
    {
        lli n,k;
        st.clear();
        fc = 0;
        check = true;
        cin>>n>>k;
        for(lli i = 0; i<n; i++)
        {
            cin>>arr[i];
        }

        for(lli i = 0; i<n; i++)
        {
            if(arr[i] == 0)
                continue;
            if(decomp(arr[i],k) == false)
            {
                cout<<"NO"<<endl;
                check = false;
                break;
            }
        }
        if(!check)
            continue;
        for(lli i = 0; i<n; i++)
        {
            if(arr[i] == 0)
                continue;
            decomp2(arr[i],k);
        }
        if(st.size() != fc)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
 
}