#include <iostream>
using namespace std;

int main() {
// 	cout<<"GfG!";
    int n,target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        
        
        int dp[n+1][target+1];
        //initialization
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        
        //code for choice diagram
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(a[i-1]<=j)
                    dp[i][j]= dp[i-1][j] + dp[i-1][j-a[i-1]];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
    
        cout<<"no of subsets with sum="<<target<<"  = "<<dp[n][target]<<"\n";
	return 0;
}
