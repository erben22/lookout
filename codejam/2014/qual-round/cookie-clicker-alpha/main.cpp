#include <cstdio>

bool purchaseNewFarm(double farmCost, double currentRate, double boost, double winningAmount)
{
    double secondsToFarm = farmCost / currentRate;
    double newRate = currentRate + boost;
    double secondsToWinWithNewFarm =
    (winningAmount / newRate);
    
    double timeToWinWithNewFarm =
        secondsToFarm + secondsToWinWithNewFarm;
    double timeToWinAtCurrentRate = (winningAmount / currentRate);
    
    printf("    secondsToFarm(%0.7f), newRate(%0.7f), secondsToWinWithNewFarm(%0.7f)\n",
           secondsToFarm, newRate, secondsToWinWithNewFarm);
    printf("    timeToWinWithNewFarm(%0.7f), timeToWinAtCurrentRate(%0.7f)\n",
           timeToWinWithNewFarm,  timeToWinAtCurrentRate);

    return (timeToWinWithNewFarm < timeToWinAtCurrentRate);
}

double findResult(double cost, double boost, double winningAmount)
{
    double timeToWin = 0.0;
    
    printf("  Cookie Farms cost %0.7f.\n", cost);
    printf("  CPS boost is %0.7f.\n", boost);
    printf("  To win, you need %0.7f cookies.\n", winningAmount);
    
    const double kStartCookies = 0.0;
    const double kInitialCookieRate = 2.0;
    
    if (winningAmount <= cost)
    {
        timeToWin = winningAmount / kInitialCookieRate;
    }
    else
    {
        double currentRate = kInitialCookieRate;
        double numCookies = 0.0;
        
        while (numCookies < winningAmount)
        {
            if (purchaseNewFarm(cost, currentRate, boost, winningAmount))
            {
                printf("   Purchasing new farm.\n");
                printf("     PRE: timeToWin(%0.7f), currentRate now(%0.7f)\n", timeToWin, currentRate);
                timeToWin += cost / currentRate;
                currentRate += boost;
                printf("     POST: timeToWin(%0.7f), currentRate now(%0.7f)\n", timeToWin, currentRate);
            }
            else
            {
                printf("   Can win without a new farm.\n");
                printf("     PRE: timeToWin(%0.7f)\n", timeToWin);
                timeToWin += (winningAmount / currentRate);
                printf("     POST: timeToWin(%0.7f)\n", timeToWin);
                break;
            }
        }
    }
    
    
    return timeToWin;
}

int main()
{
    double numTestCases = 0;
    scanf("%lf\n", &numTestCases);
    //printf("Processing %f test cases...\n", numTestCases);

    for (int inputIndex = 1; numTestCases >= inputIndex; ++inputIndex)
    {
        double cookieFarmCost = 0.00;
        double cookiePerSecondBoost = 0.00;
        double winningCookieAmount = 0.00;
        
        scanf("%lf %lf %lf\n", &cookieFarmCost, &cookiePerSecondBoost,
              &winningCookieAmount);
        
        printf("Case #%u: %0.7f\n", inputIndex,
               findResult(cookieFarmCost, cookiePerSecondBoost, winningCookieAmount));
    }
}
