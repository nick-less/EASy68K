#ifndef FORMS_HPP
#define FORMS_HPP


#include <sysobj.h>
#include <Classes.hpp>
#include <Controls.hpp>


#define MB_OK 1
#define VK_RETURN 1
#define VK_F1 1
#define VK_TAB 14

class TScrollingWinControl : public TWinControl {

};

class TCustomForm : public TScrollingWinControl {
public:
	 virtual void Show(void);
	 virtual int ShowModal(void);
	 virtual void Close(void);
};

class TMonitor: public TObject {
public:
	unsigned char MonitorNum = 0;
};

class TForm : public TCustomForm {
public:
	TMonitor* Monitor;
	TForm(TComponent *owner);
	virtual void SetFocus(void);
};


class TApplication : public TComponent {
public:
	AnsiString ExeName;
	virtual void ProcessMessages(void) {};
	virtual int MessageBox(const char * Text, const char * Caption, int Flags = 0x0)	{return 0;}

};

#endif
