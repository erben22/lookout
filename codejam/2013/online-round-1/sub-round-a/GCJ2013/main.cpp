#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdint.h>

int64_t PaintUsed(int64_t radius)
{
    return ((int)radius * (int)radius);
}

int64_t PaintRing(int64_t radius, int64_t paint)
{
    int64_t paintLeft = paint - PaintUsed(radius);
    if (paintLeft > 0)
    {
        return (1 + PaintRing(radius + 2, paintLeft));
    }
    else if (paintLeft == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
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

    return 0;
}
