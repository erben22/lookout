#include <cstdio>
#include <vector>
#include <string>

void GatherInput(std::vector<std::string>& testCaseData)
{
    unsigned int numStrings = 0;
    scanf("%u\n", &numStrings);
    //printf("For this test case, numstrings is %u.\n", numStrings);

    for (int dataIndex = 0; numStrings > dataIndex; ++dataIndex)
    {
        const unsigned int kMaxStringSize = 100;
        char inputString[kMaxStringSize + 1] = {0};

        scanf("%s\n", reinterpret_cast<char*>(&inputString));

        testCaseData.push_back(inputString);
    }
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



        printf("Case #%u: %s\n", inputIndex, "blah");
    }
}
