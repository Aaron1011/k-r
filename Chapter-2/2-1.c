#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Data type    Signed or unsigned     Minimum size            Maximum size\n");
    printf("Char         Unsigned               %i                      %i\n", CHAR_MIN, UCHAR_MAX);
    printf("Char         Signed                 %i                      %i\n", SCHAR_MIN, SCHAR_MAX);
    printf("Short        Unsigned               %i                      %i\n", SHRT_MIN, USHRT_MAX);
    printf("Short        Signed                 %i                      %i\n", SHRT_MIN, SHRT_MAX);
    printf("Int          Unsigned               %i                      %i\n", INT_MIN, UINT_MAX);
    printf("Int          Signed                 %i                      %i\n", INT_MIN, INT_MAX);
    printf("Long         Unsigned               %lu                     %li\n", LONG_MIN, LONG_MAX);
    printf("Long         Signed                 %li                     %li\n", LONG_MIN, ULONG_MAX);
    printf("Float        N/A                    %f                      %f\n", FLT_MIN, FLT_MAX);
    printf("Double       N/a                    %lg                     %lg\n", DBL_MIN, DBL_MAX);

    return 0;
}
