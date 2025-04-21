
# step1

５分考えて、Brute Forceと、ソートしてから両端の二つから段々内側にindexをずらしていき、nums[left] + nums[right] == targetを満たす組を見つける手法は思いついた。
ソートの実装方法はわからない。。。
前者はO(n^2)、後者はO(nlog(n))。

ハッシュマップを使う方法はなんとなく思いつくが完全なロジックにはならない。
考えたやり方は以下。
１：nums内の数をそれぞれキーとする辞書を作成する。
２：nums全ての要素(xi)について、(target - xi)のキーを辞書から検索し、そのキーが存在していたら、xiと(target - xi)のセットを返す。

ただcで辞書型を作成する方法を忘れた。
大きな配列メモリを確保して、indexをキー、要素をバリューとする配列を作ればいい。
ただ、バリューは何にすればいいのか。True, Flaseでは、２個同じ値があるときに対応できない。
純粋に、nums内でのキーの数字の個数を格納するのがいいか。
上記手順の２番のループでは、まず キー == xi の要素を-1して、(target - xi)のキーを検索し、要素が1なら(xi, target - xi)のセットを返すといったところか。
辞書配列の要素に対して減算を行うので、配列のコピーをつくておいた方がいい。
辞書の作成、および検索がそれぞれO(n)なので、全体としてもO(n)だろう。

c言語でhashテーブルを作る方法がわからないので、模範解答を調べることに。
構造体を使うらしい。
コードを見たが、HASH_FIND_INTやらHASH_ITERやらが意味わからん。

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        item->key = target - nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }
    *returnSize = 0;
    // If no valid pair is found, return an empty array
    return malloc(sizeof(int) * 0);
}
```

uthashというハッシュテーブルのライブラリらしい。
cでハッシュテーブルやろうとすると、構造体とかuthash使わなきゃいけないからめんどくさいなあ、、、

次に「sort+両端のポインタ」の手法を実装してみる。

# step2

他の人の解法を見てみると、同じようにBrute ForceとHash Map、ソートしてからポインタを左右から動かす方法を行っている人が多い。
ソート後に、一つ目の数を選び、二つ目を２分探索で探すという手法もあった。

leetcodeを真似して、クイックソートを自前で実装してみた。
