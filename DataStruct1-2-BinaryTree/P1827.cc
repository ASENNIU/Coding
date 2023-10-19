//
// Created by 13345 on 2023/10/19.
//

#include <iostream>
#include <string>

void postorder(std::string& pre, std::string& in) {
    /***
     * @brief 根据前序的根节点在中序的位置，划分子树
     */
    if (pre.empty()) {
        return;
    }
    char root = pre[0];
    int order = in.find(root);
    std::string left_in = in.substr(0, order);
    std::string right_in = in.substr(order + 1);
    std::string left_pre = pre.substr(1, order);
    std::string right_pre = pre.substr(order + 1);
    postorder(left_pre, left_in);
    postorder(right_pre, right_in);
    std::cout << root;
}

int main()
{
    std::string preorder, inorder;
    std::cin >> inorder >> preorder;
    postorder(preorder, inorder);

    return 0;
}