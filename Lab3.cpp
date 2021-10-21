#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *shortOptions = "hvi:";

    static struct option longOptions[] = {
        {"help",    no_argument,       0, 'h'}, 
        {"version", no_argument,       0, 'v'},
        {"input",    required_argument, 0, 'i'},
        {0, 0, 0, 0},
    };

    const char *helpOption = "Program options:\n"
    "-h or --help                          - messages with program options\n"
    "-v or --version                       - current version of file\n"
    "-i[<val1>,...]                        - values\n";
    

    bool h, v, i = false;
    
    int index, code;

    while ((code = getopt_long(argc, argv, shortOptions, longOptions, &index)) != -1) {
        switch (code) {
            case 'h': {
                if (!h) {
                    h = true;
                    printf("%s\n", helpOption);
                }
                break;
            }
            case 'i': {
                if (!i) {
                    char *args;
                    printf("Option list:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    i = true;
                }
                break;
            }
            case 'v': {
                if (!v) {
                    v = true;
                    printf("Current version\n");
                }
                break;
            }
            default: {
                printf("Mistake!\n");
                return 0;
            }
        }
    }
    return 0;
}
