class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>>& visited(m,vector<int>(n,0));

        vector<pair<int,int>> rotten;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                // if(grid[i][j] == 0)visited[i][j] = -1;
                if(grid[i][j] == 2)rotten.push_back(make_pair(i,j));
            }
        }

        

        int j = 0;

        int minutes = 0;
        while(j  != rotten.size()){
            int size = rotten.size();
            for(int i = j;i < size;i++){
                int row = rotten[i].first;
                int col = rotten[i].second;

                if(row - 1 >= 0 && grid[row - 1][col] == 1){
                    grid[row - 1][col] = 2;
                    rotten.push_back(make_pair(row - 1,col));
                }

                if(row + 1 < m && grid[row + 1][col] == 1){
                    grid[row + 1][col] = 2;
                    rotten.push_back(make_pair(row + 1,col));
                }

                if(col - 1 >= 0 && grid[row][col - 1] == 1){
                    grid[row][col - 1] = 2;
                    rotten.push_back(make_pair(row,col - 1));
                }

                if(col + 1 < n && grid[row][col + 1] == 1){
                    grid[row][col + 1] = 2;
                    rotten.push_back(make_pair(row,col + 1));
                }
            }
            minutes++;
            j = size;
        }

        for(auto c: grid){
            for(auto p: c){
                if(p == 1)return -1;
            }
        }

        if(minutes == 0)return 0;
        return minutes - 1;
        
    }
};