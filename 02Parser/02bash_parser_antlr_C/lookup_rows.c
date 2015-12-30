#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}
/*nimmt die erste Zeile einer Datei als Spaltenbezeichner*/
char** lookup(char* filename, char delimit)
{
	FILE *f;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char** ptr;	
	f=fopen(filename,"r");
	if(!f)
		return NULL;
	if( read = getline(&line, &len, f) ==-1)
		return NULL;
	printf("%s\n",line);
	fclose(f);
	return str_split(line,delimit);
}

int main(int argc, char* argv[])
{
	char **ptr;
	ptr=lookup(argv[1],',');
	while(*ptr!=NULL)
		printf("%s\n",*ptr++);
	return 0;
}
