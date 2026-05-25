class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                char digit = board[r][c];

                if(digit == '.') continue;

                if(rows[r].count(digit)) return false;
                rows[r].insert(digit);

                if(cols[c].count(digit)) return false;
                cols[c].insert(digit);

                int boxIdx = (r/3)*3+(c/3);
                if(boxes[boxIdx].count(digit)) return false;
                boxes[boxIdx].insert(digit);
            }
        }
        return true;
    }
};
