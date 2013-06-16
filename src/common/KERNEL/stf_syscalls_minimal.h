/**
 * <b>File:</b> stf_syscalls_minimal.c
 *
 * <b>Project:</b> FreeRTOS.org STM32 demo using Eclipse
 *
 * <b>Description:</b> This is the complete set of system definitions (primarily subroutines) required.
 * It implements the minimal functionality required to allow libc to link, and fail gracefully where OS services
 * are not available.
 *
 * For more information see the newlib documentation at http://sourceware.org/newlib/
 *
 * <b>Cereated:</b> 09/04/2009
 *
 * <dl>
 * <dt><b>Autor</b>:</dt>
 * <dd>Stefano Oliveri</dd>
 * <dt><b>E-mail:</b></dt>
 * <dd>software@stf12.net</dd>
 * </dl>
 */


#ifndef STF_SYSCALLS_MINIMAL_H
#define	STF_SYSCALLS_MINIMAL_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#ifdef	__cplusplus
extern "C"
{
#endif

// Function declaration.
void _exit(int i);
int _open(const char *name, int flags, int mode);
int _read(int file, char *ptr, int len);
int _write(int file, char *buffer, unsigned int count);
int _lseek(int file, int ptr, int dir);
int _fstat(int file, struct stat *st);
int _link(char *old, char *new);
int _unlink(char *name);
int _stat(char *file, struct stat *st);
int _close(int file);
int _execve(char *name, char **argv, char **env);
int _fork();
int _getpid();
int _isatty(int file);
int _kill(int pid, int sig);
caddr_t _sbrk(int incr);
int times(struct tm *buf);
int _wait(int *status);


#undef errno
extern int errno;
char *__env[1] = {0};
char **__environ = __env;
extern unsigned int _heap;
extern unsigned int _eheap;
static caddr_t heap = NULL;


#ifdef	__cplusplus
}
#endif

#endif	/* STF_SYSCALLS_MINIMAL_H */

