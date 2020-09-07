#ifndef TRACE_H
#define TRACE_H

#include <stdarg.h>
#include <stdlib.h>

void _trace(unsigned level, const char *fmt, ...);

#define die(...)  (_trace(2, __VA_ARGS__), exit(1))
#define err(...)   _trace(3, __VA_ARGS__)
#define warn(...)  _trace(4, __VA_ARGS__)
#define note(...)  _trace(5, __VA_ARGS__)
#define info(...)  _trace(6, __VA_ARGS__)
#define debug(...) _trace(7, __VA_ARGS__)
#define die_on(cond, ...) do { \
	if (cond) \
		die(__VA_ARGS__); \
    } while (0)

#define if_return(r) { int _e_ = (r); if (_e_ != 0) { warn("%s failed: 0x%08X", #r, _e_); return _e_; } }
#define if_report(r) { int _e_ = (r); if (_e_ != 0) { warn("%s failed: 0x%08X", #r, _e_); } }
	
#endif // TRACE_H
