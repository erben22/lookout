#include <cstdio>

double findResult(float cost, float boost, float winningAmount)
{
    return 1.0;
}

int main()
{
    double numTestCases = 0;
    scanf("%lf\n", &numTestCases);
    printf("Processing %f test cases...\n", numTestCases);

    for (int inputIndex = 1; numTestCases >= inputIndex; ++inputIndex)
    {
        double cookieFarmCost = 0.00;
        double cookiePerSecondBoost = 0.00;
        double winningCookieAmount = 0.00;
        
        scanf("%lf %lf %lf\n", &cookieFarmCost, &cookiePerSecondBoost, &winningCookieAmount);
        printf("  Cookie Farms cost %0.7f.\n", cookieFarmCost);
        printf("  CPS boost is %0.7f.\n", cookiePerSecondBoost);
        printf("  To win, you need %0.7f. cookies\n", winningCookieAmount);
        
        printf("Case #%u: %f\n", inputIndex, findResult(cookieFarmCost, cookiePerSecondBoost, winningCookieAmount));
    }
}
