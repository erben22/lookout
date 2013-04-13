#include <cstdio>

const unsigned int kBufferSize = 100;
const unsigned int kNumRows = 4;
const unsigned int kNumColumns = 4;

char dataSet[kNumRows][kNumColumns] = {0};

bool IsCharPresent(char searchChar)
{
    bool found = false;

    for (unsigned int rowIndex = 0;  (kNumRows > rowIndex) && (false == found);  ++rowIndex)
    {
        for (unsigned int columnIndex = 0;  kNumColumns > columnIndex;  ++columnIndex)
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

int main()
{
    int numInput= 0; 
    scanf("%d\n", &numInput);

    for (unsigned int inputIndex = 1; numInput >= inputIndex; ++inputIndex) 
    {
        // Build a data set from the current input:

        for (unsigned int rowIndex = 0;  kNumRows > rowIndex;  ++rowIndex)
        {
            static char inputLine[kBufferSize] = {0}; 
            scanf("%s\n", inputLine);

            printf("Input %d is: %s\n", inputIndex, inputLine);

            for (unsigned int columnIndex = 0;  kNumColumns > columnIndex;  ++columnIndex)
            {
                dataSet[rowIndex][columnIndex] = inputLine[columnIndex];
            }
        }


        // Now, operate on the data set.

        bool tiePossible = IsCharPresent('.');

        const unsigned int kMyRow = 2;
        const unsigned int kMyColumn = 1;
        
        printf("Case #%d: entry at [%d][%d], is: \"%c\".  Tie possible: %d\n", inputIndex, 
            kMyRow, kMyColumn, dataSet[kMyRow][kMyColumn], tiePossible);

    }
}


/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char *a = "y qeez ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char *b = "a zooq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main() {
  int tc; scanf("%d\n", &tc);
  for(int tci = 0; tci < tc; tci++) {
    static char str[109]; scanf("%[a-z ]\n", str);
    for(int i = 0; str[i]; i++) {
      str[i] = b[find(a, a+133, str[i])-a];
    }
    printf("Case #%d: %s\n", tci+1, str);
  }
  return 0;
}
*/