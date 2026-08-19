// Last updated: 8/19/2026, 11:45:13 PM
// Approach:HashMap & Bitmasking: Used a HashMap to process only the rows that have reservations, as iterating through all $10^9$ rows would cause a Time Limit Exceeded (TLE) error.3-Bit Mask: Tracked the availability of the three valid seating blocks per row using a 3-bit integer mask:Bit 1 (Value 1): Left block (seats 2-5) is ruined.Bit 2 (Value 2): Middle block (seats 4-7) is ruined.Bit 3 (Value 4): Right block (seats 6-9) is ruined.Calculation: Completely empty rows automatically fit 2 families. For rows in the map, if the bitmask value is 0, it fits 2 families. If at least one bit is 0 (meaning at least one block is free), it fits 1 family.Complexity:Time Complexity: $\mathcal{O}(m)$ where $m$ is the number of reserved seats. We only iterate through the given reservedSeats array once and then the unique rows in the map.Space Complexity: $\mathcal{O}(m)$ to store the rows with reservations in the HashMap.
1class Solution {
2    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
3        // Map to track the status of blocks in each row that has reservations
4        Map<Integer, Integer> rowData = new HashMap<>();
5
6        for (int[] seat : reservedSeats) {
7            int row = seat[0];
8            int s = seat[1];
9            
10            int val = rowData.getOrDefault(row, 0);
11
12            // Set bits if a seat falls into one of our three target blocks
13            if (s >= 2 && s <= 5) val |= 1; // Ruins Left block
14            if (s >= 4 && s <= 7) val |= 2; // Ruins Middle block
15            if (s >= 6 && s <= 9) val |= 4; // Ruins Right block
16
17            rowData.put(row, val);
18        }
19
20        // Add 2 families for every completely empty row
21        int maxGroups = (n - rowData.size()) * 2;
22
23        // Process rows with at least one reservation
24        for (int val : rowData.values()) {
25            if (val == 0) {
26                // No blocks were ruined (reservations were only on seat 1 or 10)
27                maxGroups += 2;
28            } else if ((val & 1) == 0 || (val & 2) == 0 || (val & 4) == 0) {
29                // At least one block is still available
30                maxGroups += 1;
31            }
32        }
33
34        return maxGroups;
35    }
36}