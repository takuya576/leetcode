int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(sizeof(int)*2);
                *returnSize = 2;
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    int* result = (int*)malloc(sizeof(int)*0);
    *returnSize = 0;
    return result;
}

////////////////////////////////////////////
void swap(int * const a, int * const b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition_indexes(const int* const nums, int* const indexes, int lo, int hi) {
    int pivot = lo++; // pivotの値として一番左の値を使用、値の比較は次のインデックスから始めるのでincrement
    int pivot_val = nums[indexes[pivot]]; // pivotの値
    int idx = pivot; // pivotの値以下であることが保証されている左のグループグループの、一番右のidx
    for (; lo < hi; ++lo) {
        if (nums[indexes[lo]] <= pivot_val) { // [True,....,True,"False",..,False,"True",?,?,...]
            swap(indexes + lo, indexes + ++idx); // pivot以下と判明したindexと、pivot以下が保証されている集団のすぐ右のindexを交換
        }
    }
    swap(indexes + pivot, indexes + idx); // 最後にpivot(一番左)と、pivot以下が保証されている集団の右端を交換
    // swap前：["True(pivot)",....,"True",False,..,False]
    // swap後：["True",....,"True(pivot)",False,..,False]
    return idx;
}

void sort_indexes(const int* const nums, int* const indexes, int lo, int hi) {
    if (lo < hi) {
        int pivot = partition_indexes(nums, indexes, lo, hi);
        sort_indexes(nums, indexes, lo, pivot); // pivotを除いた左半分
        sort_indexes(nums, indexes, pivot + 1, hi); // pivotを除いた右半分
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* indexes = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        indexes[i] = i;
    }
    sort_indexes(nums, indexes, 0, numsSize);

    int left = 0, right = numsSize - 1;
    while (left < right) {
        if (nums[indexes[left]] + nums[indexes[right]] == target) {
            int* result = (int*)malloc(sizeof(int) * 2);
            result[0] = indexes[left];
            result[1] = indexes[right];
            *returnSize = 2;
            return result;
        }
        if (nums[indexes[left]] + nums[indexes[right]] < target) {
            ++left;
        }
        else {
            --right;
        }
    }
    int* result = (int*)malloc(sizeof(int) * 0);
    *returnSize = 0;
    return result;
}
