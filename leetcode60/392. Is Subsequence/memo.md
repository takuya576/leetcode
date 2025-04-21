
# step1

一番最初に思いついたのは、sの一文字目と合致するものをtから探し、次に二文字目と合致するものをtのそれ以降から探す方針である。これを繰り返すと、合致するものがあるか時間計算量O(n)で計算できる。

```c
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int s_len = strlen(s), t_len = strlen(t);
    int s_i = 0;
    if (s_len == 0) {
        return true;
    }
    for (int t_i = 0; t_i < t_len; ++t_i) {
        if (s[s_i] == t[t_i]) {
            ++s_i;
        }
        if (s_i >= s_len) {
            return true;
        }
    }
    return false;
}
```

# step2

