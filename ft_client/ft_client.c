/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:39:40 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/20 23:52:28 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ft_client.h"

int size;
void fil_tab_len(int n, int depth , int tab[32]) {
    if (depth == 0) {
        return;
    }
    tab[depth - 1] = n % 2;
    // if (tab[depth - 1] == 0)
    //   kill(pid, SIGUSR2);
    // if (tab[depth - 1] == 1)
    //   kill(pid, SIGUSR1);
    // usleep(400);
    fil_tab_len(n / 2, depth - 1, tab);
    // printf("tab [%d] == %d\n" , depth - 1, tab[depth - 1]);
}

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
      octet -= n;
    }
    else
    {
      tab[i] = 0;
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

void send_len(int tab[32], pid_t pid)
{
  int i = 0;
  while (i < 32)
  {
    if (tab[i] == 0)
      kill(pid, SIGUSR2);
    if (tab[i] == 1)
      kill(pid, SIGUSR1);
    usleep(1000);
    i++;
  }
}

int main(int argc, char *argv[])
{
  int tab [32];
    pid_t pid = ft_atoi(argv[1]);
    if (pid > 1)
    {
      printf("PID %d\n",pid);
      int i = 0;
      ft_memset(tab, 1, 32);
      int len = ft_strlen(argv[2]);
      fil_tab_len(len, 32, tab);
      send_len(tab, pid);
      while (argv[2][i])
        send_bit(argv[2][i++], pid);
    usleep(1000);
    }
    else
      write(1, "Don't play with me", 18);
}