#include <iostream>

#include <vector>
#include <string>

// Check if a position is under atack
bool UnderAtack(bool board[8][8], int row, int column) {
    // Column
    for (int i=0; i<row; i++) {
        if (board[i][column])   return true;
    }

    // Left diagonal
    int i = row;
    int j = column;
    while (i>=0 && j>=0) {
        if (board[i][j])    return true;
        i--;
        j--;
    }

    
    // Right diagonal
    i = row;
    j = column;
    while (i>=0 && j < 8) {
        if (board[i][j])    return true;
        i--;
        j++;
    }

    return false;
}

// Adjust queens per row, will set only 1 queen per row in any valid case
bool nQueens(int row, bool board[8][8], int scores[8][8], int* sum) {
    if (row == 8)    return true;

    bool flag = false;
    int score = 0;
    for (int i=0; i<8; i++) {
        // Check if the position is valid
        if (!UnderAtack(board, row, i)) {
            int new_score = 0;
            board[row][i] = true;
            
            // If this position blocks the further steps, it shall not be used
            if (nQueens(row+1, board, scores, &new_score)) {
                new_score += scores[row][i];
                flag = true;
                score = std::max(score, new_score);
            }
            
            // Set the board back
            board[row][i] = false;
        }
    }
    *sum = score;

    return flag;
}


int main() {
    int n_boards;
    std::cin >> n_boards;

    bool board[8][8] = {false};
    while (n_boards-- > 0) {
        int sum = 0;
        int scores[8][8];
        for (int i=0; i<64; i++) {
            std::cin >> scores[i/8][i%8];
        }

        nQueens(0, board, scores, &sum);

        // Print formated answer
        std::string answer = std::to_string(sum);
        int dif = 5 - answer.length();
        while (dif-- > 0)   std::cout << " ";
        std::cout << answer << std::endl;
    }

    return 0;
}