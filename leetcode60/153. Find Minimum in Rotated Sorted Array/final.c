int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left <= right) { // leftとrightが交差して終了するケース
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[0]) { // [False,...,False,True,...True]で、Trueの左端が答えになる
            right = mid - 1; // 基本True側にいるが、終了時にFalseに来る
        }
        else {
            left = mid + 1; // 基本False側にいるが、終了時にTrueに来る
        }
    }
//　終了状態は以下のよう。leftの位置が答えに
// [False,...,False,True,...True]
//            right "left"
    return nums[left % numsSize]; // [False,...,False]タイプに対応([0,1,2,3]のケースに対応)
}

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1; // leftとrightが交差して終了するケース
    while (left <= right) { // leftとrightが交差して終了するケース
        int mid = left + (right - left) / 2;
        if (nums[mid] <= nums[numsSize - 1]) { // [False,...,False,True,...True]で、Trueの左端が答えになる
            right = mid - 1; // 基本True側にいるが、終了時にFalseに来る
        }
        else {
            left = mid + 1; // 基本False側にいるが、終了時にTureに来る
        }
    }
    return nums[left];
}


