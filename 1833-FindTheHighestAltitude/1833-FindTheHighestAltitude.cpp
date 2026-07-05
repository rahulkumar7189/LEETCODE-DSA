// Last updated: 7/5/2026, 11:03:38 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude = 0;
        int current_altitude = 0;
        
        for (int g : gain) {
            current_altitude += g;
            max_altitude = max(max_altitude, current_altitude);
        }
        
        return max_altitude;
    }
};