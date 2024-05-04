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
