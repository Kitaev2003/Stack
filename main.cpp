#include "Stack_Lib.h"

int main()
{
    LOG_FILE = fopen("log.txt", "w");

    Check_Open_File(LOG_FILE);

    Stack_Struct stk = {};

    stk.capacity = 10;

    Stack_Order(&stk);

    int val = 0;

    scanf("%d", &val);

    while(val!= 303)
    {
        Stack_Push(&stk, val);
        scanf("%d", &val);
    }

    Print_In_File_Protect(stk);

    Stack_Print(&stk);

    Stack_Free(&stk);

    return 0;
}
