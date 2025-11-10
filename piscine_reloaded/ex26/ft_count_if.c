int ft_count_if(char **tab, int (*f)(char*));

int found_size(char **tab)
{
    return (sizeof(tab) / sizeof(tab[0]));
}
int ft_count_if(char **tab, int (*f)(char*))
{
    int i;
    int size;
    int number;

    i = 0;
    number = 0;
    size = found_size(tab);
    while (i < size)
    {
        if (f(tab[i]) == 1)
            number++;;
        i++;
    }
    return (number);
}