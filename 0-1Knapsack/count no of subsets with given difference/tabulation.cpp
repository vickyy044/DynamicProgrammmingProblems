#include <iostream>
using namespace std;

int main() {
	int n,diff;
	cin>>n>>diff;
	int a[n],sumOfArray=0;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    sumOfArray+=a[i];
	}
	int w = (diff+sumOfArray)/2;
	
	//create DP table
	int dp[n+1][w+1];
	//initialize
	for(int i=0;i<n+1;i++){
	    for(int j=0;j<w+1;j++){
	        if(i==0)
	            dp[i][j]=0;
	        if(j==0)
	            dp[i][j]=1;
	    }
	}
	
	//code for choice diagram
	for(int i=1;i<n+1;i++){
	    for(int j=1;j<w+1;j++){
	        if(a[i-1]<=j){
	            dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
	        }else
	            dp[i][j] = dp[i-1][j]; 
	    }
	}
	
	cout<<"No of subsets with differnce="<<diff<<"   is equal to "<<dp[n][w]<<"\n";
	return 0;
}
