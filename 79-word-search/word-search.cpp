class Solution {
public:
    void answer(vector<vector<char>>& board, string& temp, string& word, int i,
                int j, int k) {
        temp += board[i][j];
        if (temp == word)
            return;

        if (word[k] == board[i][j]) {
            board[i][j] = '.';
            if (j - 1 >= 0)
                answer(board, temp, word, i, j - 1, k + 1);
            if (i - 1 >= 0)
                answer(board, temp, word, i - 1, j, k + 1);
            if (j + 1 < board[0].size())
                answer(board, temp, word, i, j + 1, k + 1);
            if (i + 1 < board.size())
                answer(board, temp, word, i + 1, j, k + 1);
            if (temp == word)
                return;
            board[i][j] = word[k];
        }

        temp.pop_back();
        if (k != 0 && (board[i][j] != word[k] || board[i][j] == word[k]))
            return;

        if (j < board[0].size() - 1) {
            answer(board, temp, word, i, j + 1, k);
        }
        if (j == (board[0].size() - 1) && i != board.size() - 1) {
            answer(board, temp, word, i + 1, 0, k);
        }

        return;
    }
    bool exist(vector<vector<char>>& board, string word) {

        map<char, int> board_map;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board_map[board[i][j]]++;
            }
        }

        for (auto i : word) {
            if (board_map[i] == 0) {
                return false;
            }
        }

        string temp = "";
        answer(board, temp, word, 0, 0, 0);
        if (temp == word) {
            return true;
        }

        return false;
    }
};