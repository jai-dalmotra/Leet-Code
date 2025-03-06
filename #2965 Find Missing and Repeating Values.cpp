class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int repeat,miss;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int curr=abs(grid[i][j]);
                int row=(curr-1)/n;
                int col=(curr-1)%n;

                if(grid[row][col]<0)
                {
                    repeat=abs(curr);
                    continue;
                }
                grid[row][col]*=-1;
            }
        }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]>0){
                        miss=i*n+j+1;
                        break;
                    }
                }
            }
            return {repeat,miss};
         
    }
};
