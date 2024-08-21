#include "func.h"
#include "Structs.h"
#define TRUE 1
#define INIT 0
#define ONE 1
#define ASCII_ZERO 48
#define ASCII_NINE 57
int main()
{
    int Amount_Of_Users = 2;
    // An array of structs for users' info.
    USER_INFO **Users = (USER_INFO **)malloc(1 * sizeof(USER_INFO *));
    int z = 0;
    while (TRUE)
    {
        char *FirstChoice=NULL; 
        char *In_Check=NULL;
        while (TRUE)
        {
            int len=0;
            printf("-");
            FirstChoice = dyn_str(FirstChoice);
            Check_Input(FirstChoice, &len);
            // A variable for checking input.
            In_Check = (char *)malloc((len + 1) * sizeof(char));
            In_Check = Check_Input(FirstChoice, &len);
            if (strcmp(In_Check, "signup") != 0 && strcmp(In_Check, "login") != 0)
            puts("Please choose between 'signup' and 'login' correctly!Try again:");
            else
            {
                fflush(stdin);
                break;
            }
        }
        // Signup.
        if (strcmp(In_Check, "signup") == 0)
        {
            //flag for wrong inputs!
            int m = 0;
            char *New_username;
            int New_username_Len;
            int up_len;
            char *New_up;
            int uplength;
            char *init_up;
            while (TRUE)
            {

                init_up = strchr(FirstChoice, ' ');
                if(init_up==NULL){
                    puts("Please enter username and password!");
                    m=1;
                    break;
                }
                uplength = strlen(init_up + 1);
                New_up = (char *)malloc((uplength + 1) * sizeof(char));
                strcpy(New_up, init_up + 1);
                up_len = strlen(New_up);
                New_username_Len = TillSpace_Len(New_up);
                New_username = (char *)malloc(New_username_Len * sizeof(char));
                New_username = New_UserName(New_up, New_username_Len);
                int Space_Occurrence = 0;
                    for (int a = 0; FirstChoice[a] != '\0'; a++)
                    {
                        if (FirstChoice[a] == ' ')
                            Space_Occurrence++;
                    }
                    if (Space_Occurrence != 2)
                    {
                        puts("Please pay attention to spaces!");
                        m=1;
                        break;
                    }
                strcpy(New_username, New_UserName(New_up, New_username_Len));
                if (User_existance_up(New_username, Users, Amount_Of_Users) == 1)
                {
                    puts("This username exists!");
                    m = 1;
                    break;
                }
                else
                    break;
            }
            if (m == 1)
                continue;
            ADD_USER(Users, &Amount_Of_Users, New_up, New_username, New_username_Len, up_len);
            // Reallocate the size of array.
            Amount_Of_Users++;
            Users = (USER_INFO **)realloc(Users, (Amount_Of_Users) * sizeof(USER_INFO *));
            puts("Signup successful!\n");
            continue;
        }
        // login
        if (strcmp(In_Check, "login") == 0)
        {
            //flag for wrong inputs!
            int j = 0;
            int len = 0;
            char *User_login;
            char *login_username;
            char *init_usp;
            int uslength;
            int uplength;
            while (TRUE)
            {
                init_usp = strchr(FirstChoice, ' ');
                if(init_usp==NULL){
                    puts("Please enter username and password!");
                    j=1;
                    break;
                }
                uplength = strlen(init_usp + 1);
                User_login = (char *)malloc((uplength + 1) * sizeof(char));
                strcpy(User_login, init_usp + 1);
                uplength = strlen(User_login);
                uslength = TillSpace_Len(User_login);
                login_username = (char *)malloc(uslength * sizeof(char));
                login_username = New_UserName(User_login, uslength);

                if (User_existance_in(User_login, Users, Amount_Of_Users) == 0)
                {
                    puts("There is no user with this information!");
                    j = 1;
                    break;
                }
                else
                {
                    puts("Login successful!\n");
                    break;
                }
            }
            if (j == 1)
                continue;
            while (TRUE)
            {
                char *Menu_Choice;
                printf("->>");
                Menu_Choice = dyn_str(Menu_Choice);
                if ((strchr(Menu_Choice, ' ')) == NULL)
                {
                    // INFO!
                    if (!strcmp(Menu_Choice, "info"))
                    {
                        INFO(Users, login_username);
                        continue;
                    }
                    // LOGOUT!
                    if (!strcmp(Menu_Choice, "logout"))
                    {
                        break;
                    }
                    puts("Please enter a valid input!");
                    continue;
                }
                Check_Input(Menu_Choice, &len);
                // A variable for checking input.
                char *In_Check = (char *)malloc((len + 1) * sizeof(char));
                In_Check = Check_Input(Menu_Choice, &len);
                // POST!
                if (!strcmp(In_Check, "post"))
                {
                    char *init_post = strchr(Menu_Choice, ' ');
                    if(init_post==NULL){
                    puts("Please enter the post!");
                    break;
                }
                    int init_post_len = strlen(init_post + 1);
                    char *post = (char *)malloc((init_post_len + 1) * sizeof(char));
                    strcpy(post, init_post + 1);
                    int post_len = strlen(post);
                    // status for post.
                    int status;
                    status = New_Post(Users, User_login, login_username, post, post_len, uslength, uplength);
                    if (status == 1)
                        puts("Post successfuly added!");
                    else
                        puts("Post adding failed!");
                }
                // LIKE!
                if (!strcmp(In_Check, "like"))
                {
                    int Space_Occurrence = 0;
                    for (int a = 0; Menu_Choice[a] != '\0'; a++)
                    {
                        if (Menu_Choice[a] == ' ')
                            Space_Occurrence++;
                    }
                    if (Space_Occurrence != 2)
                    {
                        puts("There is not such an ID or username");
                        continue;
                    }
                    char *init_like = strchr(Menu_Choice, ' ');
                    int init_like_len = strlen(init_like + 1);
                    char *like = (char *)malloc((init_like_len + 1) * sizeof(char));
                    strcpy(like, init_like + 1);
                    int like_len = strlen(like);
                    int User_Len = TillSpace_Len(like);
                    char *like_Username = (char *)malloc(User_Len * sizeof(char));
                    like_Username = New_UserName(like, User_Len);
                    if (User_existance_up(like_Username, Users, Amount_Of_Users) == 0)
                    {
                        puts("There is no user with this information!");
                        continue;
                    }
                    // For wrong situations!
                    int flag = 0;
                    char *init_ID = strchr(like, ' ');
                    int init_ID_len = strlen(init_ID + 1);
                    char *ID = (char *)malloc((init_ID_len + 1) * sizeof(char));
                    strcpy(ID, init_ID + 1);
                    for (int n = 0; ID[n] != '\0'; n++)
                    {
                        if ((ID[n] < ASCII_ZERO) || (ID[n] > ASCII_NINE))
                        {
                            puts("Only use numbers for post id");
                            flag = 1;
                            break;
                        }
                    }
                    if (flag)
                        continue;
                    int Post_ID = atoi(ID);
                    if (!Post_ID)
                    {
                        puts("Wrong Post ID!");
                        continue;
                    }
                    int Status = 1;
                    if ((Status = LIKE(Users, Post_ID, like_Username)) == 0)
                    {
                        puts("There is no post with this ID");
                        continue;
                    }
                    else
                        puts("Post liked!");
                }
                // DELETE!
                if (!strcmp(In_Check, "delete"))
                {
                    int Space_Occurrence = 0;
                    for (int a = 0; Menu_Choice[a] != '\0'; a++)
                    {
                        if (Menu_Choice[a] == ' ')
                            Space_Occurrence++;
                    }
                    if (Space_Occurrence != 1)
                    {
                        puts("Please pay attention to your input!");
                        continue;
                    }
                    // For wrong situations!
                    int flag = 0;
                    char *init_delete = strchr(Menu_Choice, ' ');
                    int init_delete_len = strlen(init_delete + 1);
                    char *Dpost = (char *)malloc((init_delete_len + 1) * sizeof(char));
                    strcpy(Dpost, init_delete + 1);
                    for (int n = 0; Dpost[n] != '\0'; n++)
                    {
                        if ((Dpost[n] < ASCII_ZERO) || (Dpost[n] > ASCII_NINE))
                        {
                            puts("Only use numbers for post id");
                            flag = 1;
                            break;
                        }
                    }
                    if (flag)
                        continue;
                    int DpostID = atoi(Dpost);
                    int Status = 1;
                    if ((Status = Delete_Post(Users, login_username, DpostID)) == 0)
                    {
                        puts("There is no post with this ID!");
                        continue;
                    }
                    else
                    {
                        puts("Post deleted successfully!");
                        continue;
                    }
                }
                // FIND_USER!
                if (!strcmp(In_Check, "find_user"))
                {
                    int Space_Occurrence = 0;
                    for (int a = 0; Menu_Choice[a] != '\0'; a++)
                    {
                        if (Menu_Choice[a] == ' ')
                            Space_Occurrence++;
                    }
                    if (Space_Occurrence != 1)
                    {
                        puts("Please pay attention to your input!");
                        continue;
                    }
                    char *init_fuser = strchr(Menu_Choice, ' ');
                    int init_fuser_len = strlen(init_fuser + 1);
                    char *fuser = (char *)malloc((init_fuser_len + 1) * sizeof(char));
                    strcpy(fuser, init_fuser + 1);
                    if (!User_existance_up(fuser, Users, Amount_Of_Users))
                    {
                        puts("There is no user with this username!");
                        continue;
                    }
                    FIND_USER(Users, fuser);
                }
                // WRONG INPUT!
                if ((strcmp(In_Check, "post") != 0) && (strcmp(In_Check, "like") != 0) && (strcmp(In_Check, "delete") != 0) && (strcmp(In_Check, "find_user") != 0))
                {
                    puts("Please enter a valid input!");
                    continue;
                }
            }
            continue;
        }

        return 0;
    }
}