//---------------------------------------------------------------------------

#ifndef findDialogSH
#define findDialogSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SIM68Ku.h"
//---------------------------------------------------------------------------
class TfindDialogFrm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *findText;
        TButton *findNextBtn;
        TButton *cancelBtn;
        void  findNextBtnClick(TObject *Sender);
        void  cancelBtnClick(TObject *Sender);
        void  findTextChange(TObject *Sender);
        void  FormShow(TObject *Sender);
        void  FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
        bool    findNext;
public:		// User declarations
         TfindDialogFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfindDialogFrm *findDialogFrm;
//---------------------------------------------------------------------------
#endif
