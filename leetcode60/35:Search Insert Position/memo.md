
# step1で感じたこと

30分かけて、エッジケースがうまくいかなかった(step1-draft)。
初稿では、left < rightの条件でwhile文を回したがうまくいかず。
時間計算量：O(log(n))、空間計算量：O(numsSize)
命名は、tailよりleft、headよりrightの方が明確。
２分探索自体のロジックはわかるが、headとtail、pivot(２分探索のための軸)での条件分岐において、境界条件が悩ましい。
while文で、left < rightにするか、left =< rightにするか。
head,tailをpivot近辺に移せばいいのはわかるが、どうすればエラーが全てのケースを網羅できるか難しい。
最後のループまで答えが見つからなかった場合、どのように答えを与えるか迷った。

# step2で感じたこと

空間計算量は、定数なのでO(1)であった。
c言語久々で忘れている、、
int* numsでアドレスを渡しており、nums[pivot]で参照元のアドレスに格納された値を参照している。
配列のメモリは呼び出し元ですでに確保されている。
*numsは配列の先頭の要素を取得、nums[pivot] == *(nums+pivot)。

他の人の回答を見てみると、閉区間、半開区間というか替えがあるらしい。<=と<の違いか。

正直、left <= rightで一回書いて仕舞えば、脳死で欠けてしまうので(頭使ってない)、left < rightで書いてみることにした。

これが試作バージョン

```c:step2.c
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, pivot = 0;
    while (left < right) {
        pivot = left + (right - left) / 2;
        if (nums[pivot] == target) return pivot;
        else if (nums[pivot] > target) right = pivot;
        else left = pivot + 1;
    }
    return left;
}
```

この場合の特徴は、else if (nums[pivot] > target) right = pivot;の部分であると思う。
left == rightのループを許していない分、rightの移動をドラスティックにしすぎると、いきなりright==leftになりleftとtargetの大小比較ができなくなる。逆の条件分岐では、else left = pivot + 1;となり、閉区間手法と同じである。終盤で探索範囲のサイズが２になった場合に、left ==　pivotになるので、else left = pivot;だとループし続けてしまう。

しかしながらこのプログラムだと、右端にtargetが挿入される場合(たとえば、[1,3,5,7]に対して、target==8だった場合)うまく機能しない。
このプログラムは最終的に、left,right,pivotが一致する形で終了する。targetはnums[pivot]のみと比較される。
よって、上記の具体例の場合、最後[5,7]に対してtarget(==8)の挿入位置を検討するが、pivot(==5)と比較を行うものの、right(==7)とは比較しない。よって、index3に入れるのかindex4に入れるのか、検討することができない。

right = numSizeとすることで解決できることがわかった。
半開区間なので、rightを一つ多くとってあげると、右端まで全て検討してあげることができる。

# step3で感じたこと

これくらいの規模のコードだと、深く考えずに脳死で書けてしまうので、閉区間、半開区間それぞれ２回ずつ書いた。
３回連続失敗せずに書くというのが、意外とストレスが溜まる作業だとわかった。
脳死で書いてしまうと、タイポが発生してやり直しになるので、頭を使って書くための制約なのだろうか。
結局、初回ということもあり、ここまでで５時間かかってしまった。。。
