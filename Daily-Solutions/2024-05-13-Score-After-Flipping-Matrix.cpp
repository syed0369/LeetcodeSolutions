/********************************************
Solution to LeetCode Daily Question 05-13-2024. 

Problem:
You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

Solution:
Sine we have to select the maximum happiness in each iteration, priority queue pq can be used. In C++ it is implemented using heap. First inserting the elements of happiness into the pq named q. For selecting the maximum happiness in each iteration we can just pop out the element from the pq. Since for each turn the happiness of the children decreases by 1, maintain a counter which increases after each element is selected.

Complexity:
Time complexity: O(nlogn + klogn) Any operation takes logn time. For creating the pq, n insertions required O(nlongn) for accessing the maximum element it takes O(1), deleting it takes longn time, k deletions take O(klogn). Hence total time complexity O(nlogn + klogn)
Space complexity: O(n)
where n is number of children
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
