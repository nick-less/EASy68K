#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <Classes.hpp>
#include <Graphics.hpp>

 int  MessageDlg(const AnsiString Msg, int DlgType, int Buttons, int HelpCtx);
void  ShowMessage(const AnsiString Msg);

class TCommonDialog : public TComponent {
public:
	bool Execute(void);
};

class TFontDialog : public TCommonDialog {
public:
	 TFont* Font ;
};

class TOpenDialog : public TCommonDialog {
public:
	AnsiString FileName;

};


class TSaveDialog : public TOpenDialog {
public:
	AnsiString FileName;

};

class TPrinterSetupDialog : public TCommonDialog {

};


#endif
