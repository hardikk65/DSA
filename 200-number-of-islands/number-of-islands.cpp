class Solution {
public:

    void bfs(vector<vector<char>>& grid,char color,queue<pair<int,int>>& q,int delrow[],int delcol[]){

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            if(grid[row][col] == '1'){
                grid[row][col] = color;
                for(int i = 0;i < 4;i++){
                    int row1 = row + delrow[i];
                    int col1 = col + delcol[i];
                    if((row1 >= 0 && row1 < grid.size()) && (col1 >= 0 && col1 < grid[0].size()) && (grid[row1][col1] == '1')){
                        q.push({row1,col1});
                    }
                }
            }

        }
        return;


        
    }
    int numIslands(vector<vector<char>>& grid) {
        int color = 1;
        queue<pair<int,int>> q;

        int row = grid.size();
        int col = grid[0].size();

        int delrow[] = {-1,0,0,1};
        int delcol[] = {0,1,-1,0};

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == '1'){
                    q.push({i,j});
                    color = color + 1;
                    bfs(grid,'3',q,delrow,delcol);
                    
                }
            }
        }

    
        return color - 1;
        
    }
};