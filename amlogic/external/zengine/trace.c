#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include "trace.h"

static const char argv0[] = "zproxy";
static const unsigned verbosity = 7;

void _trace(unsigned level, const char *fmt, ...)
{

	if (level < 2)
		level = 2;
	else if (level > 7)
		level = 7;
	if (level <= verbosity) {
            switch(level) {
            case 2:
            case 3: level = ANDROID_LOG_ERROR; break;
            case 4: level = ANDROID_LOG_WARN; break;
            case 5:
            case 6: level = ANDROID_LOG_INFO; break;
            case 7: level = ANDROID_LOG_DEBUG; break;
            default:
                   level = ANDROID_LOG_INFO; break;
            }
            va_list ap;
            va_start(ap, fmt);
            __android_log_vprint(level, argv0, fmt, ap);
            va_end(ap);
/* #ifndef ANDROID
		static const char levels[8][6] = {
			[2] = "crit:",
			[3] = "err: ",
			[4] = "warn:",
			[5] = "note:",
			[6] = "info:",
			[7] = "dbg: "
		};
		int _errno = errno;
		va_list ap;
		fprintf(stderr, "%s: %s ", argv0, levels[level]);
		va_start(ap, fmt);
		vfprintf(stderr, fmt, ap);
		va_end(ap);
		if (fmt[strlen(fmt) - 1] != '\n') {
			char buffer[128];
			strerror_r(_errno, buffer, sizeof buffer);
			fprintf(stderr, ": (-%d) %s\n", _errno, buffer);
		}
		fflush(stderr);
*/
	}
}
