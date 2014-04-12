#include <cstdio>

bool purchaseNewFarm(double farmCost, double currentRate, double boost, double winningAmount)
{
    // Determine if we need to purchase a new farm.  Calculate the time it
    // will take to win with a new farm increasing our rate, and compare it
    // to our current rate.
    
    double secondsToFarm = farmCost / currentRate;
    double newRate = currentRate + boost;
    double secondsToWinWithNewFarm =
    (winningAmount / newRate);
    
    double timeToWinWithNewFarm =
        secondsToFarm + secondsToWinWithNewFarm;
    double timeToWinAtCurrentRate = (winningAmount / currentRate);
    
    return (timeToWinWithNewFarm < timeToWinAtCurrentRate);
}

double findResult(double cost, double boost, double winningAmount)
{
    double timeToWin = 0.0;
    
    const double kStartCookies = 0.0;
    const double kInitialCookieRate = 2.0;
    
    if (winningAmount <= cost)
    {
        // Short-circuit, if a farm costs more than we need to win, just
        // stop here.
        
        timeToWin = winningAmount / kInitialCookieRate;
    }
    else
    {
        double currentRate = kInitialCookieRate;
        
        while (1)
        {
            if (purchaseNewFarm(cost, currentRate, boost, winningAmount))
            {
                // Need to buy a new farm, so update our total time, and
                // then buy the farm.  We do not have to track cookies
                // at all, just the time to get to a new farm.
                
                timeToWin += cost / currentRate;
                currentRate += boost;
            }
            else
            {
                // We do not need to buy a new farm.  Find out how much
                // time we need to win at our current rate, and add that
                // to the time we have accumulated so far farming.
                
                timeToWin += (winningAmount / currentRate);
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
