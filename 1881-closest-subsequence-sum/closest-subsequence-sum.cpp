class Solution {
public:
    void subsetsum(int start, int end,int sum,vector<int>& nums,vector<int>& d1){
        if(start == end){
            d1.push_back(sum);
            return;
        }
        subsetsum(start + 1,end,sum + nums[start],nums,d1);
        subsetsum(start + 1,end,sum,nums,d1);
        return;
    }
    void subsetsum1(int start, int end,int sum,vector<int>& nums,vector<int>& d2){
        if(start == end){
            d2.push_back(sum);
            return;
        }
        subsetsum1(start + 1,end,sum + nums[start],nums,d2);
        subsetsum1(start + 1,end,sum,nums,d2);
        return;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int size = nums.size();
        if(size%2 != 0)nums.push_back(0);     
        size = nums.size();
        vector<int> d1,d2;
        subsetsum(0,size/2,0,nums,d1);
        subsetsum1(size/2,size,0,nums,d2);

        sort(d1.begin(),d1.end());
        sort(d2.begin(),d2.end());
        // for(a)
        int low = 0;
        int high = d2.size() - 1;

        int maxs = INT_MAX;

        while(low < d1.size() && high >= 0){

            int sum = d1[low] + d2[high];
            maxs = min(maxs,abs(sum - goal));
            if(sum < goal){
                low++;
            }
            else if(sum > goal)high--;

            else{
                return 0;
            }

        }

        
        return  maxs;
    }
};