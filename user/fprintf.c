#include "lib.h"



static void user_out2string(void *arg, char *s, int l)
{
    int i;
	char * b = (char *)arg;
    // special termination call
    if ((l==1) && (s[0] == '\0')) return;
    /*if(s[0] == '\0') {
		b[0] = '\0';
		return;
	}*/
    for (i=0; i< l; i++) {
		b[i]=s[i];
    }
}


int fwritef(int fd, const char *fmt, ...)
{
	char buf[512];
	va_list ap;
	int i;
	for(i = 0; i < 512; i++) {
		buf[i] = '\0';
	}
	va_start(ap, fmt);
	/*if(fd == 1) {
		user_lp_Print(user_myoutput, 0, fmt, ap);
	} else {
		user_lp_Print(user_out2string, buf, fmt, ap);
	}*/
	user_lp_Print(user_out2string, buf, fmt, ap);
	va_end(ap);
	return write(fd, buf, strlen(buf));
}