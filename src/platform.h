#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef WINDOWS
	/* Get current working directory */
	#include <direct.h>
	#define currentDir _getcwd
	#define PATH_SEP '\\'
#else
	#include <unistd.h>
	#define currentDir getcwd
	#define PATH_SEP '/'
#endif

#endif
