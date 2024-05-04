/********************************************
Solution to LeetCode Daily Question 05-04-2024. 

Problem:
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.

Solution:
Each boat can accomodate atmost 2 people of weight atmost limit. So to use the least number of boats the intuition should be in each boat try to accomodate the 2 people with combined weight just under limit. This can be done by making the people with the maximum and minimum weight sit in same boat or if the combined weight is more than the maximum limit, only the maximum weight person sits. The next maximum is compared with the minimum and procedure is repeated. For this the array is sorted and two pointers i and j are maintained to point to the next maximum and next minimum. If the sum of the weights is less than or equal to limit place them both in the same boat (increment count of boats). Else just place the maximum weight in the boat.

Complexity:
Time complexity: O(N) where N is number of people
Space complexity: O(1)

********************************************/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i, j;
        int count;
        sort(people.begin(), people.end(), greater<int>());
        i = 0;
        j = people.size() - 1;
        count = 0;
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                count++;
                i++;
                j--;
            }
            else {
                count++;
                i++;
            }
        }
        return count;
    }
};
