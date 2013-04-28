#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdint.h>

extern int correct_main();

int64_t PaintUsed(int64_t radius)
{
    return (radius);
}

int PaintRing(int64_t radius, int64_t paint)
{
    int numRings = 0;

    while (paint >= 0)
    {
        paint -= PaintUsed(radius);
        if (paint > 0)
        {
            ++numRings;
        }
        else if (paint == 0)
        {
            ++numRings;
        }

        radius += 2;
    }

    return numRings;
}

int main()
{
    /*
    freopen("data.in", "r" , stdin); 
    freopen("data.out", "w" , stdout);
    std::cout << std::fixed << std::setprecision(12);
    
    int64_t numInput = 0; 
    std::cin >> numInput;

    for (int inputIndex = 1; numInput >= inputIndex; ++inputIndex) 
    {
        int64_t radius = 0;
        int64_t paint = 0;
        std::cin >> radius >> paint;

        std::cout << "Case #" << inputIndex << ": " << PaintRing(radius, paint) << std::endl;
    }

    return 0
    */

    return correct_main();
}
