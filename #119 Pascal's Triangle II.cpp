class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> arr(rowIndex+1);

        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=0;j<=i;j++)
            {
                arr[i].resize(i + 1);
                if(j==0||j==i){
                    arr[i][j]=1;
                }
                else{
                    arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
                }
            }
        }
        return arr[rowIndex];
    }
};
