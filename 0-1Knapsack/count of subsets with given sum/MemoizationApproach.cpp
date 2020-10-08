#include <bits/stdc++.h>
using namespace std;
//create dp matrix for max constraints
    int static dp[100][100];
int countSubset(int a[],int target,int n){
    //base condition
    if(target==0)
        return 1;
    if(n==0)
        return 0;
    
    //check if element is already visited in DP table
    if(dp[n][target]!=-1)
        return dp[n][target];
    //code for choice diagram
    if(a[n-1]<=target){
        return dp[n][target] = countSubset(a,target,n-1)+countSubset(a,target-a[n-1],n-1);
    }else
        return dp[n][target] = countSubset(a,target,n-1);
}

int main() {
    //initialize dp matrix
    memset(dp,-1,sizeof(dp));
    
	int n, target;
	cin>>n>>target;
	int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	
	int count = countSubset(a,target,n);
	cout<<"No. of subsets with sum = "<<target<<"  = "<<count<<"\n";
	return 0;
}
