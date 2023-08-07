#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXLEN 1024

FILE *finput, *foutput;

char *argv1;

void *pipe_read_thread(void *ptr) {
	char temp[MAXLEN];
	finput = fopen(argv1, "r");
	while (fgets(temp, MAXLEN, finput))
			puts(temp);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: messenger <read-pipe> <write-pipe>");
		exit(1);
	}
	
	argv1 = argv[1];
	
	pthread_t thread1;
	if (pthread_create(&thread1, NULL, pipe_read_thread, NULL)) {
		fputs("Cannot create thread.\n", stderr);
		exit(1);
	}
	
	foutput = fopen(argv[2], "w");
	
	char buffer[MAXLEN];
	
	while (fgets(buffer, MAXLEN, stdin)) {
		fputs(buffer, foutput);
		fflush(foutput);
	}
}
