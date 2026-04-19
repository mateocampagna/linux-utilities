#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

// strstr = busca substring dentro de un string
// char* result = strstr("this line has foo in it", "foo");
// result != NULL si encontró "foo"
// result == NULL si no está

// while ((read = getline(&line, &len, f)) != -1) {
// line contiene la línea, incluyendo el '\n'
// }

int grep_file(char* pattern, FILE* file){
    if(!file) return 1;

    char* line = NULL;
    size_t lenght = 0;
    while((getline(&line, &lenght, file)) != -1){
        if(strstr(line, pattern) != NULL){
            printf("%s", line);
        }
    }
    free(line);
    return 0;
}


int main(int argc, char* argv[]){
    if(argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    if(argc == 2){
        grep_file(argv[1], stdin);
    }
    if(argc >= 3){
        // multiples archivos!
        for(int i=2; i<argc; i++){
            FILE* f=fopen(argv[i], "r");
            if(!f){
                printf("wgrep: cannot open file\n");
                return 1;
            }
            grep_file(argv[1], f);
            fclose(f);
        }
    }

    return 0;
}