
# step1

40分かかった。
時間計算量：O(log(n))
空間計算量：O(1)
閉区間で行くか半開区間で行くか、前もって決めれば、midの動かし方で躊躇しなくなった。
midとの比較対象として、ずっと配列の左端の値(target)を使っているが、ベストかわからない。
もっとスマートな方法があるのだろうか？

# step2

最初にtargetとして、左端の値をとり、midがtargetより小さくなるたびにtargetをmidで更新すれば、targetが最終的な答えにできる。
leetcodeの答えを見てみたが、全くrotateされていないケースについては、エッジケースとして先に処理し、
残りのケースの最小値を以下の判定式で求めている。

```c:example.c
        // If the mid element is greater than its next element then mid+1
        // element is the smallest This point would be the point of change. From
        // higher to lower value.
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        // If the mid element is lesser than its previous element then mid
        // element is the smallest
        if (mid > 0 && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }
```

rotateしていないケースは特殊なので、こっちの方が直感的で分かりやすい可能性もある。
また、上記の条件式で最初にinflection pointを検出していることで、[2,1]などのケースにおいてもエラーが発生しない。
上記の条件式での検出を行わない場合、以下の操作をすると、nums[mid] <= nums[0]の条件でright = mid - 1を実行するので、1がnums[0]と比較されずスキップされてしまうのである。

```c:example.c
        if (nums[mid] > nums[0]) {
            left = mid + 1;
        } else {
            // If nums[0] is greater than the mid value then this means the
            // smallest value is somewhere to the left
            right = mid - 1;
        }
```

また、他の人の回答も見てみた。
while (left < right - 1)という条件で、leftとrightが並ぶ形で終了するケースもあるのだ学んだ。
色々やると疲れて続かないので、基本的な半開区間、閉区間で練習しようと思う。

# step3

半開区間、閉区間それぞれ２回ずつ行った。
エッジケースをそれぞれ手元で書きながら確認しないと厳しい。
何もせずに書けはするが、脳死で書くだけなので内容を把握したことにはならなそう。
トータル３時間かかった。
