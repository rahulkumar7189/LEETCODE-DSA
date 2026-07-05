// Last updated: 7/5/2026, 11:02:43 PM
import java.util.Arrays;

class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int n = landStartTime.length;
        int m = waterStartTime.length;

        Ride[] landRides = new Ride[n];
        for (int i = 0; i < n; i++) {
            landRides[i] = new Ride(landStartTime[i], landDuration[i]);
        }

        Ride[] waterRides = new Ride[m];
        for (int j = 0; j < m; j++) {
            waterRides[j] = new Ride(waterStartTime[j], waterDuration[j]);
        }

        // Sort both by start time ascending
        Arrays.sort(landRides, (a, b) -> Integer.compare(a.start, b.start));
        Arrays.sort(waterRides, (a, b) -> Integer.compare(a.start, b.start));

        int ans = Integer.MAX_VALUE;
        ans = Math.min(ans, solveOneWay(landRides, waterRides));
        ans = Math.min(ans, solveOneWay(waterRides, landRides));

        return ans;
    }

    private int solveOneWay(Ride[] firstRides, Ride[] secondRides) {
        int n = firstRides.length;
        int m = secondRides.length;

        // prefixMinDuration[j] = min duration among secondRides[0 ... j]
        int[] prefixMinDuration = new int[m];
        prefixMinDuration[0] = secondRides[0].duration;
        for (int j = 1; j < m; j++) {
            prefixMinDuration[j] = Math.min(prefixMinDuration[j - 1], secondRides[j].duration);
        }

        // suffixMinFinish[j] = min finish time among secondRides[j ... m-1]
        int[] suffixMinFinish = new int[m];
        suffixMinFinish[m - 1] = secondRides[m - 1].start + secondRides[m - 1].duration;
        for (int j = m - 2; j >= 0; j--) {
            suffixMinFinish[j] = Math.min(suffixMinFinish[j + 1], secondRides[j].start + secondRides[j].duration);
        }

        int minResult = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int firstFinishTime = firstRides[i].start + firstRides[i].duration;

            // Binary search to find the largest index where secondRides[idx].start <= firstFinishTime
            int idx = binarySearch(secondRides, firstFinishTime);

            // Case A: Rides that open BEFORE or AT firstFinishTime (indices 0 to idx)
            if (idx >= 0) {
                minResult = Math.min(minResult, firstFinishTime + prefixMinDuration[idx]);
            }

            // Case B: Rides that open AFTER firstFinishTime (indices idx + 1 to m - 1)
            if (idx + 1 < m) {
                minResult = Math.min(minResult, suffixMinFinish[idx + 1]);
            }
        }

        return minResult;
    }

    // Returns the largest index where ride.start <= target, or -1 if none
    private int binarySearch(Ride[] rides, int target) {
        int low = 0, high = rides.length - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (rides[mid].start <= target) {
                ans = mid;
                low = mid + 1; // Try to find a larger index
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    private static class Ride {
        int start;
        int duration;

        Ride(int start, int duration) {
            this.start = start;
            this.duration = duration;
        }
    }
}