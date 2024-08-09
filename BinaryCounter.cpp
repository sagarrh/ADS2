#include <stdio.h>
 
int main()
{
    int binary[] = {0, 0, 0, 0};
    int actual, amort, credits = 0;
    int n = 16;
 
    for (int count = 1; count <= n; count++)
    {
        actual = 0;
        amort = 0;
        for (int i = 0; i < 4; i++)
        {
            if (binary[i] == 0)
            {
                binary[i] = 1;
                actual++;
                amort += 2;
                break;
            }
            else
            {
                binary[i] = 0;
                actual++;
            }
        }
 
        credits += amort - actual;
        printf("Count: %2d | Binary: ", count);
        for (int i = 3; i >= 0; i--)
        {
            printf("%d", binary[i]);
        }
        printf(" | Actual: %d | Amortized: %d | Credits: %d\n", actual, amort, credits);
    }
}