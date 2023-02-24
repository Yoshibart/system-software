#include <stdio.h>

int main() {
    char string[10] = "barnet";
    
    printf("%s", string);
    FILE *fp;
    int status;
    char path[1024];

    fp = popen(write(fd[1], string, (strlen(string)+1)), "r");

    while (fgets(path, 1024, fp) != NULL)
        printf("%s", path);

    status = pclose(fp);
}
