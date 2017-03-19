unit test2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

type
  generic TTest<T> = class(TObject)
  private
    FObj: T;
  public
    property Obj: T read FObj write FObj;
  end;

type
  ts = specialize TTest<string>;


procedure test2();

implementation

procedure test2();
var
  t: ts;
begin
  t := ts.Create;
  t.Obj := 'ok';
end;

end.
