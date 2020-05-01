#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <string>
#include <sysobj.h>
#include <algorithm>
#define __published public
#define PACKAGE
#define __fastcall
#define WORD unsigned short
#define DWORD unsigned long

#define HWND void*
#define TWMDisplayChange int
#define TWMDropFiles int
#define mbOK 1
#define mtInformation 1
#define mrOk 1
#define mrAll 2

enum class TCloseAction : unsigned char { caNone, caHide, caFree, caMinimize };


enum class  TOwnerDrawState: unsigned char { dsNone };


enum States : unsigned char { ssHorizontal, ssShift, ssCtrl};



// typedef std::set<States> TShiftState ;


typedef unsigned short TShortCut;


class TShiftState  {
public:
	bool Contains(States s) {return false;}
};
class TObject {
private:
public:
  TObject(void);
};


class AnsiString : public std::string {
public:
		AnsiString(std::string s) : std::string( s ) {}
        AnsiString(void) : std::string( "" ) {}
        AnsiString(int i) : std::string( std::to_string(i) ) {}
        AnsiString(const char *s) : std::string( s ) {}
        
        int ToInt() { return std::stoi(*this);}
        AnsiString sprintf ( const char * format, ... ) { }
        AnsiString UpperCase () { AnsiString str; std::transform(str.begin(), str.end(),str.begin(), ::toupper); return str;}
        AnsiString LowerCase () { AnsiString str; std::transform(str.begin(), str.end(),str.begin(), ::tolower); return str;}

        AnsiString SubString(int start, int length) {return *this;}
};

AnsiString ChangeFileExt(const AnsiString FileName, const AnsiString Extension);
class TDateTime {

};
TDateTime Now(void);
AnsiString DateTimeToStr(const TDateTime DateTime);


class TPersistent : public TObject {
};


class TStrings : public TPersistent {
public:
	int Count;
	virtual int Add(const AnsiString S) {};
	virtual void Clear(void) {};
	virtual void LoadFromFile(AnsiString name) {};
	AnsiString Strings[1000];
};



class TInterfacedPersistent : public TPersistent {
};

class TComponent : public TPersistent {
	
};

class TBasicAction : public TComponent {
};




#endif
