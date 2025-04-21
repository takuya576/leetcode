#include <string.h>
#include <stdbool.h>

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

#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int s_len = strlen(s), t_len = strlen(t);
    int s_i = 0, t_i = 0;
    while (s_i < s_len && t_i < t_len) {
        if (s[s_i] == t[t_i]) {
            ++s_i;
        }
        ++t_i;
    }
    if (s_i < s_len) {
        return false;
    }
    else {
        return true;
    }
}
