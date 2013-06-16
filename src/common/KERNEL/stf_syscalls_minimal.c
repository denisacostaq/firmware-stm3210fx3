#include "stf_syscalls_minimal.h"
// Function definition.

void _exit(int i)
{
	printf("Program exit with code %d", i);
	while (1);
}

int _write(int file, char *buffer, unsigned int count)
{
	register int i;
	for (i=0; i<count; ++i) {
		//putChar(*buffer++);
	}

	return count;
}

int _close(int file)
{
	return -1;
}

int _fstat(int file, struct stat *st)
{
	st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int file)
{
	return 1;
}

int _lseek(int file, int ptr, int dir)
{
	return 0;
}

int _read(int file, char *ptr, int len)
{
	return 0;
}

caddr_t _sbrk(int incr)
{
	caddr_t prevHeap;
	caddr_t nextHeap;

	if (heap == NULL)
	{ // first allocation
		heap = (caddr_t) & _heap;
	}

	prevHeap = heap;

	// Always return data aligned on a 8 byte boundary
	nextHeap = (caddr_t) (((unsigned int) (heap + incr) + 7) & ~7);

	// Check enough space and there is no collision with stack coming the other way
	// if stack is above start of heap
	if (nextHeap >= (caddr_t) & _eheap)
	{
		errno = ENOMEM;
		return NULL; // error - no more memory
	}
	else
	{
		heap = nextHeap;
		return (caddr_t) prevHeap;
	}
}

int _open(const char *name, int flags, int mode)
{
	return -1;
}

int _link(char *old, char *new)
{
	errno = EMLINK;
	return -1;
}

int _unlink(char *name)
{
	errno = ENOENT;
	return -1;
}

int _stat(char *file, struct stat *st)
{
	st->st_mode = S_IFCHR;
	return 0;
}

int _execve(char *name, char **argv, char **env)
{
	errno = ENOMEM;
	return -1;
}

int _fork()
{
	errno = EAGAIN;
	return -1;
}

int _getpid()
{
	return 1;
}

int _kill(int pid, int sig)
{
	errno = EINVAL;
	return (-1);
}

int times(struct tm *buf)
{
	return -1;
}

int _wait(int *status)
{
	errno = ECHILD;
	return -1;
}
