#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,m;
int p[100005]; //initially p[i] = i;
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
    for(int i=0;i<=n;i++)p[i]=i;
    for(int i=0;i<m;i++){
        string s;
        int u , v;
        cin>>s>>u>>v;
        if(s=="union")Union(u,v);
        else {
            if(Find(u)==Find(v)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
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
