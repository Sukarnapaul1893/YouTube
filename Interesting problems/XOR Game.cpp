//Video tutorial link: https://youtu.be/y2ERMJFsyjg

#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int a,b;

void input();

void solve(){

    for(int i=0;i<30;i++){
        if( ((1<<i)&a) and ((1<<i)&b) ){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>a>>b;
}
