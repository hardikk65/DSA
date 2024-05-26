class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1)return matrix[0][0];
        vector<int> front(n,0), curr(n,0);
        for(int i = 0;i < n;i++)front[i] = matrix[n - 1][i];

        int answer;
        for(int i = n - 2;i >= 0;i--){
            int a=INT_MAX,b = INT_MAX,c= INT_MAX,mini = INT_MAX;
            for(int j = 0;j < n;j++){
                if(j - 1 >= 0)a = matrix[i][j] + front[j - 1];
                if(j + 1 < n)b = matrix[i][j] + front[j + 1];
                c = matrix[i][j] + front[j];
                curr[j] = min(a,min(b,c));
                mini = min(mini,curr[j]);
            }
            answer = mini;
            front = curr;
        }

        for(auto c: curr)cout<<c<<endl;

        return answer;

        
    }
};