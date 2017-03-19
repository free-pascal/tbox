#ifndef BOX_H
#define BOX_H
#ifdef BOX_EXPORTS
#define BOX_API __declspec(dllexport)
#else
#define BOX_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef signed long box_long_t;
typedef signed int box_bool_t;
#define box_true ((box_bool_t)1)
#define box_false ((box_bool_t)0)
typedef unsigned long box_size_t;
typedef const void *box_cpointer_t;
typedef void *box_pointer_t;
typedef void (*box_coroutine_func_t)(box_cpointer_t priv);
typedef void *box_co_scheduler_ref_t;
typedef void *box_coroutine_ref_t;
typedef void *box_co_channel_ref_t;
typedef void (*box_co_channel_free_func_t)(box_pointer_t data, box_cpointer_t priv);
BOX_API box_bool_t box_init();
BOX_API void box_exit();

//coroutine
BOX_API box_co_scheduler_ref_t box_co_scheduler_init();
BOX_API box_bool_t box_coroutine_start(box_co_scheduler_ref_t scheduler, box_coroutine_func_t func, box_cpointer_t priv, box_size_t stacksize);
BOX_API box_coroutine_ref_t box_coroutine_self();
BOX_API void box_co_scheduler_loop(box_co_scheduler_ref_t schedule, box_bool_t exclusive);
BOX_API void box_co_scheduler_exit(box_co_scheduler_ref_t scheduler);
BOX_API box_bool_t box_coroutine_yield();
BOX_API box_pointer_t box_coroutine_sleep(box_long_t interval);
BOX_API box_pointer_t box_coroutine_suspend(box_cpointer_t priv);
BOX_API box_pointer_t box_coroutine_resume(box_coroutine_ref_t coroutine, box_cpointer_t priv);

//channel
BOX_API box_co_channel_ref_t box_co_channel_init(box_size_t size, box_co_channel_free_func_t free, box_cpointer_t priv);
BOX_API void box_co_channel_exit(box_co_channel_ref_t channel);
BOX_API void box_co_channel_send(box_co_channel_ref_t channel, box_cpointer_t data);
BOX_API box_pointer_t box_co_channel_recv(box_co_channel_ref_t channel);
BOX_API box_bool_t box_co_channel_send_try(box_co_channel_ref_t channel, box_cpointer_t data);
BOX_API box_bool_t box_co_channel_recv_try(box_co_channel_ref_t channel, box_pointer_t *pdata);

//test
BOX_API int add(int a,int b);


#ifdef __cplusplus
}
#endif
#endif
