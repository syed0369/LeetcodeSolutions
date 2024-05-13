/********************************************
Solution to LeetCode Daily Question 05-13-2024. 

Problem:
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

Solution:
The most significant bit has to be set to obtain the maximum sum. If the bit is 1 we leave the row unchanged if it is 0, we flip the bits in the row. Now we look at the columns, if the number of ones is less than the number of zeroes, we should also keep account of whether particular row in which the bit is present was flipped or not. This can be checked form the table:
First Element| Current Element| Current Element after flip
     0	   |        0	     |      1
     0	   |        1	     |      0
     1       |        0	     |      0
     1	   |        1	     |      1
If the first row element is 0, flip the curr element else donot flip. 
We can count the number of ones in the particular column after which we can choose to flip the bits if count of ones is less than the count of zeroes. The decimal form of the number is then adder to score. The decimal form is  1  << n - j - 1. Where i,j is the index of the bit in the matrix and n is the number of columns. 

Complexity:
Time complexity: O(m * n)
Space complexity: O(1)
********************************************/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int count;
        int m = grid.size();
        int n = grid[0].size();
        int score = (1 << (n - 1)) * m;
        for (int j = 1; j < n; j++) {
            count = 0;
            for (int i = 0; i < m; i++) 
                count += grid[i][j] == grid[i][0];
            score += max(count, m - count) * (1 << (n - j - 1));
        }
        return score;
    }
};
