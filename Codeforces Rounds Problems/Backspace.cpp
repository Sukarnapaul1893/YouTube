#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

bool ans ;

string s,t;

void input();

void StartHere(int i){
    int j = t.size()-1;


    for(;i>=0 and j>=0;){
        if(s[i]==t[j]){
            i--;
            j--;
        }
        else{
            i-=2;
        }
    }
    if(j==-1)ans = true;
}

void solve(){
    int tz = t.size();
    int sz = s.size();
    if(sz<tz){
        cout<<"NO\n";
        return;
    }
    ans = false;

    for(int i=sz-1;i>=0;i-=2){
        if(s[i]==t[tz-1]){
            StartHere(i);
            break;
        }
    }

    if(ans) cout<<"YES\n";
    else    cout<<"NO\n";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--){
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>s>>t;
}
