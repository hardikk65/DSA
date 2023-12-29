class Solution {
public:
int ispossible(vector<int>& arr,int mid){

    int sum = 0;
    int jwaak = 0;
    for(int i = 0;i < arr.size();i++){

        sum = sum + arr[i];
        if(sum >= mid){
            jwaak++;

            if(sum == mid){
                sum = 0;
            }
            else{
                sum = arr[i];
            }
        }
    }

    if((sum < mid && sum != 0 )|| (sum == arr[arr.size() - 1])){
        jwaak++;
    }

    if(sum == 0 && arr[arr.size() - 1] == 0){
        jwaak--;
    }

    return jwaak;
    
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n){
        return -1;
    }
    int start = 0;
    int end = 0;

    

    for(int i = 0;i < arr.size();i++){
        end = end + arr[i];

        if(arr[i] > start){
            start = arr[i];
        }
    }
    
    
    int mid = start + (end - start)/2;
    int ans = INT_MIN;

    while(start <= end){
        mid = start + (end - start)/2;
        // cout<<"start "<<start<<" end "<<end<<endl;
        int jwaak = ispossible(arr,mid);
        cout<<jwaak<<endl;
        if(jwaak <= m){
            
            end = mid - 1;
        }
        else if (jwaak > m){
            start = mid + 1;
        }

        cout<<"start "<<start<<" end "<<end<<endl;

    }
    return start;

}
    int splitArray(vector<int>& nums, int k) {
        if(nums.size() == 1 && k == 1){
            return nums[0];
        }
        
        return findPages(nums,nums.size(),k);
        
    }
};