#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void reverse_inplace(char*);



int main()
{
	char str[]="my name is akash";
	//printf("")
	reverse_inplace(str);
	assert(&str);
	printf("\nreversed string: %s", str);

}

void reverse_inplace(char* str)
{
	//char *str = *mystr;
	printf("string:%s", str);
	int len = strlen(str);
	assert(str);
	int i=0;
	char temp;
	while(i<len/2)
	{
		temp = str[i];
		str[i]=str[len-i-1];
		str[len-1-i]= temp;
		i++;
	}
	//*mystr = str;
}
		
