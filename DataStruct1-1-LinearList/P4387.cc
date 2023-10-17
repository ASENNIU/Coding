//
// Created by 13345 on 2023/10/17.
//

#include <cstdio>
#include <stack>
#include <stack>

#define N 100005

int input[N];
int output[N];

int main()
{
    int total_num, list_length;
    scanf("%d", &total_num);

    while (total_num--) {
        std::stack<int> st;
        scanf("%d", &list_length);
        for (unsigned i = 0; i < list_length; ++i) {
            scanf("%d", input + i);
        }
        for (unsigned i = 0; i < list_length; ++i) {
            scanf("%d", output + i);
        }
        int in_idx = 0, out_idx = 0;
        while (out_idx < list_length && in_idx < list_length) {
            if(st.empty()) {
                st.push(input[in_idx++]);
                continue;
            }
            if (st.top() == output[out_idx]) {
                st.pop();
                ++out_idx;
            } else {
                st.push(input[in_idx++]);
            }
        }

        while (out_idx < list_length && st.top() == output[out_idx]) {
            st.pop();
            ++out_idx;
        }
        if (st.empty()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }


    }
    return 0;
}