#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <Classes.hpp>


typedef unsigned long TColor;

TColor clRed = 0x00ff0000;
TColor clBlack = 0x00000000;
TColor clWhite = 0x00ffffff;

class TCustomCanvas : public TPersistent {

};





class TGraphicsObject : public TPersistent {
public:
	TColor Color;
};

class  TFont : public TGraphicsObject {
public:
	virtual void  Assign(TPersistent* Source);
};

class TCanvas : public TCustomCanvas {
public:
	TFont *Font;
};

class TGraphic : public TInterfacedPersistent {
public:
	TCanvas* Canvas;
};

class TBitmap : public TGraphic {

};
class TBrush : public TGraphicsObject {

};

#endif
