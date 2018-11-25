#include "types.h"
#include "stat.h"
#include "uproc.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    struct uproc p;
    int b = getprocinfo(0,&p); 
    if (b != -1) {
        printf(1, "\tID\tP_ID\tSZ\tC_W\tK\tName\n");
        printf(1, "\t%d\t%d\t%d\t%d\t%d\t%s\n", p.pid, p.parent_pid, p.sz, p.channel_wait,p.killed,p.name);
        //printf(1, "Process size: %d\n", p.sz);
        //printf(1, "CHannel Wait: %d\n", p.channel_wait);
        //printf(1, "Killed: %d\n", p.killed);
        //printf(1, "Name: %s\n", p.name);
    }
    exit();
}
