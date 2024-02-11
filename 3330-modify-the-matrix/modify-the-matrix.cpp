class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for(int col = 0;col < matrix[0].size();col++){
            int maxx = -1;
            for(int row = 0;row < matrix.size();row++){
                if(matrix[row][col] == -1 && maxx == -1){
                    for(int row1 = 0;row1 < matrix.size();row1++){
                        maxx = max(maxx,matrix[row1][col]);
                    }
                
                }if(matrix[row][col] == -1 && maxx != -1){
                    matrix[row][col] = maxx;
                }
            }
        }
        return matrix;
        
    }
};