//---------------------------------------------------------------------------

#ifndef logUH
#define logUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TLog : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *ELogType;
        TEdit *ELogFileName;
        TLabel *Label1;
        TButton *OKBtn;
        TBitBtn *ELogOpenBtn;
        TSaveDialog *ELogSaveDlg;
        TRadioGroup *OLogType;
        TEdit *OLogFileName;
        TBitBtn *OLogOpenBtn;
        TLabel *Label2;
        TSaveDialog *OLogSaveDlg;
        TGroupBox *MemRange;
        TLabel *MemLbl2;
        TMaskEdit *MemFrom;
        TLabel *MemLbl3;
        TMaskEdit *MemBytes;
        TButton *CancelBtn;
        void  ELogOpenBtnClick(TObject *Sender);
        void  OKBtnClick(TObject *Sender);
        void  CancelBtnClick(TObject *Sender);
        void  OLogOpenBtnClick(TObject *Sender);
        void  FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void  ELogTypeClick(TObject *Sender);
        void  MemFromKeyPress(TObject *Sender, char &Key);
        void  MemFromExit(TObject *Sender);
        void  FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
         TLog(TComponent* Owner);
        void  setLogFileNames(AnsiString name);
        void  prepareLogFile();
        void  stopLog();
        void  stopLogWithAnnounce();
        void  startLog();
        void  addMessage(AnsiString msg);


};
//---------------------------------------------------------------------------
extern PACKAGE TLog *Log;
//---------------------------------------------------------------------------
#endif
