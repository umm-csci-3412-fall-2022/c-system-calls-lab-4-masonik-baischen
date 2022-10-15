#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int numd, numr = 0;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    // Define stuff here
    if (typeflag == 0){
    	numr++;
    }
    else if (typeflag == 1){
    	numd++;
    }
    return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check arguments and set things up

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    printf("There were %d directories.\n", numd);
    printf("There were %d regular files.\n", numr);

    // Print out the results
}
