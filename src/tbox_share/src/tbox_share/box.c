/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#define BOX_EXPORTS
#include "box.h"
#include "config.h"
#include "tbox.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
BOX_API int box_init()
{
    tb_trace_i("box_init");
    return tb_init(tb_null, tb_null);
}

BOX_API void box_exit()
{
    tb_exit();
}

BOX_API box_co_scheduler_ref_t box_co_scheduler_init()
{
    return tb_co_scheduler_init();
}
BOX_API box_bool_t box_coroutine_start(
    box_co_scheduler_ref_t scheduler,
    box_coroutine_func_t func,
    box_cpointer_t priv,
    box_size_t stacksize)
{
    return tb_coroutine_start((tb_co_scheduler_ref_t)scheduler, func, priv, stacksize);
}

BOX_API box_coroutine_ref_t box_coroutine_self()
{
    return tb_coroutine_self();
}

BOX_API void box_co_scheduler_loop(box_co_scheduler_ref_t schedule, box_bool_t exclusive)
{
    tb_co_scheduler_loop((tb_co_scheduler_ref_t)schedule, exclusive);
}
BOX_API void box_co_scheduler_exit(box_co_scheduler_ref_t scheduler)
{
    tb_co_scheduler_exit((tb_co_scheduler_ref_t)scheduler);
}
BOX_API box_bool_t box_coroutine_yield()
{
    return tb_coroutine_yield();
}

BOX_API box_pointer_t box_coroutine_sleep(box_long_t interval)
{
    return tb_coroutine_sleep(interval);
}

BOX_API box_pointer_t box_coroutine_suspend(box_cpointer_t priv)
{
    return tb_coroutine_suspend(priv);
}

BOX_API box_pointer_t box_coroutine_resume(box_coroutine_ref_t coroutine, box_cpointer_t priv)
{
    return tb_coroutine_resume((tb_coroutine_ref_t)coroutine,priv);
}


BOX_API box_co_channel_ref_t box_co_channel_init(box_size_t size, box_co_channel_free_func_t free, box_cpointer_t priv)
{
    return tb_co_channel_init(size,free,priv);
}

BOX_API void box_co_channel_exit(box_co_channel_ref_t channel)
{
   tb_co_channel_exit((tb_co_channel_ref_t)channel); 
}

BOX_API void box_co_channel_send(box_co_channel_ref_t channel, box_cpointer_t data)
{
   tb_co_channel_send((tb_co_channel_ref_t)channel,data);
}
BOX_API box_pointer_t box_co_channel_recv(box_co_channel_ref_t channel)
{
    return tb_co_channel_recv((tb_co_channel_ref_t)channel);
}
BOX_API box_bool_t box_co_channel_send_try(box_co_channel_ref_t channel, box_cpointer_t data)
{
    return tb_co_channel_send_try((tb_co_channel_ref_t)channel,data);
}
BOX_API box_bool_t box_co_channel_recv_try(box_co_channel_ref_t channel, box_pointer_t *pdata)
{
    return tb_co_channel_recv_try((tb_co_channel_ref_t)channel,pdata);
}

BOX_API int add(int a,int b)
{
    return a+b;
}
