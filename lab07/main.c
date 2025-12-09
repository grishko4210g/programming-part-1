#include <stdio.h>
#include "lib.h"

int main ()
{
    UNITY_BEGIN ();
    RUN_TEST (test_mul);
    return UNITY_END ();
}