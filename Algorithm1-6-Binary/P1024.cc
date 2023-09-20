//
// Created by 13345 on 2023/9/20.
//

#include <stdio.h>
#include <math.h>

float a, b, c, d;
float func(float x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

int main()
{
    scanf("%f %f %f %f", &a, &b, &c, &d);
    float left, right, mid, y1, y2;
    int count = 0;
    for (int i = -100; i < 100; ++i) {
        left = i;
        right = i + 1;
        y1 = func(left);
        if (!y1) {
            printf("%.2f ", left);
            ++count;
        }
        y2 = func(right);
        if (y1 * y2 < 0) {
            while (right - left >= 0.001) {
                mid = (right + left) / 2;
                if (func(left) * func(mid) <= 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            printf("%.2f ", left);
            ++count;
        }
        if (count == 3)
            break;
    }

    return 0;
}