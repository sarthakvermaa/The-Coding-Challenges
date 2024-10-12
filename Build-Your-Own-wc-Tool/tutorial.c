#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>

#define KNRM  "\x1B[0m"    // Reset to default
#define KRED  "\x1B[31m"   // Red
#define KGRN  "\x1B[32m"   // Green
#define KYEL  "\x1B[33m"   // Yellow
#define KBLU  "\x1B[34m"   // Blue
#define KMAG  "\x1B[35m"   // Magenta
#define KCYN  "\x1B[36m"   // Cyan
#define KWHT  "\x1B[37m"   // White

// Additional bold and background colors:
#define BOLD  "\x1B[1m"    // Bold
#define UNDERLINE  "\x1B[4m"   // Underline

// Background colors:
#define BGRED  "\x1B[41m"   // Background Red
#define BGBLU  "\x1B[44m"   // Background Blue
#define BGNORM  "\x1B[49m"  // Default background


// c == count (argc)
// v == vector (argv)
int main(int argc, char **argv){
    // printf("you typed %s %s\n", argv[0], argv[1]);

    if(argc < 2){
        printf("%sGive a filename%s\n", KYEL, KNRM);
        return 1;
    }

    if(access(argv[1], F_OK) == -1){
        printf("%sError:%s file does not exist\n", KRED, KNRM);
        return 2;
    }

    struct stat st;
    stat(argv[1], &st);
    
    struct passwd *pw = getpwuid(st.st_uid);
    printf("%sFile %s has owner %s%s\n", KGRN, argv[1], pw->pw_name, KNRM);

    // printf("file is %s\n", argv[1]);
    return 0;
}

// YT link: https://www.youtube.com/watch?v=cNBrsrvxeQg
