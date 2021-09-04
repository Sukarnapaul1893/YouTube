#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

string s;
char Max[100005];
int idx[100005];

void input();

void solve(){

    int n = s.size();

    Max[n-1] = s[n-1];
    idx[n-1] = n-1;

    for(int i=n-2;i>=0;i--){
        Max[i] = max(s[i],Max[i+1]);
        if(s[i]!=Max[i])idx[i] = idx[i+1];
        else                idx[i] = i;
    }

    int i=0;
    string ans = "";

    while(i<=n-1){

        ans += Max[i];

        i = idx[i]+1;
    }

    cout<<ans<<"\n";
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
    cin>>s;
}
