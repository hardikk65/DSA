class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> sum(ratings.size(),1);

        for(int i = 0;i < ratings.size() - 1;i++){
            if(ratings[i] < ratings[i + 1]){
                sum[i + 1] = sum[i] + sum[i + 1];
            }
        }

        for(int i = ratings.size() - 1;i > 0;i--){
            if((ratings[i] < ratings[i - 1]) && (sum[i - 1] == 1)){
                sum[i - 1] = sum[i] + sum[i - 1];
            }
            else if((ratings[i] < ratings[i - 1]) && (sum[i - 1] != 1) && (sum[i] >= sum[i - 1])){
                sum[i - 1] = sum[i] + 1;
            }
        }

        int answer = 0;
        for(auto c:sum)cout<<c<<" ";
        for(auto c:sum)answer += c;

        return answer;
        
    }
};