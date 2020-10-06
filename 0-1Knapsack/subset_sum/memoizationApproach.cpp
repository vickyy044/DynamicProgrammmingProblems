#include <bits/stdc++.h>
using namespace std;
int static dp[100][100];            //Dp table , made up of max constraints
int subset_sum(int a[],int sum,int n){
    if(sum==0)
        return 1;                   // true-1
    if(n==0)
        return 0;                   // false-0
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    
    if(a[n-1]<=sum){
        int sol1= subset_sum(a,sum-a[n-1],n-1);
        int sol2=subset_sum(a,sum,n-1);
        if(sol1==1 || sol2==1)
            return dp[n][sum]=1;
        else return dp[n][sum]=0;
    }else
        return dp[n][sum] = subset_sum(a,sum,n-1);
}

int main() {
    // 	cout<<"GfG!";
    memset(dp,-1,sizeof(dp));
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(subset_sum(a,sum,n)==1)
         cout<<"yes subset is present"<<"\n";
	return 0;
}
