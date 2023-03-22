#include<iostream>
using namespace std;
const int n=8;//棋盘大小
int ans=0;//记录可行解的数量
int vis[n][n];//标记是否已经遍历过
int dx[]={-2,-2,-1,-1,1,1,2,2};//骑士的行走方向
int dy[]={-1,1,-2,2,-2,2,-1,1};//骑士的行走方向
void dfs(int x,int y,int step){//x，y表示当前位置，step表示已经走了几步
    if(step==n*n){//找到一组可行解
        ans++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<8;i++){//枚举8个方向
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n||vis[nx][ny]){//越界或者已经遍历过
            continue;
        }
        vis[nx][ny]=step+1;//标记为已遍历
        dfs(nx,ny,step+1);//递归搜索下一步
        vis[nx][ny]=0;//回溯
    }
}
int main(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;//初始化为未遍历
        }
    }
    vis[3][3]=1;//从(0,0)出发
    dfs(3,3,0);
    cout<<"可行解的数量为："<<ans<<endl;
    return 0;
}
