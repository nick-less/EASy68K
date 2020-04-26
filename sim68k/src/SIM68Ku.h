//---------------------------------------------------------------------------

#ifndef sim68KuH
#define sim68KuH
//---------------------------------------------------------------------------
#include <string>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <SHELLAPI.H>           // required for drag-n-drop from explorer
#include <Dialogs.hpp>
#include <Mask.hpp>
#include <MPlayer.hpp>
#include "findDialogS.h"
#include <NMURL.hpp>

extern TApplication * Application;


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *D0lbl;
        TLabel *D1lbl;
        TLabel *D2lbl;
        TLabel *D3lbl;
        TLabel *D5lbl;
        TLabel *D4lbl;
        TLabel *D6lbl;
        TLabel *D7lbl;
        TLabel *A0lbl;
        TLabel *A1lbl;
        TLabel *A2lbl;
        TLabel *A3lbl;
        TLabel *A4lbl;
        TLabel *A5lbl;
        TLabel *A6lbl;
        TLabel *A7lbl;
        TActionList *ActionList1;
        TMainMenu *MainMenu1;
        TToolBar *ToolBar1;
        TAction *Open;
        TMenuItem *File1;
        TImageList *ImageList1;
        TMenuItem *Open1;
        TMenuItem *N1;
        TMenuItem *Exit1;
        TMenuItem *RunMenu;
        TMenuItem *Close1;
        TMenuItem *Run1;
        TMenuItem *N2;
        TMenuItem *StepOver1;
        TMenuItem *TraceInto1;
        TMenuItem *Pause1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TAction *Close;
        TAction *Exit;
        TAction *Run;
        TAction *Step;
        TAction *Trace;
        TAction *Pause;
        TAction *Rewind;
        TAction *About;
        TToolButton *ToolOpen;
        TToolButton *ToolButton3;
        TToolButton *ToolRun;
        TToolButton *ToolStep;
        TToolButton *ToolTrace;
        TToolButton *ToolButton7;
        TToolButton *ToolPause;
        TToolButton *ToolButton9;
        TToolButton *ToolReset;
        TPanel *Panel1;
        TListBox *ListBox1;
        TScrollBar *ScrollBar1;
        TStatusBar *StatusBar1;
        TMenuItem *Options1;
        TMenuItem *SourceFont;
        TAction *FontSource;
        TOpenDialog *OpenDialog1;
        TFontDialog *FontDialogSource;
        TSplitter *Splitter2;
        TMemo *Message;
        TLabel *PClbl;
        TLabel *A8lbl;
        TMaskEdit *regPC;
        TMaskEdit *regA8;
        TMaskEdit *regA7;
        TMaskEdit *regA3;
        TMaskEdit *regA6;
        TMaskEdit *regA2;
        TMaskEdit *regA5;
        TMaskEdit *regA1;
        TMaskEdit *regA4;
        TMaskEdit *regA0;
        TMaskEdit *regD7;
        TMaskEdit *regD3;
        TMaskEdit *regD6;
        TMaskEdit *regD2;
        TMaskEdit *regD5;
        TMaskEdit *regD1;
        TMaskEdit *regD4;
        TMaskEdit *regD0;
        TMenuItem *OutputFont;
        TAction *FontOutput;
        TLabel *SRflags;
        TLabel *SRlbl;
        TMaskEdit *regSR;
        TMenuItem *View1;
        TMenuItem *OutputWindow1;
        TMenuItem *Stack1;
        TMenuItem *Memory1;
        TMenuItem *N4;
        TMenuItem *LogOutput1;
        TPanel *breakPnl;
        TLabel *Label1;
        TStaticText *cyclesDisplay;
        TMenuItem *BreakPoints1;
        TPaintBox *breakP;
        TMenuItem *Reset1;
        TMenuItem *N3;
        TButton *ClearCycles;
        TLabel *LoggingLbl;
        TToolButton *ToolButton1;
        TMenuItem *N5;
        TMenuItem *ExceptionsEnabled;
        TLabel *HeadingsLbl;
        TAction *Help;
        TMenuItem *Help2;
        TPopupMenu *BreakMenu;
        TMenuItem *ClearAllPCBreakpoints1;
        TToolButton *ToolAutoTrace;
        TAction *AutoTrace;
        TMenuItem *AutoTrace1;
        TMenuItem *N6;
        TMenuItem *SimulatorOptions;
        TTimer *AutoTraceTimer;
        TAction *OpenData;
        TMenuItem *OpenData1;
        TMenuItem *N7;
        TLabel *USlbl;
        TMaskEdit *regUS;
        TMenuItem *Hardware1;
        TAction *RunToCursor;
        TMenuItem *RunToCursor1;
        TToolButton *ToolRunToCursor;
        TToolButton *ToolReload;
        TAction *Reload;
        TMenuItem *Reload1;
        TFontDialog *FontDialogSimIO;
        TFontDialog *FontDialogPrinter;
        TMenuItem *PrinterFont1;
        TAction *FontPrinter;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TMenuItem *N8;
        TMenuItem *PrinterSetup1;
        TMenuItem *N9;
        TMenuItem *mmuFullscreenOptions;
        TToolButton *ToolButton2;
        TToolButton *ToolLogStart;
        TAction *LogStart;
        TAction *LogStop;
        TToolButton *ToolLogStop;
        TMenuItem *N10;
        TMenuItem *LogStart1;
        TMenuItem *LogStop1;
        TOpenDialog *OpenDialogIO;
        TSaveDialog *SaveDialogIO;
        TMenuItem *N11;
        TMenuItem *BitFieldEnabled;
        TMenuItem *N12;
        TMenuItem *OutputWindowSize1;
        TMenuItem *Size640x480;
        TMenuItem *Size800x600;
        TMenuItem *Size1024x768;
        TMenuItem *Size1280x800;
        TMenuItem *Size1280x1024;
        TMenuItem *Size1440x900;
        TMenuItem *Size1680x1050;
        TMenuItem *Size1920x1080;
        TMenuItem *Size1920x1200;
        TMenuItem *OutputWindowTextWrap1;
        TMenuItem *Search1;
        TAction *Search;
        TMenuItem *Search2;
        TMenuItem *N13;
        TMenuItem *GotoPC1;
        TMenuItem *EASyBIN1;
        void  OpenExecute(TObject *Sender);
        void  CloseExecute(TObject *Sender);
        void  ExitExecute(TObject *Sender);
        void  RunExecute(TObject *Sender);
        void  StepExecute(TObject *Sender);
        void  TraceExecute(TObject *Sender);
        void  PauseExecute(TObject *Sender);
        void  RewindExecute(TObject *Sender);
        void  AboutExecute(TObject *Sender);
        void  ListBox1DrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
        void  ScrollBar1Change(TObject *Sender);
        void  FormActivate(TObject *Sender);
        void  FontSourceExecute(TObject *Sender);
        void  FontOutputExecute(TObject *Sender);
        void  FontDialogSourceApply(TObject *Sender, HWND Wnd);
        void  regSRKeyPress(TObject *Sender, char &Key);
        void  Stack1Click(TObject *Sender);
        void  OutputWindow1Click(TObject *Sender);
        void  regKeyPress(TObject *Sender, char &Key);
        void  RegChange(TObject *Sender);
        void  Memory1Click(TObject *Sender);
        void  FormShow(TObject *Sender);
        void  BreakPoints1Click(TObject *Sender);
        void  FormResize(TObject *Sender);
        void  breakPMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void  breakPPaint(TObject *Sender);
        void  ClearCyclesClick(TObject *Sender);
        void  LogOutput1Click(TObject *Sender);
        void  FormClose(TObject *Sender, TCloseAction &Action);
        void  ExceptionsEnabledClick(TObject *Sender);
        void  HelpExecute(TObject *Sender);
        void  ClearAllPCBreakpoints1Click(TObject *Sender);
        void  FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regSRChange(TObject *Sender);
        void  regPCChange(TObject *Sender);
        void  ListBox1DblClick(TObject *Sender);
        void  AutoTraceExecute(TObject *Sender);
        void  AutoTraceTimerTimer(TObject *Sender);
        void  SimulatorOptionsClick(TObject *Sender);
        void  OpenDataExecute(TObject *Sender);
        void  regA7KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regUSKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA8KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA6KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA5KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA4KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA3KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA2KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA1KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  regA0KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  Hardware1Click(TObject *Sender);
        void  RunToCursorExecute(TObject *Sender);
        void  ReloadExecute(TObject *Sender);
        void  FontDialogSimIOApply(TObject *Sender, HWND Wnd);
        void  FontPrinterExecute(TObject *Sender);
        void  PrinterSetup1Click(TObject *Sender);
        void  mmuFullscreenOptionsClick(TObject *Sender);
        void  regPCDblClick(TObject *Sender);
        void  regDblClick(TObject *Sender);
        void  LogStartExecute(TObject *Sender);
        void  LogStopExecute(TObject *Sender);
        void  BitFieldEnabledClick(TObject *Sender);
        void  WindowSizeClick(TObject *Sender);
        void  OutputWindowTextWrap1Click(TObject *Sender);
        void  SearchExecute(TObject *Sender);
        void  GotoPC1Click(TObject *Sender);
        void  EASyBIN1Click(TObject *Sender);
private:	// User declarations
        int startPC;
        void OnDisplayChange(TWMDisplayChange&);
        void  WmDropFiles(TWMDropFiles& Message);     // handle drag-n-drop from explorer

public:		// User declarations
         TForm1(TComponent* Owner);
         ~TForm1();
        void  BringToFront();
        void  OpenFile(AnsiString  name);
        void  setMenuActive();
        void  setMenuInactive();
        void  setMenuTrace();
        void  setMenuTask19();
        void  restoreMenuTask19();
        void  WindowSizeChecked();


        void  loadRegs();
//        void  runLoop(TObject*, bool &done);
        void  runLoop();
        void  highlight();
        void  find(AnsiString  searchStr, bool next);

        bool inline  isInstruction(AnsiString  &str);

        bool  lineToLog();
        void  displayHelp(const char * context);
//        void  RunAfterSTOP();
        void  LoadSettings();
        void  SaveSettings();
        void  defaultSettings();

        // needed for HTML help
        HWND m_hWindow;
        AnsiString  m_asHelpFile;
        DWORD m_Cookie;

/*
        BEGIN_MESSAGE_MAP
          VCL_MESSAGE_HANDLER(WM_DISPLAYCHANGE, TWMDisplayChange, OnDisplayChange);
          // message map for handling drag-n-drop from explorer
          MESSAGE_HANDLER(WM_DROPFILES, TWMDropFiles, WmDropFiles)
        END_MESSAGE_MAP(TForm);
*/
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif
