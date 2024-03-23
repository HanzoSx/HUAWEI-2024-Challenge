#include<bits/stdc++.h>
using namespace std;

int tick,tmp,n,f[15010][11];
string s;
char ch;
int main()
{
    freopen("test.rpy","r",stdin);
    for (int i = 1; i <= 210; ++ i)
        getline(cin,s);
    while (cin>>tick>>tmp)
    {
        cin>>n>>ch;
        for (int i = 1;i <= n; ++ i)
            getline(cin,s);
        for (int i = 1;i <= 30; ++ i)
            getline(cin,s);
        for (int i = 1;i <= 10; ++ i)
        {
            cin>>f[tick][i];
        }
        // cout<<tick;
    }
    for (int i=1;i<=10;++i)
        cout<<f[15000][i]<<" ";
    return 0;
}