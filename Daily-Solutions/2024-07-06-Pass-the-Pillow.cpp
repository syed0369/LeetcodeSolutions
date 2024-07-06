/********************************************
Solution to LeetCode Daily Question 07-06-2024. 
Problem:
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

Solution:
Simulating the same, at time 0, the pillow is at position 1 with the movement in forward direction +1, first the position changes i.e. pillow is passed then if the pillow is with the last person or fisrt person, the direction of movement of the pillow changes.

Time Complexity:   O(T)
Space Complexity:  O(1)

********************************************/
class Solution {
public:
    int passThePillow(int n, int time) {
        int pos, change;
        pos = 1;
        change = 1;
        while(time--) {
            pos = pos + change;
            if(pos == n || pos == 1)
                change = -change;
        }
        return pos;
    }
};
