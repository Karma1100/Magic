#include <stddef.h>



typedef struct Block
{
	size_t block_size;
	int free;
	struct Block *next;
}Block;

static char memory_pool[1024*1024];
struct Block *free_list = (Block *)memory_pool;

queue_init()
{
	free_list->block_size = sizeof(memory_pool) - sizeof(Block);
	free_list->free = 1;
	free_list->next = NULL;

}

enqueue(sizeof sizeT)
{
	Block curr = free_list;

	while(curr)
	{
		if(curr->free && curr->block_size >= sizeT)
		{
			curr->free = 0;
			return (void *)(curr + 1);
		}
		curr = curr->next;
	}
	return NULL; //out of memory, watch out.


}



