#ifndef MASK_HPP
#define MASK_HPP


#include <Classes.hpp>
#include <StdCtrls.hpp>


class TCustomMaskEdit : public TCustomEdit {

};


class TMaskEdit : public TCustomMaskEdit {
public:
	AnsiString EditText;
	AnsiString Text;

};


#endif
