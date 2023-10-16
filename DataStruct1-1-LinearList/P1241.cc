//
// Created by 13345 on 2023/10/16.
//

#include <cstdio>
#include <stack>
#include <cstring>

#define N 101
char s[N];
bool is_match[101];
int main()
{
    std::stack<int> st;
    scanf("%s", s);
    int length = strlen(s);
    for (int i = 0; i < length; ++i) {
        if (s[i] == '(' or s[i] == '[') {
            st.push(i);
        } else {
            if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    is_match[st.top()] = true;
                    is_match[i] = true;
                    st.pop();
                }
            } else {
                if (!st.empty() && s[st.top()] == '[') {
                    is_match[st.top()] = true;
                    is_match[i] = true;
                    st.pop();
                }
            }
        }
    }
    for (int i = 0; i < length; ++i) {
        if (is_match[i]) {
            printf("%c", s[i]);
        } else {
            if (s[i] == '(' || s[i] == ')') {
                printf("()");
            } else {
                printf("[]");
            }
        }
    }
    return 0;
}