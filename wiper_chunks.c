#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INT32 (2147483647)
#define CHUNK_SIZE (4)

int main(int argc, char *argv[])
{

	// Check if input file is given before starting, exit if no input
	if (argc == 1 ){
		fprintf(stderr,"You have not entered any arguments. Exiting\n");
		return -1;
	}

	// Iterate over all input files
	for (int i = 1; i < argc; i++){

		struct stat file_info;
		off_t fsize = 0;
		char buffer[CHUNK_SIZE] = {0};
		size_t chunk_number = 0;
		size_t chunk_remainder = 0;

		if ( stat( argv[i], &file_info) == 0){
			fsize = file_info.st_size;
			chunk_number = fsize / CHUNK_SIZE;
			chunk_remainder = fsize % CHUNK_SIZE;
		} 
		else {
			printf("\"%s\" could not be opened. Skipping\n",argv[i]);
		}
	
		FILE* fptr = fopen(argv[i],"w");

		printf("Size of \"%s\" is %ld bytes\n", argv[i], fsize);
		printf("%ld chunks of %d bytes, and %ld remaining \n",chunk_number,CHUNK_SIZE,chunk_remainder);

		for (size_t i = 0; i < chunk_number; i++){
			fwrite(buffer,sizeof(char),CHUNK_SIZE,fptr);
		}
		for (size_t i = 0; i < chunk_remainder; i++){
			putc(0,fptr);
		}

		fclose(fptr);

	}
		
	return 0;
}

