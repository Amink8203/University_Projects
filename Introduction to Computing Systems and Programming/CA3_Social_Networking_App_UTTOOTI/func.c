#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define INIT 0
#define ONE 1
char *dyn_str(char *str_input)
{
    int i = 0;
    while (TRUE)
    {
        // allocating a space for str.
        if (i == INIT)
            str_input = (char *)malloc(i + ONE);
        // reallocate the size after getting every character by 1.
        else
            str_input = (char *)realloc((str_input), i + ONE);
        // Get every char with getchar one by one.
        (str_input)[i] = getchar();
        // If we encouter new line or end of file,the string ends.
        if ((str_input)[i] == '\n' || (str_input)[i] == EOF)
        {
            (str_input)[i] = '\0';
            break;
        }
        i++;
    }
    return str_input;
}
int TillSpace_Len(char *str_input)
{
    int i = 0;
    while (str_input[i] != ' ')
    {
        i++;
    }
    return i;
}
char *Check_Input(char *Menu_Choice, int *len)
{
    *len = TillSpace_Len(Menu_Choice);
    char *temp = (char *)malloc((*len + 1) * sizeof(char));
    strncpy(temp, Menu_Choice, (*len));
    *(temp + (*len)) = '\0';
    return temp;
}
char *New_UserName(char *str_input, int length)
{
    int i = 0;
    char *username = (char *)malloc(length * sizeof(char));
    for (i = 0; i < length; i++)
        username[i] = str_input[i];
    // Note that the last character must be NULL otherwise the program will crash!!
    username[i] = '\0';
    return username;
}
int Post_ID(char *like, int like_len, int username_len)
{
    char *postID = (char *)malloc((like_len - username_len) * sizeof(char));
    if (like[username_len] == ' ')
    {
        puts("You must use only 1 space between username and post_ID");
        return 0;
    }
    int i, j = 0;
    for (i = username_len + 1, j; i < like_len; i++, j++)
        postID[j] = like[i];
    // Note that the last character must be NULL otherwise the program will crash!!
    postID[j] = '\0';
    int ID = atoi(postID);
    return ID;
}