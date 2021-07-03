#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,q;
map<int,int>Min,Max,Sum;
void input();


int p[300005]; //initially p[i] = i;
int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b)
{
    int Fa = Find(a);
    int Fb = Find(b);
    p[Fb] = Fa; // Making the parent of a and b same
     
}

void updateSum(int a, int b){
    int Fa = Find(a);
    int Fb = Find(b);
    int total = Sum[Fa] + Sum[Fb];
    
    Sum[Fa] = total;
    Sum[Fb] = total;
}

void updateMin(int a, int b){
    int Fa = Find(a);
    int Fb = Find(b);
     
    int mnFa = Min[Fa];
    int mnFb = Min[Fb];
    
    Min[Fa] = min({mnFa,mnFb});
    Min[Fb] = min({mnFa,mnFb});
}

void updateMax(int a, int b){
    int Fa = Find(a);
    int Fb = Find(b);
    
    int mFa = Max[Fa];
    int mFb = Max[Fb];

    Max[Fa] = max({mFa,mFb});
    Max[Fb] = max({mFa,mFb});
}

void Get(int v){
    cout<<Min[Find(v)]<<" "<<Max[Find(v)]<<" "<<Sum[Find(v)]<<"\n";
}

void solve(){
    for(int i=1;i<=n;i++){
        p[i]=i;
        Max[i] = i;
        Min[i] = i;
        Sum[i] = 1;
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s=="union"){
            int u,v;

            cin>>u>>v;
            if(Find(u)!=Find(v)){
                updateMin(u,v);
                updateMax(u,v);
                updateSum(u,v);
            }
            Union(u,v);
        }
        else{
            int v;
            cin>>v;
            Get(v);
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
    cin>>n>>q;
}
