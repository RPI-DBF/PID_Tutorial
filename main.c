#include <stdio.h>
#include <stdlib.h>

#define NUM_TRIALS 200
#define TARGET     10

FILE *fp;

long plant(long input, long time)
{
    double x = (double)time;
    double result = x + 0.1 * (float)input;
    fprintf(fp, "%ld,%ld\n", time, (long)result);
    return ((long)result);
}

long PID(long output)
{
    // YOUR CODE HERE
    
    return 0;
}

int main()
{
    fp = fopen("out.csv", "w");

    long output = 0;
    for (long i = 0; i < NUM_TRIALS; i++)
    {
        long input = PID(output);
        output = plant(input, i);
    }

    fclose(fp);
    system("python plot.py");
    return 0;
}
