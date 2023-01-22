
#include "cub3d.h"

char *ft_strcpy(char *str, char *str2)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		str2[j] = str[i];
		j++;
		i++; 
	}
	str2[j] = '\0';
	return (str2);
}

int main()
{
    char *str = "C        225,250,0";
    char *fin;
    fin = (char*)malloc(50);
    fin = ft_strcpy(str, fin);
    printf("%s\n", fin);
}