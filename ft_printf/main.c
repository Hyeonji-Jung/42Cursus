#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("--- printf ---\n");
    int ret = printf("%d\n%i\n%i\n%i\n\n", -42, -052, -0x2a, -0x2A);
    ft_printf("--- ft_printf ---\n");
    int ft_ret = ft_printf("%d\n%i\n%i\n%i\n\n", -42, -052, -0x2a, -0x2A);
    printf("printf: %d\nft_printf: %d\n", ret, ft_ret);
    return 0;
}