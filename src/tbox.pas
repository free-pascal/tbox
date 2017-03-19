unit tbox;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

const
  tbox_dll = 'tbox_share';
  box_true = 1;
  box_false = 0;

type
  box_bool_t = cardinal;
  box_size_t = cardinal;
  box_long_t = longint;
  box_cpointer_t = pointer;
  box_pointer_t = pointer;
  pbox_pointer_t = ^box_pointer_t;
  box_co_scheduler_ref_t = pointer;
  box_co_channel_ref_t = pointer;
  box_coroutine_ref_t = pointer;
  box_coroutine_func_t = procedure(priv: box_cpointer_t); cdecl;
  box_co_channel_free_func_t = procedure(Data: box_pointer_t; priv: box_cpointer_t); cdecl;
function add(a,b:integer):integer;cdecl; external tbox_dll;
function box_init(): box_bool_t; cdecl; external tbox_dll;
procedure box_exit(); cdecl; external tbox_dll;

//coroutine
function box_co_scheduler_init(): box_co_scheduler_ref_t; cdecl; external tbox_dll;
function box_coroutine_start(scheduler: box_co_scheduler_ref_t;
  func: box_coroutine_func_t; priv: box_cpointer_t; stacksize: box_size_t): box_bool_t;
  cdecl; external tbox_dll;
function box_coroutine_self(): box_coroutine_ref_t; cdecl; external tbox_dll;
procedure box_co_scheduler_loop(schedule: box_co_scheduler_ref_t; exclusive: box_bool_t);
  cdecl; external tbox_dll;
procedure box_co_scheduler_exit(scheduler: box_co_scheduler_ref_t);
  cdecl; external tbox_dll;
function box_coroutine_yield(): box_bool_t; cdecl; external tbox_dll;
function box_coroutine_sleep(interval: box_long_t): box_pointer_t;
  cdecl; external tbox_dll;
function box_coroutine_suspend(priv: box_cpointer_t): box_pointer_t;
  cdecl; external tbox_dll;
function box_coroutine_resume(coroutine: box_coroutine_ref_t;
  priv: box_cpointer_t): box_pointer_t; cdecl; external tbox_dll;

//channel
function box_co_channel_init(size: box_size_t;
  Free: box_co_channel_free_func_t; priv: box_cpointer_t): box_co_channel_ref_t;
  cdecl; external tbox_dll;
procedure box_co_channel_exit(channel: box_co_channel_ref_t); cdecl; external tbox_dll;
procedure box_co_channel_send(channel: box_co_channel_ref_t; Data: box_cpointer_t);
  cdecl; external tbox_dll;
function box_co_channel_recv(channel: box_co_channel_ref_t): box_pointer_t;
  cdecl; external tbox_dll;
function box_co_channel_send_try(channel: box_co_channel_ref_t;
  Data: box_cpointer_t): box_bool_t; cdecl; external tbox_dll;
function box_co_channel_recv_try(channel: box_co_channel_ref_t;
  pdata: pbox_pointer_t): box_bool_t; cdecl; external tbox_dll;

implementation

initialization
  box_init;
finalization
  box_exit;
end.
