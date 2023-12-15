//
// Created by 13345 on 2023/12/15.
//

#include<bits/stdc++.h>
using namespace std;
const int maxn = 105, mod = 1000007;
int n, m, f[maxn], sum[maxn], a[maxn];
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    f[0] = 1;
    for(int i=0; i<=m; i++) sum[i] = 1;
    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            int t = j - min(a[i], j) - 1;
            if(t < 0) f[j] = (f[j] + sum[j-1])%mod;
            else f[j] = (f[j] + sum[j-1] - sum[t] + mod)%mod;
        }
        for(int j=1; j<=m; j++) sum[j] = (sum[j-1] + f[j])%mod;
    }
    cout<<f[m]<<endl;
    return 0;
}