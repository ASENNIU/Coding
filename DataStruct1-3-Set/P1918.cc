//
// Created by 13345 on 2023/11/10.
//

#include<map>
#include<iostream>
using namespace std;
map<int,int>ma;
int n,a,q,m;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        ma[a]=i;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>m;
        cout<<ma[m]<<endl;
    }
}