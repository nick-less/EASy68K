#ifndef CONTROLS_HPP
#define CONTROLS_HPP



#include <string>
#include <Classes.hpp>
#include <ImgList.hpp>

#include <Graphics.hpp>

enum class TMouseButton : unsigned char { mbLeft, mbRight, mbMiddle };

class TControl : public TComponent {
public:

	 AnsiString Caption;
	 bool Visible = true;
	 bool Enabled = true;
	 TFont *Font;
	 int StrToInt(std::string s) { return std::stoi(s);}

	 virtual void Show(void);
	 virtual void Hide(void);

};

class TWinControl : public TControl {
public:
	virtual void Repaint(void);

};


class TStyledControl : public TControl {

};

class TGraphicControl : public TControl {

};

class TToolButton : public TGraphicControl {

};


class TCustomControl : public TWinControl {

};

class TTextControl : public TStyledControl {

};

class TDragImageList : public TCustomImageList {

};

class TImageList : public TDragImageList {

};



class TCustomListControl : public TWinControl {
public:
	int ItemIndex = -1;
};

class TCustomMultiSelectListControl : public TCustomListControl {

};




#endif
