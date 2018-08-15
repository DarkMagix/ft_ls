#include "ft_ls.h"

void listFiles(char *b_path)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir;
    struct stat buf;
    dir = opendir(b_path);
    if (!dir)
    {
       
        return ;
    }
    while((dp = readdir(dir))!= NULL)
    {   
        if (ft_strcmp(dp->d_name, ".") != 0 && ft_strcmp(dp->d_name, "..")!=0)
        {
            ft_strcpy(path, b_path);
            ft_strcat(path, "/");
            ft_strcat(path, dp->d_name);
            stat(path, &buf);
            if(S_ISDIR(buf.st_mode)) 
            {
                printf("\n%s/ \n", path);
            }
            listFiles(path);
            if(S_ISREG(buf.st_mode))
                printf("%s", dp->d_name);
            printf("\n");
        }
    }
    closedir(dir);
}
int main(int argc, char *argv[]) {
    int a;
    for(a = 1; a < argc; a ++) {
        struct stat buf;
        stat(argv[a], &buf);
        if(S_ISDIR(buf.st_mode)) 
        {
            listFiles(argv[a]);
        }
        //     printf("%-20s -- is a directory\n", argv[a]);
        // }
        // else {
        //     printf("%-20s -- is not a directory\n", argv[a]);
        // }
    }
    return 0;
}