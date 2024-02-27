#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_puthex(unsigned long long nb, int firstdigit)
{
    char    *base;

    base = "0123456789abcdef";
    if (nb < 16 && firstdigit == 1)
		ft_putchar('0');
    if (nb >= 16)
	{
        ft_puthex(nb / 16, 0);
		ft_puthex(nb % 16, 0);
	}
   	else
    	ft_putchar(base[nb]);
}

void	print_ptr_addr(unsigned long long nb)
{
	unsigned long long	tmp;
	char				*base;
	int					i;

	base = "0123456789abcdef";
	tmp = nb;
	i = 0;
	while (tmp / 16 != 0)
		i++;
	
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;
	char			substr[17];
	
	i = 0;
	str = addr;
	while (str[i])
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				print_values(str, i);
			print_ptr_addr((long long) str + (i * 16));
		}
		else
		{
			substr[i % 16] = str[i];
			print_hexa(str, i);
		}
	}
}






int     main(void)
{
	int i;

	char str[] = "Bonjour les amiseeeeeee\neeeeeeeedwadwadawdadwadwegfrsdhgrtdhtrdharewfwafwafeawfwFAWFAGAWGRESHSERHEStrgesgresgrtdhtyjreeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	i = 150;
	ft_print_memory(str, i);
}

//00000010a161f40
//0x7fff57f54a40

