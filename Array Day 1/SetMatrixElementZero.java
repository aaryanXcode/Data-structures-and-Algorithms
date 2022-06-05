class Solution {
    public void setZeroes(int[][] matrix) {
        int n=matrix.length,m=matrix[0].length;
        
        int []row=new int[n];
        int []column=new int[m];
        int i,j;
        for (i = 0; i < n; i++)
        {
            row[i] = 1;
        }
        for (i = 0; i < m; i++)
        {
            column[i] = 1;
        }    
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                  if (matrix[i][j] == 0) 
                  {
                       row[i] = 0;
                       column[j] = 0;
                  }
             }
        }
         for (i=0; i<n; i++)
         {
              for (j=0; j<m; j++) 
              {
                    if (row[i] == 0 || column[j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
               }       
        
         }
        
    }
}