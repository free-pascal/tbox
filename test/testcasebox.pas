unit testcasebox;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry;

type

  TTestCaseBox= class(TTestCase)
  protected
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestCo;
  end;

implementation
uses
  tbox,test1;


procedure TTestCaseBox.TestCo;
begin
  box_demo_coroutine_channel_test(2)
end;

procedure TTestCaseBox.SetUp;
begin

end;

procedure TTestCaseBox.TearDown;
begin

end;

initialization
  RegisterTest(TTestCaseBox);
end.

