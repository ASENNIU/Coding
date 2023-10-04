//
// Created by 13345 on 2023/10/4.
//
#include <string>
#include <iostream>

int main()
{
    std::string src("abcd");
    std::string tmp("fgbd");
    std::string t("ux");
    auto pos = src.find_first_of(tmp);
//    std::string str = src.replace(pos, tmp.length(), t);
    std::cout << pos << std::endl;
    return 0;
}