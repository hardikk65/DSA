class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int ans[arr.size()];
        int min = INT_MAX;
        int max = -1;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] > max){
                max = arr[i];
            }
            if(arr[i] < min){
                min = arr[i];
            }
        }

        int mid = min + (max - min)/2;
        int count = 0;
        int answer = -1;

        while(min <= max){
            mid = min + (max - min)/2;
            count = 0;
            int counter = 0;
            for(int j = 0;j<arr.size();j++){
                if(arr[j] <= mid){
                    ans[j] = 1;
                }
                else if (arr[j] > mid){
                    ans[j] = 0;
                }
            }
            for(int p = 0;p<arr.size();p++){
                if(ans[p] == 0){
                    count = 0;
                }
                else if(ans[p] == 1){
                    count++;
                }
                if(count == k){
                    counter++;
                    count = 0;
                }
            }
            if(counter >= m){
                max = mid - 1;
                answer = mid;
            }
            else{
                min = mid + 1;
            }
        }
        return answer;
        
    }
        
};