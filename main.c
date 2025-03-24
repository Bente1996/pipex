#include <unistd.h>
#include <stdio.h>

int	main()
{
	int child_pid;

	child_pid = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		printf("hoi ik ben een child process");
	}
	else
		printf("hoi ik ben een parent process");
	printf("%d\n", child_pid);
	return(0);
}
