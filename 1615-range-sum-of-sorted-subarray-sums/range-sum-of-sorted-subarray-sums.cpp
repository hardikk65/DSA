class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int> sum;

        for(int i = 0;i < nums.size();i++){
            int temp = 0;
            for(int j = i;j < nums.size();j++){
                temp += nums[j];
                sum.push_back(temp);
            }
        }

        sort(sum.begin(),sum.end());

        int answer = 0;

        int modi = pow(10,9) + 7;
        for(int i = left - 1;i < right;i++){
            answer += sum[i];
            answer = answer%modi;
        }
        return answer;
    }
};