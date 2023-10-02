#include<iostream>
using namespace std;
int c[10000][2],d=0,x[9]={0,1,0,1,-1,0,-1,1,-1};
int                 y[9]={0,0,1,1,0,-1,-1,-1,1};
char a[103][103],b,k[9]=" yizhong";
bool s[102][102];
bool f(int i,int j,int m,int n,int next){
    if(next>=8){
        s[i][j]=1;
        return 1;
    }
    if(a[i+m][j+n]==k[next])
        if(f(i+m,j+n,m,n,next+1)){
            s[i][j]=1;
            return 1;
        }
    return 0;
}
int main(){
    int n,i,j,o;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>b;
            if(b=='y'){
                c[++d][0]=i;
                c[d][1]=j;
            }
            a[i][j]=b;
        }
    }
    while(d){
        i=c[d][0];
        j=c[d][1];
        for(o=1;o<=8;o++){
            if(a[i+x[o]][j+y[o]]=='i')
                if(f(i+x[o],j+y[o],x[o],y[o],3))
                    s[i][j]=1;
        }
        d--;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(s[i][j])cout<<a[i][j];
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}