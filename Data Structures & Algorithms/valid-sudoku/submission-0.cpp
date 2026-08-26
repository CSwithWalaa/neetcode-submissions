class Solution {
public:
// O(n²) time/space

// duplicate detection → sets 
// One cell belongs to 3 groups (row, column, box) → check all 3 simultaneously

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.')
                    continue; 

                int box = (r / 3) * 3 + (c / 3);

                // check (row, column, box) if duplicate → false
                if(rows[r].contains(board[r][c]) || 
                   cols[c].contains(board[r][c]) || 
                   boxes[box].contains(board[r][c]))
                    return false; 
                
                // otherwise → insert to the three of them
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                boxes[box].insert(board[r][c]);
            }
        }
        return true;
    }
};
