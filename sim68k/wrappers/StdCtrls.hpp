#ifndef STDCTRLS_HPP
#define STDCTRLS_HPP

#include <Controls.hpp>
#include <Presentation.hpp>

class TCustomGroupBox : public TCustomControl {

};

class TGroupBox : public TCustomGroupBox {

};

class TPresentedTextControl: public TPresentedControl {

};

class TLabel: public TPresentedTextControl {

};

class TCustomEdit: public TWinControl {

};

class TEdit: public TCustomEdit {
public:
	AnsiString Text;
};
class TCustomButton: public TPresentedTextControl {

};

class TButton: public TCustomButton {

};


class TCustomListBox : public TCustomMultiSelectListControl {

};

class TListBox : public TCustomListBox {
public:
	TStrings *Items;
};


class TCustomStaticText : public TWinControl {

};

class TStaticText : public TCustomStaticText {

};

class TScrollBar : public TWinControl {

};

class TCustomMemo : public TCustomEdit {
public:
	TStrings *Lines;
};

class TMemo : public TCustomMemo {

};

class TButtonControl : public TWinControl {

};

class TCustomCheckBox : public TButtonControl {

};

class TCheckBox : public TCustomCheckBox {
public:
	bool Checked = false;

};

class TCustomCombo : public TCustomListControl {

};

class TCustomComboBox : public TCustomCombo {

};

class TComboBox : public TCustomComboBox {

};

#endif
