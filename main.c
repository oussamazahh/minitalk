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

void print_bit(unsigned char octet)
{
  unsigned char n;
  int kill_result;
  int tab[8];
  int i;

  n = 128;
  i = 0;
  ft_memset(tab, 0, 8);
  while ( i < 8 && n != 0)
  {
    if ((octet - n) >= 0)
    {
      tab[i] = 1;
      //   kill_result = kill(pid, SIGUSR1); //sends signal SIGUSR2 to a server
      //   if (kill_result == -1) {
      //       perror("Error sending SIGUSR1");
      //   }
      //   usleep(500);
      octet -= n;
    }
    else
    {
      tab[i] = 0;
        // kill_result = kill(pid, SIGUSR2); //sends signal SIGUSR2 to a server
        // if (kill_result == -1) {//check if the signal send
        //     perror("Error sending SIGUSR2");
        // }
        // usleep(500);
    }
    if(octet == 0 && n == 1)
      break;
    n /= 2;
    i++;
  }
  i = 0;
  while (i <= 7)
  {
    if (tab[i] >= 0)
        // kill(pid, SIGUSR2);
        printf("%d", tab[i]);
    else if (tab[i] >= 1)
        // kill(pid, SIGUSR1);
        printf("%d", tab[i]);
      usleep(100);
    i++;
  }
}

int main()
{
    print_bit(128);
}