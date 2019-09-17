#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TRIALS 100
#define TARGET     30.0

FILE *fp;
 
double sign(double x)
{ 
    if (x > 0.0) return 1.0;
    if (x < 0.0) return -1.0;
    return 0.0;
}

double prev1 = 0;
double plant(double x, double t)
{
    double result = prev1 + log(fabs(x)) * sign(x) + 1;
    prev1 = result;

    fprintf(fp, "%f,%f\n", t, result);
    return result;
}

double PID(double output)
{
    // YOUR CODE HERE
    
    return 0;
}

int main()
{
    fp = fopen("out.csv", "w");

    double output = 0;
    for (long i = 0; i < NUM_TRIALS; i++)
    {
        double input = PID(output);
        output = plant(input, i);
    }

    fclose(fp);
    system("python plot.py");
    return 0;
}
