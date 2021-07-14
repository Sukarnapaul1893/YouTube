//Video explanation: https://youtu.be/9HsJInMb9Fg
#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n;

int p[1000006]; //initially p[i] = i;
int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
    p[Find(b)] = Find(a); // Making the parent of a and b same
}

void input();

void solve(){
    for(int i=1;i<=n+3;i++)p[i]=i;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        int px = Find(x);

        cout<<px;
        if(i<n-1)cout<<" ";

        if(px<n)Union(px+1,px);
        else    Union(1,px);
    }

    cout<<"\n";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
    Clear();
}

void input(){
    cin>>n;

}
