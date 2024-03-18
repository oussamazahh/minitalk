#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ft_client.h"

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
        usleep(500);
        ft_printf("1");
      octet -= n;
    }
    else
    {
        kill_result = kill(pid, SIGUSR2); //sends signal SIGUSR2 to a server
        if (kill_result == -1) {//check if the signal send
            perror("Error sending SIGUSR2");
        }
        usleep(500);
        ft_printf("0");
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
    int i = 0;
    while (argv[2][i])
      print_bit(argv[2][i++], pid);
    sleep(2);
    
  //  print_int_bit(len, pid);
}