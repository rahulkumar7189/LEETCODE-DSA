// Last updated: 9/15/2026, 11:57:33 PM
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if rec1 is completely to the outside of rec2
        bool isLeft = rec1[2] <= rec2[0];
        bool isRight = rec1[0] >= rec2[2];
        bool isBottom = rec1[3] <= rec2[1];
        bool isTop = rec1[1] >= rec2[3];
        
        // If any of the above are true, they do not overlap.
        // Therefore, we return the negation.
        return !(isLeft || isRight || isBottom || isTop);
    }
};