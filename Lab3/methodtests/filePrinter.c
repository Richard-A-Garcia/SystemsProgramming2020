#include <stdio.h>
#include <stdlib.h>
void printFile(char file_name[25])
{
   char ch;
   FILE *fp;
   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("The contents of %s file are:\n", file_name);

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
}
int main(){
	char ch, file_name[25];
	FILE *fp;
	printf("Enter name of a file you wish to see\n");
	gets(file_name);
	printFile(file_name);
	return 0;
}
