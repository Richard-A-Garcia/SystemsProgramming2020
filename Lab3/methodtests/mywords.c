/*
	example of command line parsing via getopt
	usage: getopt [-dmp] -f fname [-s sname] name [name ...]

	Paul Krzyzanowski
*/

#include <stdio.h>
#include <stdlib.h>

int debug = 0;	
int main(int argc, char **argv)
{
	
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int cflag=0, sflag=0, fflag = 0;
	char *sname = "default_sname", *fname;
	static char usage[] = "usage: %s [-cs] [-f substring] filename\n";	 
	char ch;
	FILE *filePointer;
	

	while ((c = getopt(argc, argv, "csf:")) != -1)
		switch (c) {
		case 'c':
			debug = 1;
			cflag = 1;
			break;
		case 's':
			sflag = 1;
			break;
		case 'f':
			fflag = 1;
			break;
		case '?':
			err = 1;
			break;
		}
	if (fflag == 0) {	/* -f was mandatory */
		fprintf(stderr, "%s: missing -f option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		//exit(1);
	} else if ((optind+1) > argc) {	
		/* need at least one argument (change +1 to +2 for two, etc. as needeed) */

		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing name\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	/* see what we have REMOVE LATER */
	printf("cflag = %d\n", cflag);
	printf("sflag = %d\n", sflag);
	printf("fflag = %d\n", fflag);
	
 	
	//This block of code prints the contents of the file 
	printf("File Name: %s\n", argv[optind]);
	filePointer = fopen(argv[optind], "r");
	if (filePointer == NULL)
   	{
      		printf("Error while opening the file.\n");
      		exit(-1);
   	}
	printf("File text is : \n");
  	 while((ch = fgetc(filePointer)) != EOF)
      		printf("%c", ch);
	
	//code to call wordCount function
//	if(cflag == 1){
	
   	fclose(filePointer);
	
//	if (optind < argc)	/* these are the arguments after the command-line options */
//		for (; optind < argc; optind++)
//			printf("argument: \"%s\"\n", argv[optind]);
//	else {
//		printf("no arguments left to process\n");
//	}

	exit(0);
}
