class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int answer[nums.size()*2];
        stack<int> st;
        for(int i = 0;i < nums.size()*2;i++){
            answer[i] = nums[i%nums.size()];
        }

        for(int i = nums.size()*2 - 1;i >= 0;i--){
            while((!st.empty()) && (st.top() <= answer[i])){
                st.pop();
            }
            if(st.empty())nums[i%nums.size()] = -1;
            else{
                nums[i%nums.size()] = st.top();
            }
            st.push(answer[i]);
        }

        return nums;



        
    }
};