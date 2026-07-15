class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int board_length = 9;
        vector<unordered_set<char>> row_element(board_length);
        vector<unordered_set<char>> col_element(board_length);
        vector<unordered_set<char>> subBox_element(board_length);


        // iterate full sudoku box (need index ids of each iteration to calc subBoxId)
        // subBoxId
        // |0,1,2|
        // |3,4,5|
        // |6,7,8|
        // while iteration -> skip empty element '.'
        // check if board element at (i,j) is present in:
        // row_element set -> i
        // col_element set -> j
        // subBox_element -> ( (i/3) * 3 + (j/3) )
        // if found in the set, duplicate is present, not a valid sudoku.
        // else after full iteration, return as valid sudoku
        for(int i=0; i < board_length; i++){
            for(int j=0; j < board_length; j++){

                if(board[i][j] == '.')
                    continue;

                int value = board[i][j];
                if(row_element[i].find(value) != row_element[i].end())
                    return false;
                
                if(col_element[j].find(value) != col_element[j].end())
                    return false;

                int subBoxId = ( (i/3) * 3 + (j/3) );
                if(subBox_element[subBoxId].find(value) != subBox_element[subBoxId].end())
                    return false;

                row_element[i].insert(value);
                col_element[j].insert(value);
                subBox_element[subBoxId].insert(value);
            }
        }

        return true;
    }
};
