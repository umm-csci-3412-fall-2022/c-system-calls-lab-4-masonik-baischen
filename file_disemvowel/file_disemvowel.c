#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
	char* vowels = calloc(11, sizeof(char));
	strcpy(vowels, "aeiouAEOIOU\0");
	return strchr(vowels, c);
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */

	int num_non_vowels = 0;
	for (int i = 0; i < num_chars; i++){
		if (is_vowel(in_buf[i]) == 0){
			out_buf[num_non_vowels] = in_buf[i];
			num_non_vowels++;
		}
	}
	return num_non_vowels;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
	FILE *input;
	FILE *output;
	input = inputFile;
	output = outputFile;
	int c;
	int counter = 0;
	char in_buf[BUF_SIZE];
	char out_buf[BUF_SIZE];
	while(counter < BUF_SIZE) {
		c = fgetc(input);
		if (c == EOF){
			int output_length = copy_non_vowels(counter, in_buf, out_buf);
                        for (int i = 0; i < output_length; i++){
                                fputc(out_buf[i], output);
                        }
                        counter = BUF_SIZE;
		}
		else {
		in_buf[counter] = (char) c;
		counter++;
			if (counter == BUF_SIZE - 1){
				int output_length = copy_non_vowels(counter, in_buf, out_buf);
				for (int i = 0; i < output_length; i++){
					fputc(out_buf[i], output);
				}
				counter = 0;
			}
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
	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w+");
    }
    else if(argc == 2) {
	inputFile = fopen(argv[1], "r");
    }
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.
    
    disemvowel(inputFile, outputFile);

    return 0;
}
