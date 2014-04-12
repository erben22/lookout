#include <cstdio>
#include <vector>
#include <string>

void dumpData(std::vector<unsigned int>& data)
{
    std::vector<unsigned int>::const_iterator itor = data.begin();
    
    printf("Dumping data...\n");
    
    while (data.end() != itor)
    {
        printf("%u ", *itor);
        itor++;
    }
    
    printf("\n");
}

std::string findCard(std::vector<unsigned int>& firstRow, std::vector<unsigned int>& secondRow)
{
    const char kBadMagician[] = "Bad magician!";
    const char kCheaterCheater[] = "Volunteer cheated!";
    
    std::string result(kBadMagician);
    
    std::vector<unsigned int> compareList;
    
    std::vector<unsigned int>::const_iterator firstRowItor = firstRow.begin();
    
    while (firstRow.end() != firstRowItor)
    {
        std::vector<unsigned int>::const_iterator secondRowItor = secondRow.begin();
        
        while (secondRow.end() != secondRowItor)
        {
            if (*firstRowItor == *secondRowItor)
            {
                compareList.push_back(*firstRowItor);
            }
            
            secondRowItor++;
        }

        firstRowItor++;
    }
    
    if (compareList.size() == 1)
    {
        const unsigned int kMaxStringSize = 255;
        char resultString[kMaxStringSize] = {0};
        
        snprintf(resultString, kMaxStringSize, "%u", compareList[0]);
        result = resultString;
    }
    else if (compareList.size() == 0)
    {
        result = kCheaterCheater;
    }
    
    return result;
}

int main()
{
    unsigned int numTestCases = 0;
    scanf("%u\n", &numTestCases);
    //printf("Processing %u test cases...\n", numTestCases);

    int trickResult = 0;
    
    for (int inputIndex = 1; numTestCases >= inputIndex; ++inputIndex)
    {
        const unsigned int kMaxTablesRows = 4;
        const unsigned int kMaxRowEntries = 4;
        
        unsigned int answerRow1 = 0;
        scanf("%u\n", &answerRow1);
        --answerRow1;
        //printf("For first table, number is in row %u.\n", answerRow1+1);

        std::vector<unsigned int> cardRow1;
        
        for (int row = 0; kMaxTablesRows > row; ++row)
        {
            if (row == answerRow1)
            {
                for (int column = 0; kMaxRowEntries > column; ++column)
                {
                    unsigned int value = 0;
                    scanf("%u", &value);
                    cardRow1.push_back(value);
                    //printf("Read %u into the array.\n", value);
                }
            }
            else
            {
                //printf("Skipping row(%u).\n", row);
                unsigned int dummyValue1 = 0;
                unsigned int dummyValue2 = 0;
                unsigned int dummyValue3 = 0;
                unsigned int dummyValue4 = 0;
                scanf("%u %u %u %u\n", &dummyValue1, &dummyValue2, &dummyValue3, &dummyValue4);
            }
        }

        //dumpData(cardRow1);
        
        unsigned int answerRow2 = 0;
        scanf("%u\n", &answerRow2);
        --answerRow2;
        //printf("For second table, number is in row %u.\n", answerRow2+1);

        std::vector<unsigned int> cardRow2;
        
        for (int row = 0; kMaxTablesRows > row; ++row)
        {
            if (row == answerRow2)
            {
                for (int column = 0; kMaxRowEntries > column; ++column)
                {
                    unsigned int value = 0;
                    scanf("%u", &value);
                    cardRow2.push_back(value);
                    //printf("Read %u into the array.\n", value);
                }
            }
            else
            {
                //printf("Skipping row(%u).\n", row);
                unsigned int dummyValue1 = 0;
                unsigned int dummyValue2 = 0;
                unsigned int dummyValue3 = 0;
                unsigned int dummyValue4 = 0;
                scanf("%u %u %u %u\n", &dummyValue1, &dummyValue2, &dummyValue3, &dummyValue4);
            }
        }
        
        //dumpData(cardRow2);

        printf("Case #%u: %s\n", inputIndex, findCard(cardRow1, cardRow2).c_str());
    }
}
