#include "unity.h"

#include <limits.h>
#include "lib.h"

void setUp() {}

void tearDown () {}

// func.11:  x + log(y+1) - √z * cos(w)
void test_f11 (void) {
    double x = 2.0, y = 3.0, z = 4.0, w = 0.0;
    double result = f11(2.0, 3.0, 4.0, 0.0);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, 2.0 + log(3.0 + 1.0) - sqrt(4.0) * cos(0.0),
    result
    );
}
// func.15: x - √y * (exp(z) + sin(w))
void test_f15 (void) {
    double x = 5.0, y = 4.0, z = 1.0, w = 0.0;
    double result = f15(5.0, 4.0, 1.0, 0.0);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, 5.0 - sqrt(4.0) * (exp(1.0) + sin(0.0)), 
    result
);
}
// func.20: x + exp(y) * √z - sin(w)
void test_f20 (void) {
    double x = 1.0, y = 0.0, z = 9.0, w = 0.0;
    double result = f20(1.0, 0.0, 9.0, 0.0);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, 1.0 + exp(0.0) * sqrt(9.0) - sin(0.0),
    result 
);
}
// func.5: x * sin(y) / cos(z) + w -√v
void test_f5 (void) {
    double x = 2.0, y = 1.0, z = 0.0, w = 1.0, v = 4.0;
    double result = f5(2.0, 1.0, 0.0, 1.0, 4.0);
    double expected = (x * sin(y)) / cos(z) + w - sqrt(v);
    TEST_ASSERT_DOUBLE_WITHIN(0.00001, expected, result);

}

// main
int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_f11);
    RUN_TEST(test_f15);
    RUN_TEST(test_f20);
    RUN_TEST(test_f5);

    return UNITY_END();
}