#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
      long long maxSum = 0;
      long long currSum=0;
      for (int i = 0; i < n; i++) 
      {
          currSum += arr[i];
          if(currSum > maxSum)
          {
              maxSum = currSum;
          }
          if(currSum<0)
          {
              currSum=0;
          }

       }
      return maxSum;
}