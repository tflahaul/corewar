#include <arena.h>
#include <arena_process.h>

void					op_zjmp(t_process *process, unsigned int parameters[4])
{
//	if (process->carry != 0)
		process->pc = MEMINDEX(process->pc + (parameters[1] % IDX_MOD));
}
