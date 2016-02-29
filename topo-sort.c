#include<stdio.h>
#include<memory.h>

inline int readInt() {
    int val = 0, ch;
    while(((unsigned)(ch = getchar() - '0')) > 9)
        ;
    val = ch;
    while(((unsigned)(ch = getchar() - '0')) <= 9)
        val = (val << 3) + (val << 1) + ch;
    return val;
}

#define N 100001
#define M 500001
int hd[N];
int va[M];
int nx[M];
int cnt = 1;
int n,m;
void addEdge(int u,int v){
    va[cnt] = v;
    nx[cnt] = hd[u];
    hd[u] = cnt++;
}
char vis[N];
bool DFS(int start){
    vis[start] = -1;
    for(int i = hd[start];i ; i = nx[i]){
        if(vis[va[i]] == -1){
            return false;
        }else if(vis[va[i]] == 0){
            if(!DFS(va[i])){
                return false;
            }
        }
    }
    vis[start] = 1;
    return true;
}
int main(){
    int T;
    int u,v;
    T = readInt();
    while(T--){
        n = readInt();
        m = readInt();
        memset(hd,0,sizeof(int)*(n+1));
        memset(vis,0,sizeof(char)*(n+1));
        cnt = 1;
        for(int i = 0; i < m;i++){
            u = readInt();
            v = readInt();
            addEdge(u,v);
        }
        bool flag = true;
        for(int i = 1; i <= n;i++){
            if(vis[i] == 0 && !DFS(i)){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("Correct\n");
        }else{
            printf("Wrong\n");
        }
    }
}