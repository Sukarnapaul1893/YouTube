#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n;

vector<int >T;

bool dp[100005][102];
int total;
void input();

void solve(){
    memset(dp,false,sizeof dp);
    dp[0][0] = true;
    for(int j=1;j<=n;j++){
        for(int i=1;i<100005;i++){
            if(dp[i][j-1])dp[i][j]=true;
            else if(i>=T[j-1]){
                if(dp[i-T[j-1]][j-1])dp[i][j]=true;
            }
        }
    }
    int ans = 1e8;
    for(int i=0;i<100005;i++){
        if(dp[i][n])ans = min(max(total-i,i),ans);
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
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        total+=x;
        T.pb(x);
    }
}
