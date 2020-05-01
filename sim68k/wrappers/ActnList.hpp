#ifndef ACTNLIST_HPP
#define ACTNLIST_HPP

#include <Actions.hpp>

class TCustomAction : public TContainedAction {

};

class TAction : public TCustomAction {
public:
	bool Enabled = true;
	int ShortCut = 0;
};

class TCustomActionList : public TContainedActionList {

};

class TActionList : public TCustomActionList {

};

#endif
