#include <stdio.h>
#include <string.h>

void afficher(int liste[], int taille)
{
	int i;	
	for(i =0; i < taille; i++)
		printf("%d ", liste[i]);	
	
}

int mon_strlen_1(char s[])
{
	int count = 0;
	while(s[count + 1] != '\0')
		++count;
	
	return count;
}

int mon_strlen_2(const char *s)
{
	int i;
	for (i=0; s[i++]; ){;}
	return i; 
}

int mon_strcmp_1(const char * s1, const char * s2)
{
	int i;
	for (i = 0; s1[i++];)
	{
		if(s1[i] < s2[i])
			return s2[i] - s1[i];

		if(s1[i] > s2[i])
			return s1[i] - s2[i];
		
	}
	return 0;
}

int mon_strncmp_2(const char * s1, const char * s2, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		if(s1 < s2)
			return s2 - s1;
		if(s1 > s2)
			return s1 - s2;
	}
	return 0;
}

char *mon_strcat_1(char *s1, const char *s2)
{
	char *i = s1;
    for (; *s1; s1++)
    	;
    for (; *s1 = *s2; s1++, s2++)
    	;

    return i;
}

char *mon_strstr_1(char *haystack, char *needle)
{
	for (; *haystack; haystack++)
	{
		if (needle == haystack)
		{
			for (; needle == haystack; needle++, haystack++)
			{
				if (*needle == *haystack) 
					return *haystack - *needle;
			}
		}
	}
	return NULL;
}

char *mon_strstr_2(char *haystack, char *needle);

int main(void)
{
	return 0;
}