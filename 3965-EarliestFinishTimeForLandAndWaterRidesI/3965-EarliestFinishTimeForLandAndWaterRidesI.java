// Last updated: 7/5/2026, 11:02:42 PM
class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int minFinishTime = Integer.MAX_VALUE;
        int n = landStartTime.length;
        int m = waterStartTime.length;

        // Iterate through every possible pair of land and water rides
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // Case 1: Land ride first, then Water ride
                int finishLandFirst = landStartTime[i] + landDuration[i];
                int totalTimeIfLandFirst = Math.max(finishLandFirst, waterStartTime[j]) + waterDuration[j];
                
                // Case 2: Water ride first, then Land ride
                int finishWaterFirst = waterStartTime[j] + waterDuration[j];
                int totalTimeIfWaterFirst = Math.max(finishWaterFirst, landStartTime[i]) + landDuration[i];
                
                // Track the earliest finish time encountered
                minFinishTime = Math.min(minFinishTime, Math.min(totalTimeIfLandFirst, totalTimeIfWaterFirst));
            }
        }

        return minFinishTime;
    }
}