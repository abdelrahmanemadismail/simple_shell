#include "shell.h"

char which(char *token){
    char *pth, *cpy, *path_token, *file_path;
    int tkn_len, dir_len;
    struct stat buffer;

    pth = getenv("PATH");

    if (pth){
        cpy = strdup(pth);
        tkn_len = strlen(token);
        path_token = strtok(cpy, ":");

        while(path_token != NULL){
            dir_len = strlen(path_token);
            file_path = malloc(tkn_len + dir_len + 2); 
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, token);
            strcat(file_path, "\0");
            
            if (stat(file_path, &buffer) == 0){
            
                free(cpy);

                return (file_path);
            }
            
            else{
                    
                free(file_path);
                path_token = strtok(NULL, ":");

            }

        }

        
        free(cpy);

        if (stat(token, &buffer) == 0)
        {
            return (token);
        }


        return (NULL);

    }


    return (NULL);
}

