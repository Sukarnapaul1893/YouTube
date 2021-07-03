#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,m;

void input();

int p[200005];
int sz[200005];
int extra[200005];
int score[200005];

int Find(int x)
{
    if(p[x] == x) return x;
    else          return Find(p[x]);
}
void Union(int a, int b)
{
    int pa = Find (a);
    int pb = Find (b);

    if(pa==pb)return;

    if(sz[pa]<sz[pb])swap(pa,pb);

    p[pb] = pa;
    sz[pa]+=sz[pb];

    extra[pb] = score[pa];

}

void update_score(int x, int s){
    x = Find (x);
    score[x]+=s;
}

int find_score(int x){
    if(x==p[x])return score[x];
    else    return (score[x] - extra[x]) + find_score(p[x]);
}

void solve(){
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        if(s=="join"){
            int u,v;
            cin>>u>>v;
            Union(u,v);
        }
        else if(s=="add"){
            int x,v;
            cin>>x>>v;
            update_score(x,v);
        }
        else{
            int x;
            cin>>x;
            cout<<find_score(x)<<"\n";
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
