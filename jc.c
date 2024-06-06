#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char fileName[100];
char finalCmd[500];
char finFilename[200];
int length = 0;


void compileC();
void compileCpp();

//string compare
bool sameStr(char *first, char *second){

	int firLen = strlen(first);
	int secLen = strlen(second);
	int count = 0;

	if (firLen != secLen) {
		return false;
	}

	for (int i = 0; i < firLen; i++) {
		if (first[i] == second[i]) {
			count++;		
		}	
	}

	if (count != firLen) {
		return false;
	}else {
		return true;
	}
}

//compile C++
void compileCpp(){

	int i = 0;
	int fin = 0;
	for (int i = 0; i < length-1; i++) {
		finFilename[i] = '\0';	

	}
	
	if (fileName[0] == '.') {
		
	for (i = 2; fileName[i] != '.'; i++) {
		finFilename[fin] = fileName[i];
		fin++;
	}

	}else {
	

	for (i = 0; fileName[i] != '.'; i++) {
		finFilename[i] = fileName[i];
	}

	}

	sprintf(finalCmd, "g++ %s -o %s",  fileName, finFilename);
	system(finalCmd);

}

//compile c
void compileC(){


	int i = 0;
	int fin = 0;
	for (int i = 0; i < length-1; i++) {
		finFilename[i] = '\0';	

	}
	
	if (fileName[0] == '.') {
		
	for (i = 2; fileName[i] != '.'; i++) {
		finFilename[fin] = fileName[i];
		fin++;
	}

	}else {
	

	for (i = 0; fileName[i] != '.'; i++) {
		finFilename[i] = fileName[i];
	}

	}

	sprintf(finalCmd, "gcc %s -o %s",  fileName, finFilename);
	system(finalCmd);

}

//Check for C
bool isC(){

	int ext = 0;

	if ( fileName[length-1] == 'c' ) {
		ext++;				
	}

	if ( fileName[length-2] == '.') {
					
		ext++;				
	}
	

	if (ext == 2) {
		return true;
	}else {
		return false;
	}
}

//Check for C++
bool isCpp(){

	int ext = 0;

	if ( fileName[length-1] == 'p' ) {
		ext++;				
	}

	if ( fileName[length-2] == 'p') {
					
		ext++;				
	}
	
	if ( fileName[length-3] == 'c') {
					
		ext++;				
	}

	if ( fileName[length-4] == '.') {
					
		ext++;				
	}
	if (ext == 4) {
		return true;
	}else {
		return false;
	}
	
	
}


int main(int argc, char *argv[])
{
	if (argc < 2 ) {
		printf("Error: C or CPP file not supplied\n");
		printf("Usage: cr <prog.c or .cpp>\n");
		exit(1);
	}


	if (argc > 2  ) {
		printf("Error: one file limit\n");
		printf("Usage: cr <prog.c or .cpp>\n");
		exit(1);
	}


	if (sameStr(argv[1], "-h")) {
		printf("\njc or Just Compile is a program that can compile\n");
		printf("files with .c or .cpp extensions\n");	
		printf("Usage: cr prog.c \n");
		printf("Usage: cr prog.cpp \n\n");
		exit(0);
	}

	if (sameStr(argv[1], "--help")) {
		printf("\njc or Just Compile is a program that can compile\n");
		printf("files with .c or .cpp extensions\n");	
		printf("Usage: cr prog.c \n");
		printf("Usage: cr prog.cpp \n\n");
		exit(0);
	}

	length = strlen(argv[1]);

	strcpy(fileName, argv[1]);


	if (isCpp()) {
		compileCpp();
	}else if(isC()){
		compileC();
	}else {
		printf("Error: Incorrect Extension");
		exit(1);
	}

	return 0;
}
