class Solution {
public:
    int binary_search(vector<int>& arr,int k){
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end - start)/2;

        while(start <= end){
            
            if(arr[mid] == k){
                return mid;
            }
            else if (arr[mid] < k){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
            
        }
        return -1;
    }
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans;

        for(int i = 1;i < arr[0];i++){
            ans.push_back(i);
        }

        for(int j = arr[0] + 1;j < arr[arr.size() -1 ];j++){
            int num = binary_search(arr,j);
            if(num == -1){
                ans.push_back(j);
            }
        }
        
        for(int p = 0;p < ans.size();p++){
            cout<<ans[p]<<" ";
        }
        if(k > ans.size()){
            return arr[arr.size() - 1] + k - ans.size();
        }
        return ans[k - 1];

    }
};