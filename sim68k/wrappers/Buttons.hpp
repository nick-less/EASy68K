#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include <Controls.hpp>
#include <StdCtrls.hpp>


enum TButtonLayout : unsigned char { blGlyphLeft, blGlyphRight, blGlyphTop, blGlyphBottom };

class TBitBtn : public TCustomButton {
public:
	TButtonLayout Layout;
};

class TSpeedButton : public TGraphicControl {

};

class TCSpinButton : public TCustomButton {

};

#endif
