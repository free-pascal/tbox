unit test1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, tbox;
procedure box_demo_coroutine_channel_test(size: box_size_t);

implementation

procedure box_demo_coroutine_channel_test_send(priv: box_cpointer_t); cdecl;
var
  channel: box_co_channel_ref_t;
  Count: box_size_t;
begin
  // check
  channel := box_co_channel_ref_t(priv);

  // loop
  Count := 10;
  while Count > 0 do
  begin
    Dec(Count);
    writeln('Send:', Count);
    // send data
    box_co_channel_send(channel, box_cpointer_t(Count));
  end;

end;

procedure box_demo_coroutine_channel_test_recv(priv: box_cpointer_t); cdecl;
var
  channel: box_co_channel_ref_t;
  Count, Data: box_size_t;
begin
  // check
  channel := box_co_channel_ref_t(priv);
  // loop
  Count := 10;
  while Count > 0 do
  begin
    Dec(Count);
    writeln('recv count=',count);
    // recv
    Data := box_size_t(box_co_channel_recv(channel));
    WriteLn('recv:', Data);
  end;

end;

procedure box_demo_coroutine_channel_test(size: box_size_t);
var
  scheduler: box_co_scheduler_ref_t;
  channel: box_co_channel_ref_t;
begin
  // init scheduler
  scheduler := box_co_scheduler_init();
  if (scheduler <> nil) then
  begin
    // init channel
    channel := box_co_channel_init(size, nil, nil);
    //box_assert(channel);

    // start coroutines
    box_coroutine_start(scheduler, @box_demo_coroutine_channel_test_send, channel, 0);
    box_coroutine_start(scheduler, @box_demo_coroutine_channel_test_send, channel, 0);
    box_coroutine_start(scheduler, @box_demo_coroutine_channel_test_send, channel, 0);
    box_coroutine_start(scheduler, @box_demo_coroutine_channel_test_recv, channel, 0);
    box_coroutine_start(scheduler, @box_demo_coroutine_channel_test_recv, channel, 0);
    box_coroutine_start(scheduler, @box_demo_coroutine_channel_test_recv, channel, 0);

    // run scheduler
    box_co_scheduler_loop(scheduler, box_true);

    // exit channel
    box_co_channel_exit(channel);

    // exit scheduler
    box_co_scheduler_exit(scheduler);
  end;
end;

end.

