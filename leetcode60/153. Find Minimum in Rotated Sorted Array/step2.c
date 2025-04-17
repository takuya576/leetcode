int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1, target = nums[0];
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        if (nums[mid] < target) {
            target = nums[mid];
        }
    }
    return target;
}
