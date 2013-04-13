#include <cstdio>
#include <string>
#include <math.h>

const int kMaxStringSize = 1000;

bool IsPalindrome(char* pTestString)
{
    bool isPalindrome = false;

    std::string testString(pTestString);
    int stringLength = testString.length();

    if (1 == stringLength)
    {
        isPalindrome = true;
    }
    else
    {
        isPalindrome = true;

        for (int stringIndex = 0; (stringLength / 2) > stringIndex;  ++stringIndex)
        {
            /*printf("Testing stringIndex[%d]: testString[stringIndex]: %c, testString[%d]: %c\n",
                stringIndex, testString[stringIndex], (stringLength - 1) - stringIndex, 
                    testString[(stringLength - 1) - stringIndex]);*/

            if (testString[stringIndex] != testString[(stringLength - 1) - stringIndex])
            {
                isPalindrome = false;
                break;
            }
        }
    }

    /*
    if (isPalindrome)
    {
        printf("%s: %s is %sa palindrome.\n", __FUNCTION__, testString.c_str(), 
            isPalindrome ? "" : "not ");
    }
    */

    return isPalindrome;
}

bool GetSquareRoot(int testNumber, int& square)
{
    bool foundIntegerSquare = false;
    int squareRoot = sqrt(testNumber);
    
    if ((pow(squareRoot - 1, 2)) == testNumber)
    {
        printf("Square root of %d is %d\n", testNumber, squareRoot - 1);
        square = squareRoot - 1;
        foundIntegerSquare = true;
    }
    else if ((pow(squareRoot, 2)) == testNumber)
    {
        printf("Square root of %d is %d\n", testNumber, squareRoot);
        square = squareRoot;
        foundIntegerSquare = true;
    }
    else if ((pow(squareRoot + 1, 2)) == testNumber)
    {
        printf("Square root of %d is %d\n", testNumber, squareRoot + 1);
        square = squareRoot + 1;
        foundIntegerSquare = true;        
    }

    return foundIntegerSquare;
}

int main()
{
    int numInput = 0;
    int inFloor = 0;
    int inCeil = 0;

    scanf("%d\n", &numInput);

    for (int inputIndex = 1; numInput >= inputIndex; ++inputIndex) 
    {
        int numFairNSquares = 0;
        scanf("%d %d\n", &inFloor, &inCeil);

        for (int testIndex = inFloor; inCeil >= testIndex;  ++testIndex)
        {
            char testString[kMaxStringSize] = {0};

            if (0 <= sprintf(testString, "%d" ,testIndex))
            {
                if (IsPalindrome(testString))
                {
                    int squareRoot = 0;
                    char sqrtString[kMaxStringSize] = {0};

                    if (GetSquareRoot(testIndex, squareRoot) && 
                            (0 <= sprintf(sqrtString, "%d" ,squareRoot)) && 
                                IsPalindrome(sqrtString))
                    {
                        ++numFairNSquares;
                    }
                }
            }
        }

        printf("Case #%d (%d...%d): %d\n", inputIndex, inFloor, inCeil, numFairNSquares);
    }
}
