#include <arena.h>
#include <arena_process.h>

static inline int32_t	ft_binarray_to_int32(unsigned int address)
{
	int32_t				value;
	register int		index;

	index = 0;
	while (index < 4)
	{
		value <<= __CHAR_BIT__;
		value |= g_arena.arena[address++];
	}
	return (value);
}

void					op_zjmp(t_process *process, t_param *parameters)
{
	int32_t const		value = ft_binarray_to_int32(parameters->opaddress);

	process->pc = MEMINDEX(process->pc + (value % IDX_MOD));
}
