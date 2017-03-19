/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */ 
#include "tbox_share/box.h"
#include <stdio.h>


static void box_demo_coroutine_channel_test_send(box_cpointer_t priv)
{
	// check
	box_co_channel_ref_t channel = (box_co_channel_ref_t)priv;

	// loop
	box_size_t count = 10;
	while (count--)
	{
		// trace
	    printf("[coroutine: %p]: send: %lu", box_coroutine_self(), count);

		// send data
		box_co_channel_send(channel, (box_cpointer_t)count);

		// trace
		printf("[coroutine: %p]: send: %lu ok", box_coroutine_self(), count);
	}
}
static void box_demo_coroutine_channel_test_recv(box_cpointer_t priv)
{
	// check
	box_co_channel_ref_t channel = (box_co_channel_ref_t)priv;

	// loop
	box_size_t count = 10;
	while (count--)
	{
		// trace
		printf("[coroutine: %p]: recv: ..", box_coroutine_self());

		// recv
		box_size_t data = (box_size_t)box_co_channel_recv(channel);

		// trace
		printf("[coroutine: %p]: recv: %lu ok", box_coroutine_self(), data);
	}
}

static void box_demo_coroutine_channel_test(box_size_t size)
{
	// trace
	printf("test: %lu", size);

	// init scheduler
	box_co_scheduler_ref_t scheduler = box_co_scheduler_init();
	if (scheduler)
	{
		// init channel
		box_co_channel_ref_t channel = box_co_channel_init(size, 0, 0);
		//box_assert(channel);

		// start coroutines
		box_coroutine_start(scheduler, box_demo_coroutine_channel_test_send, channel, 0);
		box_coroutine_start(scheduler, box_demo_coroutine_channel_test_send, channel, 0);
		box_coroutine_start(scheduler, box_demo_coroutine_channel_test_send, channel, 0);
		box_coroutine_start(scheduler, box_demo_coroutine_channel_test_recv, channel, 0);
		box_coroutine_start(scheduler, box_demo_coroutine_channel_test_recv, channel, 0);
		box_coroutine_start(scheduler, box_demo_coroutine_channel_test_recv, channel, 0);

		// run scheduler
		box_co_scheduler_loop(scheduler, box_true);

		// exit channel 
		box_co_channel_exit(channel);

		// exit scheduler
		box_co_scheduler_exit(scheduler);
	}
}

static void switchfunc(box_cpointer_t priv)
{
    printf("switchfunc");
    box_size_t count = (box_size_t)priv;
    while (count--)
    {
       
        printf("[coroutine: %p\r\n]: %lu", box_coroutine_self(), count);
        box_coroutine_yield();
    }
}
static void co_demo()
{
    box_co_scheduler_ref_t scheduler = box_co_scheduler_init();
    if (scheduler)
    {
        printf("box_co_scheduler_init\r\n");
        box_coroutine_start(scheduler, switchfunc, (box_cpointer_t)10, 0);

        printf("box_coroutine_start\r\n");
        box_coroutine_start(scheduler, switchfunc, (box_cpointer_t)10, 8192);

        printf("box_coroutine_start2\r\n");
        box_co_scheduler_loop(scheduler, box_false);
        printf("box_co_scheduler_loop\r\n");       
        box_co_scheduler_exit(scheduler);
        printf("box_co_scheduler_exit\r\n");
    }

}

/* //////////////////////////////////////////////////////////////////////////////////////
 * main
 */ 
int main(int argc, char** argv)
{

    
    if (!box_init()) return -1;
    printf("inited\r\n");

   box_demo_coroutine_channel_test(1);
   
    box_exit();

    return 0;
}
