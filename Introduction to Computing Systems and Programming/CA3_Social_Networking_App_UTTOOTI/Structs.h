#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
USER_INFO *dummyNode();
int User_existance_up(char *New_username, USER_INFO **Users, int Amount_Of_Users);
int User_existance_in(char *User_login, USER_INFO **Users, int Amount_Of_Users);
int FindUserPassIndex(char *User_login, USER_INFO **Users);
int FindUsernameIndex(char *Username, USER_INFO **Users);
USER_INFO *Next_Post(USER_INFO *cur, char *User_login, char *login_username, int usernameSize, int userpassSize, int last_PostID);
int New_Post(USER_INFO **Users, char *User_login, char *login_username, char *post, int post_len, int usernameSize, int userpassSize);
int LIKE(USER_INFO **Users, int POST_ID, char *like_Username);
void INFO(USER_INFO **Users, char *login_username);
void FIND_USER(USER_INFO **Users, char *fuser);
USER_INFO **ADD_USER(USER_INFO **Users, int *Amount_Of_Users, char *New_UsernPass, char *New_username, int usernameSize, int userpassSize);
int Delete_Post(USER_INFO **Users, char *login_username, int DpostID);
