class Solution { // Slightly better solution
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<string> row(9, "");
        vector<string> col(9, "");
        vector<string> box(9, "");

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (row[i].find(board[i][j]) != string::npos) return false;
                else row[i].push_back(board[i][j]);
                if (col[j].find(board[i][j]) != string::npos) return false;
                else col[j].push_back(board[i][j]);
                if (box[((i/3)*3)+(j/3)].find(board[i][j]) != string::npos) return false;
                else (box[((i/3)*3)+(j/3)].push_back(board[i][j]));
            }
        }
        return true;
    }
};

class Solution { // Initial solution
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) { // Rows
            vector<bool> hasNum(10, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                else if (!hasNum[board[i][j]]) hasNum[board[i][j]] = true;
                else return false;
            }
        }
        for (int i = 0; i < 9; i++) { // Columns
            vector<bool> hasNum(10, false);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                else if (!hasNum[board[j][i]]) hasNum[board[j][i]] = true;
                else return false;
            }
        }
        for (int i = 0; i < 9; i++) { // Boxes
            vector<bool> hasNum(10, false);
            for (int j = 0; j < 9; j++) {
                int a = ((i / 3) * 3) + (j / 3);
                int b = ((i % 3) * 3) + (j % 3);
                if (board[a][b] == '.') continue;
                else if (!hasNum[board[a][b]]) hasNum[board[a][b]] = true;
                else return false;
            }
        }
        return true;
    }
};
