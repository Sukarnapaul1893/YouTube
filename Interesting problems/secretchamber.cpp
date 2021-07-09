#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int m,n;
bool vis[26];
vector<int>adj[26];
void input();

void dfs(int s){
    vis[s] = true;

    for(int i=0;i<adj[s].size();i++){
        int u =  adj[s][i];
        if(vis[u]==true)continue;
        dfs(u);
    }
}

bool Check(int i,  int j){
    memset(vis,false,sizeof vis);
    dfs(i);
    if(vis[j]==true)return true;
    else return false;
}

void solve(){
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(a.size()!=b.size()){
            cout<<"no\n";
            continue;
        }
        bool bl=true;
        for(int j=0;j<a.size();j++){
            int ch1 = a[j]-'a';
            int ch2 = b[j]-'a';
            if(Check(ch2, ch1))continue;
            else bl=false;
        }
        if(bl)cout<<"yes\n";
        else cout<<"no\n";
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
    cin>>m>>n;

    for(int i=0;i<m;i++){
        char a,b;
        cin>>a>>b;
        int v = a-'a';
        int u = b-'a';
        adj[u].pb(v);
    }
}
