class Solution {
public:
    bool binary_search(int start,int end,vector<int>& nums,int target){
        int mid = start + (end - start)/2;

        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }
            else if(nums[mid] == target)return true;

            else {
                end = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int pivot = -1;
        for(int i = 0;i < size - 1;i++){
            if(nums[i] > nums[i + 1]){
                pivot = i;
                break;
            }
        }
        cout<<pivot<<endl;
        if(pivot == -1)return binary_search(0,nums.size() - 1,nums,target);
        // if(pivot == 0)return binary_search(nums.size() - 1)

        return binary_search(0,pivot,nums,target)||binary_search(pivot + 1,nums.size() - 1,nums,target);

        
    }
};