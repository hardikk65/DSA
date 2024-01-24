class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        int count = 0;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(board[i][j] == 'X'){
                    if(i == 0 && j == 0){
                        count++;
                    }
                    else if(i == 0){
                        if(board[i][j - 1] != 'X'){
                            count++;
                        }
                    }
                    else if(j == 0){
                        if(board[i - 1][j] != 'X'){
                            count++;
                        }
                    }
                    else{
                        if(board[i][j - 1] != 'X' && board[i - 1][j] != 'X'){
                            count++;
                        }

                    }
                }
            }
        }

        return count;
        
    }
};