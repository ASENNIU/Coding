//
// Created by 13345 on 2023/11/9.
//

#include <unordered_map>
#include <string>
#include <iostream>

int main()
{
    int n, ans = 0;
    std::string city, state, cat_c2s;
    std::unordered_map<std::string, int> city2state;
    std::cin >> n;
    for (unsigned i = 0; i < n; ++i) {
        std::cin >> city >> state;
        city = city.substr(0, 2);
        if (city2state.find(state + city) != city2state.end() && city != state) {
            ans += city2state[state + city];
        }
        city2state[city + state]++;
    }

    std::cout << ans << std::endl;
    return 0;
}