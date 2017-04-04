#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
char* reverse(const char*);

int main()
{
	char str[]="My name is akash";
	printf("%s", str);
	assert(str);
	//char *rev = 
	char *res = reverse(str);
	printf("\n%s", res);
}


char* reverse(const char *str)
{
	char *res=NULL;
	int len = strlen(str);
	printf("\nlength of string: %d", len);
	res = (char*)malloc(sizeof(char)*len);
	assert(res);
	int i=0;
	for(i=0; i<len; i++)
	{
		*(res+len-1-i)=*(str+i);
	}
	*(res+len)='\0';
	return res;
}

