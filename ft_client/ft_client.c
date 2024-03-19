#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ft_client.h"

void send_bit(unsigned char octet, pid_t pid)
{
  unsigned char n;
  int kill_result;
  int tab[8];
  int i;

  n = 128;
  i = 0;
  ft_memset(tab, 0, 8);
  while (i < 8 && n != 0)
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
    if (tab[i] == 0)
    {
      kill_result = kill(pid, SIGUSR2); //sends signal SIGUSR2 to a server
        if (kill_result == -1) {
            perror("Error sending SIGUSR2");
        }
    }
    else if (tab[i] == 1)
    {
      kill_result = kill(pid, SIGUSR1); //sends signal SIGUSR1 to a server
        if (kill_result == -1) {
            perror("Error sending SIGUSR1");
        }
    }
    i++;
    usleep(400);
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
    if (pid > 1)
    {
      printf("PID %d\n",pid);
      int i = 0;
      while (argv[2][i])
        send_bit(argv[2][i++], pid);
    usleep(1000);
    }
    else
      write(1, "Don't play with me", 18);
  //  print_int_bit(len, pid);
}