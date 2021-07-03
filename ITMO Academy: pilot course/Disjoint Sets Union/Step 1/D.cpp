#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,m,k;

vector<pair<string , pair<int,int> > >q;

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

vector<string>ans;

void solve(){
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=k-1;i>=0;i--){
        auto it = q[i];
        string s = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(s=="cut")Union(u,v);
        else{
            if(Find(u)==Find(v)){
                ans.pb("YES");
            }
            else{
                ans.pb("NO");
            }
        }
    }

    int sz = ans.size();
    for(int i=sz-1;i>=0;i--){
        cout<<ans[i]<<"\n";
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
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
    }

    for(int i=0;i<k;i++){
        int u,v;
        string s;
        cin>>s;
        cin>>u>>v;
        q.pb({s,{u,v}});
    }
}
