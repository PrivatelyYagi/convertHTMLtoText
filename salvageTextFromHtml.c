/*********************
 *
 * HTMLからタグ以外のテキストを抽出する
 * 本文に'<'が含まれるとその一文は認識しない仕様
 *
 * 2018/04/22 22:43 file make.  Shinsaku Yagi
 * 2018/04/22 22:54 fix.        Shinsaku Yagi
 * ******************/


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
        if (isTag == true) {
            if(gotChar == '>'){
                /* end of tag. flug off */
                isTag = false;
            }
        } else {
            if (gotChar == '<') {
                /* start of tag. flug on */
                isTag = true;
            } else if (gotChar == '\t' || gotChar == ' ') {
                /* nothing to do. */
            } else {
                fputc(gotChar, textFile);
            }
        }
    }
    fclose(htmlFile);
    fclose(textFile);
    printf("success!!\n");
    return 0;
}
