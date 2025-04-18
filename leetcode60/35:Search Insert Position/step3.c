int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize, pivot = 0;
    while (left < right) {
        pivot = left + (right - left) / 2;
        if (nums[pivot] == target) return pivot;
        else if (nums[pivot] > target) right = pivot;
        else left = pivot + 1;
    }
    return left;
}

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize, pivot = 0;
    while (left < right) {
        pivot = left + (right - left) / 2;
        if (target == nums[pivot]) return pivot;
        else if (target < nums[pivot]) right = pivot;
        else left = pivot + 1;
    }
    return left;
}
