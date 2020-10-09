class Solution{

	public:
	int minDiffernce(int a[], int n) 
	{ 
	    // Your code goes here
	    int range=0;
	    for(int i=0;i<n;i++)
	        range+=a[i];
	        
	   int w=range/2;
	   bool dp[n+1][w+1];
	   //initialze dp table
	   for(int i=0;i<n+1;i++){
	       for(int j=0;j<w+1;j++){
	           if(i==0) 
	               dp[i][j]=false;
	           if(j==0)
	                dp[i][j]=true;
	       }
	   }
	   
	   // code for choice diagram
	   for(int i=1;i<n+1;i++){
	       for(int j=1;j<w+1;j++){
	           if(a[i-1]<=j)
	              dp[i][j] =  dp[i-1][j]||dp[i-1][j-a[i-1]];
	           else
	              dp[i][j] = dp[i-1][j];
	       }
	   }
	   
	  
	   //check if subset for given sum exists or not
	   int minDiff = range;
	   
	   for(int j=0;j<w+1;j++){
	       if(dp[n][j]==true)
	        if((range-2*j)<minDiff)   
	            minDiff = range-2*j;
	   }
	   
	   return minDiff;
	} 
};
