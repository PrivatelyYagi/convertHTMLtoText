#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILE_NAME_SIZE 100

int main(void){
    FILE *htmlFile;  // from
    FILE *textFile;  // to

    bool isTag = false;  // front of tag

    int gotChar;

    char fileName[FILE_NAME_SIZE];
    char textFileName[FILE_NAME_SIZE];

    printf("html file name =>");
    scanf("%s", fileName);

    printf("text file name ( make file ) =>");
    scanf("%s", textFileName);

    if((htmlFile = fopen(fileName,"r")) == NULL) {
        printf("file name error!\n");
        return -1;
    }

    if((textFile = fopen(textFileName,"a")) == NULL) {
        printf("file name error!\n");
        return -1;
    }

    while((gotChar = fgetc(htmlFile)) != EOF) {
        if( isTag == false && gotChar == '<' ) {
            isTag = true;
            continue;
		}
		else if (isTag == true && gotChar == '>') {
			isTag = false;
			continue;
		} else if ( isTag == false ) {
			if (gotChar == '\t' || gotChar == ' ') {
				continue;
			} else {
				fputc(gotChar, textFile);
			}
        } else{
            continue;
        }
    }
    fclose(htmlFile);
    fclose(textFile);
    printf("success!!\n");
    return 0;
}
