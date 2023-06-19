#include <stdlib.h>
#include <stdio.h>

long int findFactorial(int);
void rowBuilder(int,int);
int inputTester(int);
int main(int argc, char *argv[])
{
    int numRows,i,testInput;
    char *pointer;
    numRows = strtol(argv[argc-1],&pointer,10);
    testInput = inputTester(numRows);
    if(testInput==0)
    {
        printf("Invalid input try again\n");
        return -1;
    }
    else if (argc>2)
    {
        printf("Invalid input try again\n");
        return -1;
    }
    
    /*call the rowbuilding function rowNumber times*/
    else{
    for(i=numRows-1;i>=0;i--)
    {
        rowBuilder(i,numRows);
    }
    return 0;
    }
}
void rowBuilder(int rowNumber, int maxRows)/*this function will make each row separately and printf it too*/
{
    long int rowFact, posFact, pos, rowMinusPos, rowMinusPosFact,result,rowDiff;
    rowFact = findFactorial(rowNumber);
    for(rowDiff = maxRows-rowNumber;rowDiff>0;rowDiff--)
    {
        printf(" ");
    }
    for(pos = rowNumber; pos>=0;pos--)/*The binomial expansion thing is palindromic so entrance end doesn't matter here*/
    {
        rowMinusPos = rowNumber - pos;
        rowMinusPosFact = findFactorial(rowMinusPos);
        if(rowMinusPos==0)/*had issues with this*/
            rowMinusPosFact=1;
        if(pos == 0)
            posFact=1;
        else
            posFact = findFactorial(pos);
        result = rowFact/(posFact*rowMinusPosFact);
        if(result==0)
            result = 1;
        printf("  %ld",result);
    }
    printf("\n");
}
long int findFactorial(int numToFactor)
{
    long int tr = 0;
    long int i = 0;
    for(i = numToFactor;i > 0;i--)
    {
        if(tr==0){
            tr+=i;
        }
        else{
            tr*=i;
        }
    }
    return tr;
}
int inputTester(int bruh)
{
    int i;
    int allowed = 0;
    int accepted[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(i=0;i<20;i++)
    {
        if(bruh==accepted[i])
            allowed=1;
    }
    return allowed;
}