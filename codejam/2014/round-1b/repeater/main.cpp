#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

void GatherInput(std::vector<std::string>& testCaseData)
{
    unsigned int numStrings = 0;
    scanf("%u\n", &numStrings);

    for (int dataIndex = 0; numStrings > dataIndex; ++dataIndex)
    {
        const unsigned int kMaxStringSize = 100;
        char inputString[kMaxStringSize + 1] = {0};

        scanf("%s\n", reinterpret_cast<char*>(&inputString));

        testCaseData.push_back(inputString);
    }
}

void GetUniqueCharacters(const std::string& testCaseString, 
    std::vector<char>& uniqueChars)
{
    for (int stringIndex = 0;  testCaseString.length() > stringIndex; ++stringIndex)
    {
        if (uniqueChars.end() == 
            find(uniqueChars.begin(), uniqueChars.end(), 
                testCaseString.at(stringIndex)))
        {
            uniqueChars.push_back(testCaseString.at(stringIndex));
        }
    }

    
    printf("For string %s, the unique chars are:\n", testCaseString.c_str());
    std::vector<char>::const_iterator uniqueItor = uniqueChars.begin();

    while (uniqueChars.end() != uniqueItor)
    {
        printf("%c", (*uniqueItor));
        uniqueItor++;
    }
    printf("\n");
    
}

bool AllDataEqual(std::vector<std::string>& testCaseData)
{
    std::vector<std::string>::const_iterator itor = testCaseData.begin();

    while (testCaseData.end() != itor)
    {
        std::vector<std::string>::const_iterator nextItor = itor + 1;

        if (testCaseData.end() != nextItor)
        {
            printf("Comparing %s to %s\n", (*itor).c_str(), (*nextItor).c_str());
            if (0 != (*itor).compare((*nextItor)))
            {
                return false;
            }
        }

        itor++;
    }

    return true;
}

bool ProcessStrings(std::vector<std::string>& testCaseData, unsigned int& numMoves)
{
    bool wonGame = false;

    // To have a possibility of winning, all the individual characters
    // must exist in both strings.  The number of each character's
    // appearance is immaterial.

    std::vector<char> uniqueCharsFirst;
    std::vector<char> uniqueCharsSecond;

    GetUniqueCharacters((*itor), uniqueCharsFirst);
    GetUniqueCharacters((*nextItor), uniqueCharsSecond);



    if (AllDataEqual(testCaseData))
    {
        wonGame = true;
    }

    return wonGame;
}

int main()
{
    // Snag the number of test cases and start processing:

    unsigned int numTestCases = 0;
    scanf("%u\n", &numTestCases);

    for (int inputIndex = 1; numTestCases >= inputIndex; ++inputIndex)
    {
        // Gather up the input for this test case:

        std::vector<std::string> testCaseData;
        GatherInput(testCaseData);

        // Debug Output -- start.
        std::vector<std::string>::const_iterator itor = testCaseData.begin();

        while (testCaseData.end() != itor)
        {
            printf("Data for case %u is: %s\n", inputIndex, (*itor).c_str());
            itor++;
        }
        // Debug Output -- end.

        // Process this test case and determine the results:

        unsigned int numMovesToWin = 0;

        if (ProcessStrings(testCaseData, numMovesToWin))
        {
            printf("Case #%u: %u\n", inputIndex, numMovesToWin);
        }
        else
        {
            printf("Case #%u: %s\n", inputIndex, "Fegla Won");
        }
    }
}
