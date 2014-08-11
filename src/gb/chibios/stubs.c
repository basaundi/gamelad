// ANDER MARTINEZ 2014
// Newlib stubs implementation

#include <sys/types.h>
#include <stdlib.h>

pid_t _getpid()
{
	return 0;
}

void _exit( int status )
{
	(void)status;
	while( 1 );
}

int _kill( int pid, int sig )
{
	(void)pid; (void)sig;
	return -1;
}

int _open_r(void *reent, const char *file, int flags, int mode)
{
	(void)reent; (void)file; (void)flags; (void)mode;
	return -1;
}

int _sbrk_r(){ return -1; }
int _read_r(){ return -1; }
int _write_r(){ return -1; }
int _close_r(){ return -1; }
int _fstat_r(){ return -1; }
int _isatty_r(){ return -1; }
int _lseek_r(){ return -1; }

void *__dso_handle = NULL;
