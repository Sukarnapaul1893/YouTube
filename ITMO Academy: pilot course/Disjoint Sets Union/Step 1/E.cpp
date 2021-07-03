#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n;
int m;

int ans[200005];

int monkey[200005][3];

map<pair<int,int>,int >edge;

vector<pair<int,int> >deleted_edges;

vector<int>vec[200005];

//Disjoint Set Union
int p[200005]; //initially p[i] = i;
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

    for(int i=1;i<=n;i++)p[i]=i;

    for(auto it=edge.begin(); it!=edge.end();it++){
        if((*it).second == 0)continue;

        int u = (*it).first.first;
        int v = (*it).first.second;

        Union(u,v);
    }

    for(int i=1;i<=n;i++){
        if(Find(i)==Find(1))    ans[i] = -1;

        vec[Find(i)].pb(i);
    }

    int dsz = deleted_edges.size();

    for(int i=dsz-1;i>=0;i--){
        int u = deleted_edges[i].first;
        int v = deleted_edges[i].second;

        u = Find(u);
        v = Find(v);

        if(Find(u)==Find(v))continue;

        if(vec[u].size()<vec[v].size())swap(u,v);

        if(u==Find(1)){
            for(int j=0;j<vec[v].size();j++){
                ans[vec[v][j]] = i;
            }
        }

        if(v==Find(1)){
            for(int j=0;j<vec[u].size();j++){
                ans[vec[u][j]] = i;
            }
        }

        Union(u,v);
        for(int j=0;j<vec[v].size();j++)vec[u].pb(vec[v][j]);
    }

    for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
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
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        monkey[i][1] = l;
        monkey[i][2] = r;

        if(l!=-1)edge[{min(i,l),max(i,l)}]++;
        if(r!=-1)edge[{min(i,r),max(i,r)}]++;
    }

    for(int i=0;i<m;i++){
        int id, h;
        cin>>id>>h;
        int u = id;
        int v = monkey[id][h];

        edge[{min(u,v),max(u,v)}]--;

        deleted_edges.pb({u,v});
    }
}
