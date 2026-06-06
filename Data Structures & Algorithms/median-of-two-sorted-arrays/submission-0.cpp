class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;
            int A_left = (i == 0) ? INT_MIN : nums1[i - 1];
            int A_right = (i == m) ? INT_MAX : nums1[i];
            
            int B_left = (j == 0) ? INT_MIN : nums2[j - 1];
            int B_right = (j == n) ? INT_MAX : nums2[j];
            if (A_left <= B_right && B_left <= A_right) {
                if ((m + n) % 2 != 0) {
                    return std::max(A_left, B_left);
                }
                // If total number of elements is even
                return (std::max(A_left, B_left) + std::min(A_right, B_right)) / 2.0;
            }
            else if (A_left > B_right) {
                // We are too far right in nums1. Move the partition left.
                high = i - 1;
            }
            else {
                // We are too far left in nums1. Move the partition right.
                low = i + 1;
            }
        }
        
        return 0.0; // Return
    }
};
