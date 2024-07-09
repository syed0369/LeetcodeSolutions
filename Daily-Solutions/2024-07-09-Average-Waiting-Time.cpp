/********************************************
Solution to LeetCode Daily Question 07-09-2024. 
Problem:
There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrival_i, time_i]:
arrival_i is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
time_i is the time needed to prepare the order of the ith customer.
When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
Return the average waiting time of all customers. Solutions within 10^-5 from the actual answer are considered accepted.

Solution:
Simulating the same action taking place, first starting the timer when the ith person arrives and noting the time when he received his order will give the wait time for him.
Simply subtracting the time when the person arrived from the time the person is served does not always give the complete wait time as the person might arrive at a time another order was being prepared. Hence the time when the previous order was served is important. If however the chef was idle, he can start cooking when the person arrives. Hence find time which is the maximum of the time taken to serve the prev order and the arrival time of the customer. Calculate the wait time by adding the time taken to prepare the food to time and subtracting teh arrival time from the resultant. Update the total_time_wait. Return the average.

Time Complexity:   O(N) where N is number of customers
Space Complexity:  O(1)

********************************************/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int i, n;
        int time, wait_time;
        double total_wait_time;
        n = customers.size();
        time = wait_time = 0;
        total_wait_time = 0; 
        for(i = 0; i < n; i++) {
            time = max(time, customers[i][0]);
            wait_time = time + customers[i][1] - customers[i][0];
            total_wait_time += wait_time;
            time += customers[i][1];
        }
        return total_wait_time / n;
    }
};

