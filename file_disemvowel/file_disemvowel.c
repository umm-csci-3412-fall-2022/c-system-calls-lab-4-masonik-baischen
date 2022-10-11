#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
	char* vowels = calloc(11, sizeof(char));
	strcopy(vowels, "aeiouAEOIOU\0");
	return strchr(vowels, c);
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
	FILE *input;
	input = fopen(inputFile, "r");
	output = fopen(outputFile, "r+");
	int c;
	int counter = 0;
	char* in_buf[BUF_SIZE];
	char* out_buf[BUF_SIZE];
	while(counter < BUF_SIZE) {
		c = fgetc(input);
		in_buf[counter] = (char) c;
		counter++;
		if (counter == BUF_SIZE - 1 || c == EOF){
			int output_length = copy_non_vowels(counter, in_buf, out_buf);
			for (int i = 0; i < output_length; i++){
				fputc(out_buf[i], outputFile);
			}
			counter = 0;
		}
	}


}

int main(int argc, char *argv[]) {
    // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;
    
    if(argc == 3) {
	inputFile = argv[1];
	outputFile = argv[2];
    }
    else if(argc == 2) {
	inputFile = argv[1];
    }
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.
    
    disemvowel(inputFile, outputFile);

    return 0;
}
