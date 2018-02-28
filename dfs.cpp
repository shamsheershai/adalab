#include<iostream>
using namespace std; 
int a[20][20],reach[20],n;
void dfs(int v)
{
     int i;
     reach[v]=1;
     for(i=1;i<=n;i++)
         if(a[v][i]&&!reach[i])
           {
            cout<<v<<i;
            dfs(i);
            }
 }
 int main(){
    int i,j,count=0;
    cout<<"\nEnter no of vertices : ";
   cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
        reach[i]=0;
        a[i][j]=0;
        }
        cout<<"\nEnter adjacency matrix : \n";
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        cin>>a[i][j];
    dfs(1);
    for(i=1;i<=n;i++)
       if(reach[i])
         count++;
    if(count==n)
       cout<<"\nGraph is connected.";
    else
       cout<<"\nGraph is disconnected.";
   
    return(0);
}
