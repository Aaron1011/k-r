#include <stdio.h>

/* print Celsius-Fahrenheit table
   for fahr = 0, 20, ..., 300; floating-point version */

int convert(float val, int scale);

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;		/* lower limit of temperature table */
    upper = 300;	/* upper limit */
    step = 20;		/* step size */

    celsius = lower;
		printf("Celsius-fahrenheit table\n");
		while (celsius <= upper) {
				fahr = convert(celsius, 'f');
				printf("%3.0f %6.1f\n", celsius, fahr);
				celsius = celsius + step;
		}
		return 0;
}

int convert(float val, int scale)
{
		if (scale == 'c' || scale == 'C')
				return  ((val - 32.0) * 5) / 9;
		else if (scale == 'f' || scale == 'F')
				return (val * 1.8) + 32.0;
}
