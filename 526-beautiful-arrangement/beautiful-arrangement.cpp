class Solution {
public:
    int ways(int index,map<int,int> visited,int n){
        if(index <= 0)return 1;
        int ans = 0;

        for(int i = n;i >= 1;i--){
            if(!visited[i]){
                if(i%index == 0 || index%i == 0){
                    visited[i]++;
                    ans += ways(index - 1,visited,n);
                    visited[i]--;
                }
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        map<int,int> visited;
        return ways(n,visited,n);
        
    }
};