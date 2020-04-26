#ifndef MENU_HPP
#define MENU_HPP

#include <Classes.hpp>
#include <Controls.hpp>


class TMenu : public TComponent {

};

class  TMenuItem : public TTextControl {
public:
	bool Checked = false;
};

class TMainMenu : public TMenu {

};

class TPopupMenu : public TMenu {

};


#endif
