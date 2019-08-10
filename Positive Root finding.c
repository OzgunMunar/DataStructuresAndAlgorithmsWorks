#include <stdio.h>


int main()
{

    int number;
    float tempNumber;
    short divisor;
    int root;
    int remainder;

    unsigned char numberOfDigits = 1;
    unsigned char i = 0;

    printf("Enter an integer that bigger than 10: ");
    scanf("%d", &number);

    tempNumber = number;

    if(number <= 10)
    {
        printf("Input error...");
        return 0;
    }

    while(tempNumber > 1)
    {

        tempNumber = tempNumber / 10;
        numberOfDigits++;

    }

    while(1)
    {

        i++;
        divisor = (numberOfDigits * numberOfDigits) * i;
        root = (int)(number / divisor);

        if((root * root) < number)
        {

            while(1)
            {

                root++;

                if((root * root) > number)
                {

                    root--;
                    remainder = number - (root * root);

                    if(remainder == 0)
                    {

                        printf("\n\n\tSquare root solution is %d = %d * %d \n\n", number, root, root);

                    }
                    else
                    {

                        printf("\n\n\tClosest square root solution is %d = %d * %d + %d \n\n", number, root, root, remainder);

                    }

                    return 0;

                }

            }

        }

    }

}