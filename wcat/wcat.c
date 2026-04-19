#include <stdio.h> //la std para i/o incluye files
#include <stdlib.h> // para exit()

int show_file(char* name_file){
    FILE* f=fopen(name_file, "r");
    if(f==NULL){
        printf("wcat: cannot open file\n");
        return 1;
    }

    int character;
    while((character = fgetc(f)) != EOF){
        putchar(character);
    }

    fclose(f);
    return 0;
}

int main(int argc, char *argv[]){
    // argc = total arguments (like size(argv))
    // arvg[0] = ./program
    // argv[1] = argument 1
    // argv[2] = argument 2
    // argv[N-1] = argument N-1
    // argv[N] = NULL

    int error=0; 
    if(argc > 1){
        for(int i=1; i<argc; i++){
            if(show_file(argv[i]) == 1){
                error=1;
                break;
            }
        }
    }
    return error;
}