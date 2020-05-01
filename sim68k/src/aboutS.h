//----------------------------------------------------------------------------
#ifndef aboutSH
#define aboutSH
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TAboutFrm : public TForm
{
__published:
	TPanel *Panel1;
	TImage *ProgramIcon;
        TLabel *Title;
	TLabel *Copyright;
	TLabel *Comments;
	TButton *OKButton;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label4;
        void  FormShow(TObject *Sender);
        void  FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:
public:
	virtual  TAboutFrm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAboutFrm *AboutFrm;
//----------------------------------------------------------------------------
#endif    
