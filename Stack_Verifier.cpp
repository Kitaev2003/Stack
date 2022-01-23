FILE* LOG_FILE = 0;

void Check_Open_File(FILE* file)
{
	if (file == NULL)
	{
		printf("<=====================>ERROR OPENING FILE<=====================>\n\n");
		printf("<============>CHECK THE AVAILABILITY OF YOUR FILE<=============>");
		exit(ERROR_PTR);
	}
}

void Stack_Dump(int result)
{
    switch (result)
    {
        case  1:
            fprintf(LOG_FILE, "Error: The stack is completely empty \n");
            break;

        case 2:
            fprintf(LOG_FILE, "Error: Damage to the beginning of the stack \n");
            break;

        case 3:
            fprintf(LOG_FILE, "Error: Damage to the end of the stack \n");
            break;

        case 4:
            fprintf(LOG_FILE, "Error: Damage to the beginning of the array \n");
            break;

        case 5:
            fprintf(LOG_FILE, "Error: Damage to the end of the array \n");
            break;

        case 6:
            fprintf(LOG_FILE, "Error: Problems with array length \n\n");
            break;

        default:
            fprintf(LOG_FILE, "Error: NO ERRORS \n");
    }
}

void Check_Protect(Stack_Struct* stk)
{
     int result = 0;

     if (stk == NULL)
     {
        result = NULL_STACK;

        Stack_Dump(result);

        exit(0);
     }

     else if (stk->data == NULL)
     {
        result = NULL_DATA;

        Stack_Dump(result);

        exit(0);
     }

     else if (stk->protect_begin != STACK_PTR)
     {
        result = PTR_STACK_1;

        Stack_Dump(result);

        exit(0);
     }

     else if (stk->protect_end != STACK_PTR)
     {
        result = PTR_STACK_2;

        Stack_Dump(result);

        exit(0);
     }

     else if (stk -> data[0] != DATA_PTR)
     {
        result = PTR_DATA_1;

        Stack_Dump(result);

        exit(0);
     }

     else if (stk -> data[stk->capacity+PROTECTION_CELL] != DATA_PTR)
     {
        result = PTR_DATA_2;

        Stack_Dump(result);

        exit(0);
     }

     else if ((stk -> size > stk -> capacity + 1) || (stk -> size < 0))
     {
        result = STACK_OVERFLOW;

        Stack_Dump(result);

        exit(0);
     }
}

void Print_In_File_Protect(Stack_Struct stk)
{
	fprintf(LOG_FILE, "Protecting the beginning of the array: %X\n", stk.data[0]);

	fprintf(LOG_FILE, "Protecting the end of the array: %X\n", stk.data[stk.capacity+PROTECTION_CELL]);

	fprintf(LOG_FILE, "Protecting the beginning of the stack: %X\n", stk.protect_begin);

	fprintf(LOG_FILE, "Protecting the end of the stack: %X\n", stk.protect_end);
}
