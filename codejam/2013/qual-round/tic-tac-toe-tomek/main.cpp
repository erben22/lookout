#include <cstdio>

#define NumObjects(x) sizeof(x)/sizeof(x[0])

const int kBufferSize = 10;
const int kNumRows = 4;
const int kNumColumns = 4;
const int kNumforMatch = 4;
const char kWildcardSymbol = 'T';

char dataSet[kNumRows][kNumColumns] = {0};

bool IsSymbolMatch(char symbol, char testChar)
{
    return (((symbol == testChar) || (kWildcardSymbol == symbol)) ? 
        true : false);
}

void BuildInput()
{
    for (int rowIndex = 0;  kNumRows > rowIndex;  ++rowIndex)
    {
        char inputLine[kBufferSize] = {0}; 
        scanf("%s\n", inputLine);

        for (int columnIndex = 0;  kNumColumns > columnIndex;  ++columnIndex)
        {
            dataSet[rowIndex][columnIndex] = inputLine[columnIndex];
        }
    }
}

bool IsCharPresent(char searchChar)
{
    bool found = false;

    for (int rowIndex = 0; (kNumRows > rowIndex) && (false == found);  ++rowIndex)
    {
        for (int columnIndex = 0; kNumColumns > columnIndex;  ++columnIndex)
        {
            if (searchChar == dataSet[rowIndex][columnIndex])
            {
                found = true;
                break;
            }
        }
    }

    return found;
}

bool SeachForWinner(char symbol)
{
    bool foundWinner = false;

    // Make a copy of the data set and change all wildcards to our search symbol:

    char workingDataSet[kNumRows][kNumColumns] = {0};
    
    for (int rowIndex = 0;  kNumRows > rowIndex;  ++rowIndex)
    {
        for (int columnIndex = 0;  kNumColumns > columnIndex;  ++columnIndex)
        {
            workingDataSet[rowIndex][columnIndex] = dataSet[rowIndex][columnIndex];

            if (kWildcardSymbol == workingDataSet[rowIndex][columnIndex])
            {
                workingDataSet[rowIndex][columnIndex] = symbol;
            }
        }
    }

    // Search rows:

    for (int rowIndex = 0; (kNumRows > rowIndex) && (false == foundWinner);  ++rowIndex)
    {
        if (symbol == workingDataSet[rowIndex][0])
        {
            bool noMatch = false;

            for (int columnIndex = 0; kNumColumns > columnIndex;  ++columnIndex)
            {
                if ((symbol != workingDataSet[rowIndex][columnIndex]) && 
                    (kWildcardSymbol != workingDataSet[rowIndex][columnIndex]))
                {
                    noMatch = true;
                    break;
                }
            }

            if (false == noMatch)
            {
                // Winner winner chicken dinner.

                foundWinner = true;
                break;
            }
        }
    }

    // Search columns:
    
    for (int columnIndex = 0; (kNumColumns > columnIndex) && (false == foundWinner);  ++columnIndex)
    {
        if (symbol == workingDataSet[0][columnIndex])
        {
            bool noMatch = false;

            for (int rowIndex = 0; kNumRows > rowIndex;  ++rowIndex)
            {
                if ((symbol != workingDataSet[rowIndex][columnIndex]) && 
                    (kWildcardSymbol != workingDataSet[rowIndex][columnIndex]))
                {
                    noMatch = true;
                    break;
                }
            }

            if (false == noMatch)
            {
                // Winner winner chicken dinner.

                foundWinner = true;
                break;
            }
        }
    }

    // Search diagonals:

    int rowIndex = 0;
    int columnIndex = 0;
    int numMatched = 0;

    if ((false == foundWinner) && (IsSymbolMatch(symbol, workingDataSet[rowIndex][columnIndex])))
    {
        ++numMatched;

        for (int matchIndex = 1; kNumforMatch > matchIndex;  ++matchIndex)
        {
            // Check row + 1, col + 1

            if (IsSymbolMatch(symbol, workingDataSet[rowIndex + 1][columnIndex + 1]))
            {
                ++numMatched;
            }

            ++rowIndex;
            ++columnIndex;
        }

        if (kNumforMatch == numMatched)
        {
            foundWinner = true;
        }        
    }

    // Search the other diagonal:

    rowIndex = kNumRows - 1;
    columnIndex = 0;
    numMatched = 0;

    if ((false == foundWinner) && (IsSymbolMatch(symbol, workingDataSet[rowIndex][columnIndex])))
    {        
        ++numMatched;

        for (int matchIndex = 1; kNumforMatch > matchIndex;  ++matchIndex)
        {
            // Check row - 1, col + 1

            if (IsSymbolMatch(symbol, workingDataSet[rowIndex - 1][columnIndex + 1]))
            {
                ++numMatched;
            }

            --rowIndex;
            ++columnIndex;
        }

        if (kNumforMatch == numMatched)
        {
            foundWinner = true;
        }
    }

    return foundWinner;
}

int main()
{
    int numInput = 0; 
    scanf("%d\n", &numInput);

    for (int inputIndex = 1; numInput >= inputIndex; ++inputIndex) 
    {
        BuildInput();

        char playingSymbols[] = {'X', 'O'};
        char winner = '0';

        for (int symbolIndex = 0;  NumObjects(playingSymbols) > symbolIndex;  ++symbolIndex)
        {
            if (SeachForWinner(playingSymbols[symbolIndex]))
            {
                winner = playingSymbols[symbolIndex];
                break;
            }
        }

        if ('0' == winner)
        {
            bool gameEnded = (false == IsCharPresent('.'));

            if (gameEnded)
            {
                printf("Case #%d: Draw\n", inputIndex);
            }
            else
            {
                printf("Case #%d: Game has not completed\n", inputIndex);
            }
        }
        else
        {
            printf("Case #%d: %c won\n", inputIndex, winner);
        }
    }
}
