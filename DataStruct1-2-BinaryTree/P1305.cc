//
// Created by 13345 on 2023/11/3.
//


/***
 * 关于scanf（）函数我们要知道以下几点：

    1、用户输入的字符，会以ASCII码形式存储在键盘缓冲区；

    2、每调用一次scanf函数，就从键盘缓冲区读走一个字符，相当于清除缓冲区；

    3、若用户一次输入n个字符，则前n次调用scanf函数都不需要用户再次输入，直到把缓冲区的数据全部读取(清除)干净；

    4、调用scanf()函数时，用户最后输入的回车也会储存在键盘缓冲区；
    所以本题不能用scanf一个字符一个字符的读取，这样的话无法有效清除回车键
 */

#include <cstring>
#include <cstdio>

#define MAXN 30

struct node {
    char root;
    char left;
    char right;
};

node tree[MAXN];
char s[4];
void preorder(char root);

int main()
{
    int n;
    scanf("%d", &n);
    char root, left, right, cur_root;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        cur_root = s[0];
        if (i == 0) {
            root = cur_root;
        }
        int idx = cur_root - 'a';
        tree[idx].root = cur_root;
        tree[idx].left = s[1];
        tree[idx].right = s[2];

//        printf("i: %d, %c %c %c\n", i, cur_root, tree[cur_root].left, tree[cur_root].right);


    }
//    printf("root %c\n", root);
    preorder(root);

    return 0;
}

void preorder(char root) {
    int idx =  root - 'a';
    printf("%c", tree[idx].root);
    if (tree[idx].left != '*') {
        preorder(tree[idx].left);
    }
    if (tree[idx].right != '*') {
        preorder(tree[idx].right);
    }
}