#include<stdio.h>
#include<string.h>
int main(){
	char s1[210],s2[210];
	scanf("%s",s1);
	int size_1=strlen(s1);
	for(int i=0;i<size_1;i++) printf("%c",s1[i]);
	return 0;
} 