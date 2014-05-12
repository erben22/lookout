#include <cstdio>

int main()
{
    unsigned int numTestCases = 0;
    scanf("%u\n", &numTestCases);
    //printf("Processing %u test cases...\n", numTestCases);

    for (int inputIndex = 1; numTestCases >= inputIndex; ++inputIndex)
    {
        unsigned int answerRow1 = 0;
        scanf("%u\n", &answerRow1);
        //printf("For first table, number is in row %u.\n", answerRow1+1);

        printf("Case #%u: %s\n", inputIndex, "blah");
    }
}
