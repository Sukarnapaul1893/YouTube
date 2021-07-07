#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,m;

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
 
    for(int i=0;i<m;i++){
        char ch;
        int x;

        cin>>ch>>x;
        if(ch=='-')Union(x+1,x);
        else{
            int px = Find(x);
            
            if(px>=n+1)cout<<-1<<"\n";
            else cout<<px<<"\n";
        }
    }
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
    cin>>n>>m;

}
