#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		if (n > 9223372036854775807 && sign == -1)
			return (0);
		if (n > 9223372036854775807 && sign == 1)
			return (-1);
		i++;
	}
	return ((int)n * sign);
}
void print_bit(unsigned char octet, pid_t pid)
{
  unsigned char n;
  int kill_result;

  n = 128;
  while (n != 0)
  {
    if ((octet - n) >= 0)
    {
        kill_result = kill(pid, SIGUSR1); //sends signal SIGUSR2 to a server
        if (kill_result == -1) {
            perror("Error sending SIGUSR1");
        }
        usleep(100);
        printf("1");
      octet -= n;
    }
    else
    {
        kill_result = kill(pid, SIGUSR2); //sends signal SIGUSR2 to a server
        if (kill_result == -1) {//check if the signal send
            perror("Error sending SIGUSR2");
        }
        usleep(100);
        printf("0");
    }
    if(octet == 0 && n == 1)
      break;
    n /= 2;
  }
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
  if (!s)
    return (i);
  while (*s++)
		i++;
	return (i);
}
void print_int_bit(int num, pid_t pid)
{
  unsigned char *c;
  c = (unsigned char*)&num;
  int i = 3;
  while (i>=0)
  {
    print_bit(c[i], pid);
    i--;
  }
  
}
// int main(int argc, char *argv[]) {

//   pid_t pid = ft_atoi(*argv[1]);  
//   int result = kill(pid, SIGKILL);  // send the SIGKILL signal to the process
//   if (result == 0) {
//     printf("Process terminated successfully.\n");
//   } else {
//     perror("Error terminating process");
//   }
//   return 0;
// }
int main(int argc, char *argv[])
{
    pid_t pid = ft_atoi(argv[1]);
    printf("PID %d\n",pid);
    int len = ft_strlen(argv[2]);
   print_int_bit(len, pid);
}