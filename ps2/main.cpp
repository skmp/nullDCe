#include "types.h"
#include "dc/mem/_vmem.h"
#include "dc/sh4/sh4_registers.h"
#include "dc/sh4/sh4_opcode_list.h"
#include "stdclass.h"
#include "dc/dc.h"
#include "gui/base.h"
#include "config/config.h"
#include "plugins/plugin_manager.h"
#include "serial_ipc/serial_ipc_client.h"
#include "cl/cl.h"
#undef r
#undef fr

void __debugbreak() { fflush(stdout); *(int*)0=1;}

int main(int argc, wchar* argv[])
{
	/*
	if (!freopen("host0:/ndclog.txt","w",stdout))
		freopen("ndclog.txt","w",stdout);
	setbuf(stdout,0);
	if (!freopen("host0:/ndcerrlog.txt","w",stderr))
		freopen("ndcerrlog.txt","w",stderr);
	setbuf(stderr,0);
	*/

	__asm__ __volatile__ ("ctc1 $0, $31");

	int rv=EmuMain(argc,argv);

	return rv;
}
