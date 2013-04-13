#include <cstdio>
#include <string>

const int kMaxStringSize = 1000;

bool IsPalindrome(char* pTestString)
{
    bool isPalindrome = false;

    std::string testString(pTestString);
    int stringLength = testString.length();

    printf("testString: %s\n", testString.c_str());

    if (1 == stringLength)
    {
        isPalindrome = true;
    }
    else
    {
        isPalindrome = true;

        for (int stringIndex = 0; (stringLength / 2) > stringIndex;  ++stringIndex)
        {
            printf("Testing stringIndex[%d]: testString[stringIndex]: %c, testString[%d]: %c\n",
                stringIndex, testString[stringIndex], (stringLength - 1) - stringIndex, 
                    testString[(stringLength - 1) - stringIndex]);

            if (testString[stringIndex] != testString[(stringLength - 1) - stringIndex])
            {
                isPalindrome = false;
                break;
            }
        }
    }

    return isPalindrome;
}

bool IsSquare(int testNumber)
{
    bool isSquare = false;

    return isSquare;
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
                if (IsPalindrome(testString) && IsSquare(testIndex))
                {
                    ++numFairNSquares;
                }
            }
        }

        printf("Case #%d (%d...%d): %d\n", inputIndex, inFloor, inCeil, numFairNSquares);
    }
}
