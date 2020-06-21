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
	FILE *wordCountPointer;
	int wordcount;
	typedef enum {false, true} bool;
	bool isWord = false;

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
	printf("File Text is : \n");
	while((ch = fgetc(filePointer)) != EOF){
      		printf("%c", ch);

	}
	fclose(filePointer);
	//This Portion of the code counts the words in the file
	wordCountPointer = fopen(argv[optind], "r");
	if (filePointer == NULL)
   	{
      		printf("File does not exist\n");
      		exit(-1);
   	}
	
	char currentWord[50];
	while(fscanf(wordCountPointer, "%s", currentWord ) != EOF){
		wordcount++;
	}
        fclose(wordCountPointer);	
	printf("Word Count: %d \n", wordcount);
  	
	exit(0);
}
