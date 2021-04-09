#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer;
	int index = 0;
	int ch;
	const char filename[] = "challenge.txt";
	FILE *fp;

	buffer = (char *)malloc( sizeof(char) * 32 );

	if (buffer == NULL)
		return 1;

	printf("Type some text: ");
	while(ch=getchar() != NULL) {
		if( ch=='\n')
			break;
		buffer[index++] = ch;
	}
	/* cap the string */
	*(buffer+index) = '\0';

	fp = fopen(filename,"w");
	fwrite(buffer,1,index,fp);
	fclose(fp);
	free(buffer);
	printf("%s created\n",filename);

	return(0);
}

