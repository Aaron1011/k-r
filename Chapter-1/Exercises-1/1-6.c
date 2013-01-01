#include <stdio.h>

/* prove that getchar() != EOF is always 0 or 1 */

main()
{
    printf("%d\n", getchar() != EOF);
}
