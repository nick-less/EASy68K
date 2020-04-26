#ifndef EXTCTRL_HPP
#define EXTCTRL_HPP

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>

class TCustomPanel : public TCustomControl {

};

class TPanel : public TCustomPanel {

};

class TPaintBox : public TGraphicControl {

};


class TSplitter : public TGraphicControl {

};

class TTimer : public TComponent {
public:
	 bool Enabled = true;
	 unsigned Interval = 10;
};


class TShape : public TGraphicControl {
public:
	TBrush* Brush ;
};

class TCustomRadioGroup : public TCustomGroupBox {

};

class TRadioGroup : public TCustomRadioGroup {
public:
	int ItemIndex = -1;
};

#endif
