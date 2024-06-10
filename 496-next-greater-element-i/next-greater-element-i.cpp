class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        map<int,int> indexer;
        vector<int> result;
        int answer[nums2.size()];
        for(int i = nums2.size() - 1;i >= 0;i--){
            while((!st.empty()) && (st.top() <= nums2[i])){
                st.pop();
            }
            if(st.empty())answer[i] = -1;
            else{
                answer[i] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i = 0;i < nums2.size();i++)indexer[nums2[i]] = i;
        for(auto a: nums1){
            result.push_back(answer[indexer[a]]);
        }
        return result;
        
    }
};