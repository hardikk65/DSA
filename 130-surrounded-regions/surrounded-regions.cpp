class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();
        if(row < 3 && col < 3)return;
        vector<vector<char>> vis(row,vector<char>(col,'X'));
        queue<pair<int,int>> q;

        for(int i = 0;i < col;i++){
            if(board[0][i] == 'O')q.push({0,i});
        }
        for(int i = 1;i < row;i++){
            if(board[i][0] == 'O')q.push({i,0});
        }
        for(int i = 1;i < row;i++){
            if(board[i][col - 1] == 'O')q.push({i,col - 1});
        }
        for(int i = 1;i < col - 1;i++){
            if(board[row - 1][i] == 'O')q.push({row - 1,i});
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){

            int row1 = q.front().first;
            int col1 = q.front().second;

            q.pop();

            if(vis[row1][col1] != 'O'){
                vis[row1][col1] = 'O';
                for(int i = 0;i < 4;i++){
                    int temprow = row1 + delrow[i];
                    int tempcol = col1 + delcol[i];
                    if((temprow >= 0 && temprow < row) && (tempcol >= 0 && tempcol < col) && (board[temprow][tempcol] == 'O') && (vis[temprow][tempcol] != 'O')){
                        q.push({temprow,tempcol});
                    }
                }
            }

        }

        board = vis;

        

        return;



        
    }
};