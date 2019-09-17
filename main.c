#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TRIALS 100
#define TARGET     30.0

FILE *fp;

// this function returns the sign of x:
// returns either -1, 0, or 1
double sign(double x)
{
    if (x > 0.0) return 1.0;
    if (x < 0.0) return -1.0;
    return 0.0;
}

double prev1 = 0;

double plant(double x, double t)
{
    /* For reference:
     *
     *  log(x) returns the natural log of x
     * fabs(x) returns the absolute value of the float x
     * sign(x) returns -1, 0, or 1 depending on the sign of x (see above)
     */
    double result = prev1 + log(fabs(x)) * sign(x) + 1;
    prev1 = result;

    // %f signifies a "floating point" (decimal point) number
    // fprintf() is a special version of printf() that prints to a specified
    // output. In this case, we pass in `fp`, which is the file we print to.
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
    // we open "out.csv" to write to ("w" means write only)
    fp = fopen("out.csv", "w");

    // now we actually run the trials
    // the constant NUM_TRIALS is hard-coded above.
    double output = 0;
    for (long i = 0; i < NUM_TRIALS; i++)
    {
        double input = PID(output);
        output = plant(input, i);
    }

    // we close the file (since you should always close files you open)
    fclose(fp);

    // we call python to plot our output
    // you may need to run `sudo pip3 install matplotlib` to get this to work.
    system("python plot.py");
    return 0;
}
