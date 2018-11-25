#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "uproc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//ARVINDH
int
sys_backtrace(void)
{
    struct trapframe* tf = myproc()->tf;
    cprintf("edi: 0x%x\n", tf->edi);
    cprintf("esi: 0x%x\n", tf->esi);
    cprintf("ebp: 0x%x\n", tf->ebp);
    cprintf("ebx: 0x%x\n", tf->ebx);
    cprintf("edx: 0x%x\n", tf->edx);
    cprintf("ecx: 0x%x\n", tf->ecx);
    cprintf("eax: 0x%x\n", tf->eax);
    cprintf("gs: 0x%x\n", tf->gs);
    cprintf("fs: 0x%x\n", tf->fs);
    cprintf("es: 0x%x\n", tf->es);
    cprintf("ds: 0x%x\n", tf->ds);
    cprintf("cs: 0x%x\n", tf->cs);
    cprintf("eip: 0x%x\n", tf->eip);
    cprintf("eflags: 0x%x\n",tf->eflags);
    uint temp_ebp = tf->ebp;
    uint i = 0;
    for(;;temp_ebp = *((uint*)temp_ebp))
    {
        cprintf("#%d: 0x%x\n", i, *(uint*)(temp_ebp+4));
        i++;
        if (*(uint*)(temp_ebp+4) == 0xffffffff) 
            break;
    }
    return 0;
}

int
sys_getprocinfo(void)
{
    int n;
    struct uproc *p =0x0;
    if (argint(0, &n) < 0 || argptr(1,(char**) &p, sizeof(struct uproc) < 0))
        return -1;
    return getprocinfo(n, p);
}
