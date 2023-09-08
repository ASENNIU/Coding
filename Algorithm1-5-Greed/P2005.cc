//
// Created by 13345 on 2023/9/8.
//

#include <string>
#include <iostream>

int compare(const std::string& str1, const std::string& str2);
/***
 * @brief 高精度运算
 */
std::string add(std::string str1, std::string str2);

/***
 * @brief 高精度减法（只支持大的减小的）
 * @details 默认 str1代表的value > str2代表的value
 */
std::string sub(std::string str1, std::string str2);

std::string mul(std::string str1, std::string str2);

/***
 * @brief 高精度除法
 * @param str1
 * @param str2
 * @param quotient 商
 * @param residue 余数
 */
void divide(std::string str1, std::string str2, std::string& quotient, std::string& residue);

void do_divide(std::string& str1, std::string& str2, std::string& quotient, std::string& residue);
int main()
{
    std::string str1, str2, quotient, residue;
    std::cin >> str1 >> str2;
//    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;
    //std::string ans = sub(str1, str2);
    divide(str1, str2, quotient, residue);
    //std::cout << "ans: " << ans << std::endl;
//    std::cout << "quotient: " << quotient << ", residue: " << residue << std::endl;
    std::cout << quotient << std::endl;
}

int compare(const std::string& str1, const std::string& str2) {
    int length1 = str1.size();
    int length2 = str2.size();
    if (length1 > length2) {
        return 1;
    } else if (length1 < length2) {
        return -1;
    } else {
        return str1.compare(str2);
    }
}

std::string add(std::string str1, std::string str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    if (length1 < length2) {
        for (int i = 0; i < length2 - length1; ++i) {
            str1 = '0' + str1;
        }
    } else {
        for (int i = 0; i < length1 - length2; ++i) {
            str2 = '0' + str2;
        }
    }
//    std::cout << "after append: " << str1 << ", " << str2 << std::endl;
    int length = str1.length();
    int cf = 0, tmp, cur_add;
    std::string ans;
    for (int i = length - 1; i >= 0; --i) {
        cur_add = (str1[i] - '0') + (str2[i] - '0') + cf;
        cf = cur_add / 10;
        tmp = cur_add % 10;
        ans = char(tmp + '0') + ans;
    }
    if (cf != 0) ans = char(cf + '0') + ans;
    return ans;
}

std::string sub(std::string str1, std::string str2) {
    std::string ans;
    int cf = 0, tmp;
    int length1 = str1.length(), length2 = str2.length();
    int gap = length1 - length2;
    for (int i = length2 - 1; i >=0; --i) {
        if (str1[gap + i] - cf < str2[i]) {
            tmp = (str1[gap + i] - str2[i]) -cf + 10;
            cf = 1;
            ans = char(tmp + '0') + ans;
        } else {
            tmp = (str1[gap + i] - str2[i]) - cf;
            cf = 0;
            ans = char(tmp + '0') + ans;
        }
    }
    for (int i = gap - 1; i >= 0; --i) {
        if (str1[i] - cf >= '0') {
            ans = char(str1[i] - cf) + ans;
            cf = 0;
        } else {
            ans = char(str1[i] + 10 - cf) + ans;
            cf = 1;
        }
    }
    ans.erase(0, ans.find_first_not_of('0'));
    if (ans.empty())
        ans = "0";
    return ans;
}

std::string mul(std::string str1, std::string str2) {
    std::string ans = "0";
    std::string tmpstr;
    int cf, val;
    size_t length1 = str1.length(), length2 = str2.length();
    for (int i = length2 - 1; i >= 0; --i) {
        int cur_val = str2[i] - '0';
        if (cur_val != 0) {
            cf = 0;
            tmpstr = "";
            for (int j = length1 - 1; j >= 0; --j) {
               val = (str1[j] - '0') * cur_val + cf;
               cf = val / 10;
               tmpstr = char(val % 10 + '0') + tmpstr;
            }
            if (cf != 0) tmpstr = char(cf + '0') + tmpstr;
            for (int k = 0; k < length2 - i - 1; ++k) {
                tmpstr += '0';
            }

            ans = add(ans, tmpstr);
        }
    }
    ans.erase(0, ans.find_first_not_of('0'));
    if (ans.empty())
        ans = "0";
    return ans;
}



void divide(std::string str1, std::string str2, std::string& quotient, std::string& residue) {
    quotient=residue="";
    if (str2 == "0") {
        quotient = residue = "ERROR: divide by zero.";
    }
    if (str1 == "0") {
        quotient = residue = "0";
        return;
    }
    int res = compare(str1, str2);
    if (res < 0) {
        quotient = "0";
        residue = str2;
        return;
    } else if (res == 0) {
        quotient = "1";
        residue = "0";
        return;
    } else {
        do_divide(str1, str2, quotient, residue);
        return;
    }
}

void do_divide(std::string& str1, std::string& str2, std::string& quotient, std::string& residue) {
    int length1 = str1.length(), length2 = str2.length();
    std::string tmpstr = str1.substr(0, length2 - 1);
    for (int i = length2 - 1; i < length1; ++i) {
        tmpstr += str1[i];
        tmpstr.erase(0, tmpstr.find_first_not_of('0'));
        if (tmpstr.empty())
            tmpstr = "0";
        for (char val = '9'; val >= '0'; --val) {
            std::string factor;
            factor += val;
            std::string acc = mul(str2, factor);
            if (compare(acc, tmpstr) <= 0) {
                quotient += val;
                tmpstr = sub(tmpstr, acc);
                break;
            }
        }
    }
    residue = tmpstr;
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty())
        quotient = "0";
    return;
}