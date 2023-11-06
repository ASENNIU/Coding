//
// Created by 13345 on 2023/11/6.
//

#include <cstring>
#include <cstdio>

#define MAXN 10

char inorder[MAXN];
char postorder[MAXN];

void preorder(int in_start, int in_end, int post_start, int post_end);

int main()
{
    scanf("%s", inorder);
    scanf("%s", postorder);
    preorder(0, strlen(inorder), 0, strlen(postorder));

    return 0;
}

void preorder(int in_start, int in_end, int post_start, int post_end) {
    if (post_end == post_start) {
        return;
    }
    char root = postorder[post_end-1];
    printf("%c", root);
    int left_length = 0;
    for (; left_length + in_start < in_end; ++left_length) {
        if (inorder[left_length +  in_start] == root) {
            break;
        }
    }
    preorder(in_start, in_start + left_length, post_start, post_start + left_length);
    preorder(in_start + left_length + 1, in_end, post_start + left_length, post_end - 1);
}