#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define INIT 0
#define ONE 1
typedef struct USER_INFO USER_INFO;
struct USER_INFO
{
    char *User_Pass;
    char *Username;
    char *post;
    int post_ID;
    int like;
    USER_INFO *next;
};
USER_INFO *dummyNode()
{
    USER_INFO *head = (USER_INFO *)malloc(sizeof(USER_INFO));
    head->next = NULL;
    return head;
}
int User_existance_up(char *New_username, USER_INFO **Users, int Amount_Of_Users)
{
    int i = INIT;
    for (i = INIT; i < (Amount_Of_Users - 2); i++)
    {
        if (strcmp(((Users[i]->next)->Username), New_username) == INIT)
            return 1;
    }
    return 0;
}
int User_existance_in(char *User_login, USER_INFO **Users, int Amount_Of_Users)
{
    int i = INIT;
    for (i = INIT; i < (Amount_Of_Users - 2); i++)
    {
        if (strcmp(((Users[i]->next)->User_Pass), User_login) == INIT)
            return 1;
    }
    return 0;
}
// The User index in array.
int FindUserPassIndex(char *User_login, USER_INFO **Users)
{
    int i = INIT;
    for (i;; i++)
    {
        if (strcmp(((Users[i]->next)->User_Pass), User_login) == INIT)
            return i;
    }
}


int FindUsernameIndex(char *Username, USER_INFO **Users)
{
    int i = INIT;
    for (i;; i++)
    {
        if (strcmp(((Users[i]->next)->Username), Username) == INIT)
            return i;
    }
}
USER_INFO *Next_Post(USER_INFO *cur, char *User_login, char *login_username, int usernameSize, int userpassSize, int last_PostID)
{
    cur->next = (USER_INFO *)malloc(sizeof(USER_INFO));
    (cur->next)->User_Pass = (char *)malloc((userpassSize + 1) * sizeof(char));
    (cur->next)->Username = (char *)malloc((usernameSize + 1) * sizeof(char));
    strcpy((cur->next)->User_Pass, User_login);
    strcpy((cur->next)->Username, login_username);
    (cur->next)->post = NULL;
    (cur->next)->next = NULL;
    (cur->next)->like = 0;
    (cur->next)->post_ID = last_PostID + 1;
    return cur->next;
}
int New_Post(USER_INFO **Users, char *User_login, char *login_username, char *post, int post_len, int usernameSize, int userpassSize)
{
    int i = FindUserPassIndex(User_login, Users);
    USER_INFO *prev = Users[i];
    USER_INFO *cur = Users[i]->next;
    // For the first post.
    if (cur->post == NULL)
    {
        // strlen don't count NULL char.(+1)
        cur->post = (char *)malloc((post_len + ONE) * sizeof(char));
        strcpy(cur->post, post);
        cur->post_ID = 1;
        // sakhtane jaye poste baadi.
        cur->next = (USER_INFO *)malloc(sizeof(USER_INFO));
        (cur->next)->User_Pass = (char *)malloc((userpassSize + 1) * sizeof(char));
        (cur->next)->Username = (char *)malloc((usernameSize + 1) * sizeof(char));
        strcpy((cur->next)->User_Pass, User_login);
        strcpy((cur->next)->Username, login_username);
        (cur->next)->post = NULL;
        (cur->next)->next = NULL;
        (cur->next)->like = 0;
        (cur->next)->post_ID = 2;
        return 1;
    }
    else
    {
        while (cur->post != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        cur->post = (char *)malloc((post_len + 1) * sizeof(char));
        strcpy(cur->post, post);
        cur->post_ID = (prev->post_ID) + 1;
        cur->next = Next_Post(cur, User_login, login_username, usernameSize, userpassSize, cur->post_ID);
        return 1;
    }
    return 0;
}
int LIKE(USER_INFO **Users, int POST_ID, char *like_Username)
{
    int index = FindUsernameIndex(like_Username, Users);
    USER_INFO *cur = Users[index]->next;
    while (cur->post != NULL)
    {
        if (cur->post_ID == POST_ID)
        {
            cur->like = (cur->like) + 1;
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}
void INFO(USER_INFO **Users, char *login_username)
{
    int index = FindUsernameIndex(login_username, Users);
    USER_INFO *cur = Users[index]->next;
    char *init_pass = strchr(cur->User_Pass, ' ');
    int init_pass_len = strlen(init_pass + ONE);
    char *pass = (char *)malloc((init_pass_len + ONE) * sizeof(char));
    strcpy(pass, init_pass + ONE);
    printf("Username:%s\n", cur->Username);
    printf("Password:%s\n", cur->User_Pass);
    if (cur->post == NULL)
    {
        puts("You haven't post anything yet!");
        puts("");
        return;
    }
    while (cur->post != NULL)
    {
        printf("user:%s\n", cur->Username);
        printf("post_id:%d\n", cur->post_ID);
        printf("like:%d\n", cur->like);
        printf("post:%s\n", cur->post);
        puts("----------------------");
        cur = cur->next;
    }
    return;
}
void FIND_USER(USER_INFO **Users, char *fuser)
{
    int index = FindUsernameIndex(fuser, Users);
    USER_INFO *cur = Users[index]->next;
    if (cur->post == NULL)
    {
        puts("This user haven't post anything yet!");
        puts("");
        return;
    }
    while (cur->post != NULL)
    {
        printf("user:%s\n", cur->Username);
        printf("post_id:%d\n", cur->post_ID);
        printf("like:%d\n", cur->like);
        printf("post:%s\n", cur->post);
        puts("----------------------");
        cur = cur->next;
    }
    return;
}

USER_INFO **ADD_USER(USER_INFO **Users, int *Amount_Of_Users, char *New_UsernPass, char *New_username, int usernameSize, int userpassSize)
{
    USER_INFO *head = dummyNode();
    USER_INFO *NewUser = (USER_INFO *)malloc(sizeof(USER_INFO));
    NewUser->User_Pass = (char *)malloc((userpassSize + ONE) * sizeof(char));
    NewUser->Username = (char *)malloc((usernameSize + ONE) * sizeof(char));
    strcpy(NewUser->User_Pass, New_UsernPass);
    strcpy(NewUser->Username, New_username);
    NewUser->post = NULL;
    NewUser->next = NULL;
    NewUser->like = INIT;
    // At first it has 0 for ID,when it fills with post,it will become 1 in New_Post function.
    NewUser->post_ID = INIT;
    // (-2) because index starts from 0 and Amount_Of_Users starts from 2.
    Users[(*Amount_Of_Users) - 2] = head;
    head->next = NewUser;
    return Users;
}
int Delete_Post(USER_INFO **Users, char *login_username, int DpostID)
{
    int index = FindUsernameIndex(login_username, Users);
    USER_INFO *prev = Users[index];
    USER_INFO *cur = Users[index]->next;
    while ((cur->post != NULL) && (cur->post_ID != DpostID))
    {
        prev = cur;
        cur = cur->next;
    }
    // No post with this ID found!
    if (cur->post == NULL)
        return 0;
    if ((cur->post_ID != DpostID))
        return 0;
    // Delete post.
    prev->next = cur->next;
    free(cur);
    return 1;
}
