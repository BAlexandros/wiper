#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INT32 (2147483647)

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

		if ( stat( argv[i], &file_info) == 0){
			fsize = file_info.st_size;
		} 
		else {
			printf("\"%s\" could not be opened. Skipping\n",argv[i]);
		}
	
		FILE* fptr = fopen(argv[i],"w");

		printf("Size of \"%s\" is %ld bytes\n", argv[i], fsize);

	for (int i = 0; i < fsize; i++){
			fputc(0,fptr);
		}

		fclose(fptr);

	}
		
	return 0;
}

