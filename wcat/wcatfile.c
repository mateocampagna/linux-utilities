#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int show_file(char* name_file, FILE* out_file){
    FILE* f=fopen(name_file, "r");
    if(f==NULL){
        printf("wcatfile: cannot open file%s\n", name_file);
        return 1;
    }

    int ch; 
    while((ch=fgetc(f)) != EOF){
        putchar(ch);
        if(out_file != NULL){
            fputc(ch, out_file);
        }
    }

    fclose(f);
    return 0;
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        printf("Usage: %s file1 [file2 ...] [- output]\n", argv[0]);
        return 1;
    }
    
    // buscar el indice 
    int sep= -1;
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i],"-") == 0){
            sep=i;
            break;
        }
    }

    // validar que haya cosas despues del - 
    if(sep != -1 && sep+1 >= argc){
        printf("Destination file is needed.");
        return 1;
    }

    // crear archivo
    FILE* file=NULL;
    if(sep!= -1){
        file = fopen(argv[sep+1], "w");
        // si falle en abrir por alguna rzon
        if(file == NULL){
            printf("wcatfile: cannot open output file %s\n", argv[sep+1]);
            return 1;
        }
    }

    int end=(sep != -1) ? sep : argc; 
    for(int i=1; i<end; i++){
        show_file(argv[i], file);
    }

    if(file != NULL) fclose(file);
    return 0;
}