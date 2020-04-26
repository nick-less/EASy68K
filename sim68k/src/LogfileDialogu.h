//---------------------------------------------------------------------------

#ifndef LogfileDialoguH
#define LogfileDialoguH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TLogfileDialog : public TForm
{
__published:	// IDE-managed Components
        TLabel *Message;
        TButton *OkBtn;
        TButton *AllBtn;
        TButton *CancelBtn;
private:	// User declarations
public:		// User declarations
        TLogfileDialog(TComponent* Owner);
        void setMessage(AnsiString str);

};
//---------------------------------------------------------------------------
extern PACKAGE TLogfileDialog *LogfileDialog;
//---------------------------------------------------------------------------
#endif
