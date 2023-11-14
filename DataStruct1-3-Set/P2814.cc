//
// Created by 13345 on 2023/11/14.
//

#include <string>
#include <unordered_map>
#include <iostream>

int main()
{
    std::string  str, fa, name;
    std::unordered_map<std::string, std::string> name_map;
    while (std::cin >> str && str != "$") {
        if (str[0] == '#') {
            fa = str.substr(1);
            if (name_map[fa].empty())
                name_map[fa] = fa;

        } else if (str[0] == '+') {
            name_map[str.substr(1)] = fa;
        } else {
            name = str.substr(1);
            std::cout << name << ' ';
            while (name_map[name] != name) {
                name = name_map[name];
            }
            std::cout << name << '\n';
        }
    }

    return 0;
}
