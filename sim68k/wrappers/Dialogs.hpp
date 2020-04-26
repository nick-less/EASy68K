#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <Classes.hpp>
#include <Graphics.hpp>

class TCommonDialog : public TComponent {
public:
	bool Execute(void);
};

class TFontDialog : public TCommonDialog {
public:
	 TFont* Font ;
};

class TOpenDialog : public TCommonDialog {

};


class TSaveDialog : public TOpenDialog {
public:
	AnsiString FileName;

};

class TPrinterSetupDialog : public TCommonDialog {

};


#endif
