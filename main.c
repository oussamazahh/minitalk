#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
void send_len(int octet)
{
  int n;
  unsigned char *set;
  int kill_result;
  int tab[32];
  int i;

  n = 512;
  i = 0;
  ft_memset(tab, 1, 32);
  
  while (i < 32)
  {
    tab[i] = n % 2;
    if(octet == 0 && n == 1)
      break;
    n /= 2;
    i++;
  }
  i = 0;
  while (i < 32)
  {
    if (tab[i] == 0)
    {
      printf("0");
    }
    else if (tab[i] == 1)
    {
      printf("1");
    }
    i++;
    // usleep(400);
  }
}
void print_binary(int n, int depth) {
  int tab[32];
  ft_memset(tab, 1, 32);
    if (depth == 0) {
        return;
    }
    tab[depth - 1] = n % 2;
    printf("tab [%d] == %d\n" , depth - 1, tab[depth - 1]);
    print_binary(n / 2, depth - 1);
}
int main()
{
    // print_bit(128);
  // send_len(1);
  int num = 255;
  static int i = 0;
    print_binary(num, 32);

}
