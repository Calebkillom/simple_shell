#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point to parent's and child's PID
 *
 * Return: 0
 */

int main(void)
{
	pid_t parent_pid;
	pid_t my_pid;

	parent_pid = getppid();
	my_pid = getpid();

	printf("This is the current Parent's pid - %u\n", parent_pid);
	printf("This is the current Child's pid - %u\n", my_pid);
	return (0);
}
