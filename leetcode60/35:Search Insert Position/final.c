int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) { // 最後にrightとleftが交差して終わる形式。終了条件はright<left。
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) { // [False,....,False,True,.....,True]の棒を考え、一番左のTrueが答えになる。
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
//　以下が終了状態。leftが答えになる。
// [False,....,False,True,.....,True]
//             right, left
}
