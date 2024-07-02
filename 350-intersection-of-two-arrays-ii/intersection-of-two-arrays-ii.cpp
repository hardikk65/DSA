class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> arr1;
        map<int,int> arr2;

        vector<int> answer;

        for(auto i:nums1)arr1[i]++;
        for(auto i:nums2)arr2[i]++;

        for(auto c:arr1){
            if(arr2[c.first] != 0){
                for(int i = 0;i < min(arr1[c.first],arr2[c.first]);i++)answer.push_back(c.first);
            }
        }
        return answer;
        
    }
};