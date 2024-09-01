class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> hardik;

        
        int i = 0;
        if(m*n == original.size()){
            for(int rows = 0;rows < m;rows++){
            vector<int> nums;
            for(int col = 0; col < n;col++){
                nums.push_back(original[i]);
                i++;
            }hardik.push_back(nums);
        }return hardik;
        }else{
            return {};
        }
        
    }
};