#include <stdio.h>

int main(int argc, char *argv[])
{

	if (argc == 1 ){
		printf("You have not entered any arguments. Exiting\n");
		return -1;
	}

	for (int i = 1; i < argc; i++){

		FILE* fptr = fopen(argv[i],"r+");

		if (fptr == NULL){
			printf("\"%s\" could not be opened. Skipping\n",argv[i]);
			continue;
		}

		int fsize = 0;
		
		fseek(fptr,0, SEEK_END);
		fsize = ftell(fptr);
		fseek(fptr,0, SEEK_SET);

		printf("Size of \"%s\" is %d bytes\n", argv[i], fsize);
		
		for (int i = 0; i < fsize; i++){
			fputc('0',fptr);
		}

		fclose(fptr);

	}
		
	return 0;
}

