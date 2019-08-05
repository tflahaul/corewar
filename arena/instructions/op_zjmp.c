#include <arena.h>
#include <arena_process.h>

void					op_zjmp(t_process *process, t_param *parameters)
{
	int32_t const		value = ft_binarray_to_int32(parameters->opaddress);

	if (process->carry != 0)
		process->pc = MEMINDEX(process->pc + (value % IDX_MOD));
}
