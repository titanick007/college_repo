#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
    if(a>=b)return a;
    else return b;
}
struct obj{
    int w;
    int p;
};
struct obj tab[100][100];
int ks(int n,int maxw){
    if(n==0||maxw==0)return 0;
    else if(tab[n][maxw].w>maxw)return ks(n-1,maxw);
    return max(ks(n-1,maxw-tab[n][maxw]))
}
int main(){
    
    return 0;
}