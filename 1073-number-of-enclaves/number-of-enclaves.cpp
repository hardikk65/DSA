class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        if(row < 3 && col < 3)return 0;

        queue<pair<int,int>> q;

        for(int i = 0;i < col;i++){
            if(grid[0][i] == 1)q.push({0,i});
        }
        for(int i = 1;i < row;i++){
            if(grid[i][0] == 1)q.push({i,0});
        }
        for(int i = 1;i < row;i++){
            if(grid[i][col - 1] == 1)q.push({i,col - 1});
        }
        for(int i = 1;i < col - 1;i++){
            if(grid[row - 1][i] == 1)q.push({row - 1,i});
        }


        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){

            int row1 = q.front().first;
            int col1 = q.front().second;

            cout<<row1<<col1<<endl;
            q.pop();

            if(grid[row1][col1] != 0){
                grid[row1][col1] = 0;
                for(int i = 0;i < 4;i++){
                    int temprow = row1 + delrow[i];
                    int tempcol = col1 + delcol[i];
                    if((temprow >= 0 && temprow < row) && (tempcol >= 0 && tempcol < col) && (grid[temprow][tempcol] == 1)){
                        q.push({temprow,tempcol});
                    }
                }
            }

        }

        int ans = 0;

        for(auto c:grid){
            for(auto p:c){
                if(p == 1)ans++;
            }
        }
        return ans;
        
    }
};