class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum = 0;

        for(auto i:operations){
            if(i[0] == '-' || i[i.size() - 1] == '-')sum--;
            else{
                sum++;
            }
        }
        return sum;
    }
};