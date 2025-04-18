int searchInsert(int* nums, int numsSize, int target) {
    int tail = 0;
    int head = numsSize - 1;
    int res = 0;

    while (tail < head) {
        int pivot = (tail + head) / 2 + 1;
        if (nums[pivot] == target) {
            res = pivot;
            return res;
        }
        else if (nums[pivot] > target) {
            head = pivot - 1;
            res = pivot;
        }
        else {
            tail = pivot;
            res = pivot + 1;
        }
    }
    return res;
}
