/*
	This program takes command line arguments and prints texts file contents and text file word count
	Usage: [-cs] [-f substring ] filename 
	I affirm that I wrote this program myself without any help form any other people or sources from the internet
	
	Richard Garcia
	ID# 5862119
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
	//Creating the usage statement to print if the user makes an error
	static char usage[] = "usage: %s [-cs] [-f substring] filename\n";	 
	char ch;
	//these file pointers will allow me to print the file to the screen and also get the wordcount
	FILE *filePointer;
	FILE *wordCountPointer;
	int wordcount;
	
	

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
	
 	
	//This block of code prints the contents of the file 

	filePointer = fopen(argv[optind], "r");
	printf("File Text is : \n");
	while((ch = fgetc(filePointer)) != EOF){
      		printf("%c", ch);

	}
	fclose(filePointer);

	//This Portion of the code checks if the file exists
	wordCountPointer = fopen(argv[optind], "r");
	if (filePointer == NULL)
   	{
      		printf("File does not exist\n");
      		exit(-1);
   	}
	

	//This portion of the code performs the word count
	if(cflag == 1){
	char currentWord[50];
	while(fscanf(wordCountPointer, "%s", currentWord ) != EOF){
		wordcount++;
	}
        fclose(wordCountPointer);	
	printf("Word Count: %d \n", wordcount);
  	}
	exit(0);
}
