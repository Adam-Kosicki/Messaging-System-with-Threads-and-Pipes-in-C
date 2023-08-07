#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXLEN 1024

FILE *finput, *foutput; // File pointers for input and output files
char *argv1; // Stores the command-line argument for read-pipe

// Function executed by the thread to read from a pipe and print its contents
void *pipe_read_thread(void *ptr) {
	char temp[MAXLEN];
	finput = fopen(argv1, "r"); // Open the specified read-pipe
	while (fgets(temp, MAXLEN, finput)) // Read line by line from the file
		puts(temp); // Print each line
}

int main(int argc, char *argv[]) {
	if (argc != 3) { // Check if the correct number of command-line arguments is provided
		fprintf(stderr, "Usage: messenger <read-pipe> <write-pipe>");
		exit(1);
	}
	
	argv1 = argv[1]; // Store the read-pipe filename from the command-line argument
	
	pthread_t thread1; // Thread variable
	
	// Create a thread to read from the read-pipe
	if (pthread_create(&thread1, NULL, pipe_read_thread, NULL)) {
		fputs("Cannot create thread.\n", stderr);
		exit(1);
	}
	
	foutput = fopen(argv[2], "w"); // Open the specified write-pipe for output
	
	char buffer[MAXLEN]; // Buffer to store input data
	
	// Read from standard input and write to the write-pipe
	while (fgets(buffer, MAXLEN, stdin)) {
		fputs(buffer, foutput); // Write data to the write-pipe
		fflush(foutput); // Flush the output stream
	}
}
