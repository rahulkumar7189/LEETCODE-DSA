// Last updated: 8/25/2026, 3:06:47 PM
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        // Map to track the status of blocks in each row that has reservations
        Map<Integer, Integer> rowData = new HashMap<>();

        for (int[] seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];
            
            int val = rowData.getOrDefault(row, 0);

            // Set bits if a seat falls into one of our three target blocks
            if (s >= 2 && s <= 5) val |= 1; // Ruins Left block
            if (s >= 4 && s <= 7) val |= 2; // Ruins Middle block
            if (s >= 6 && s <= 9) val |= 4; // Ruins Right block

            rowData.put(row, val);
        }

        // Add 2 families for every completely empty row
        int maxGroups = (n - rowData.size()) * 2;

        // Process rows with at least one reservation
        for (int val : rowData.values()) {
            if (val == 0) {
                // No blocks were ruined (reservations were only on seat 1 or 10)
                maxGroups += 2;
            } else if ((val & 1) == 0 || (val & 2) == 0 || (val & 4) == 0) {
                // At least one block is still available
                maxGroups += 1;
            }
        }

        return maxGroups;
    }
}