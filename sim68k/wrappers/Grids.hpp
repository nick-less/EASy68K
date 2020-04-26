#ifndef GRIDS_HPP
#define GRIDS_HPP

#include <Controls.hpp>

class  TCustomGrid : public TCustomControl {

};

class TCustomDrawGrid : public TCustomGrid {

};

class  TDrawGrid : public TCustomDrawGrid {

};

class TStringGrid : public TDrawGrid {

};


#endif
