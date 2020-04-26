#ifndef SYSOBJ_H
#define SYSOBJ_H

#include <cmath>
#include <inttypes.h>
#define _ALWAYS_INLINE

#define LONG long



class POINT {
public:
 long x,y;
};

class RECT {
public:
long left, top, right, bottom;
};

class tagSIZE {
public:
	long cx, cy;
};

enum TSplitRectType : unsigned char { srLeft, srRight, srTop, srBottom };



struct TSize: public tagSIZE {
  TSize() _ALWAYS_INLINE {
    this->cx = this->cy = 0;
  }
  TSize(const tagSIZE& ts) _ALWAYS_INLINE {
    this->cx = ts.cx;
    this->cy = ts.cy;
  }
  TSize(int32_t x, int32_t y) _ALWAYS_INLINE {
    this->cx = x;
    this->cy = y;
  }
  bool operator ==(const TSize& ts) const _ALWAYS_INLINE {
    return this->cx == ts.cx && this->cy == ts.cy;
  }
  bool operator !=(const TSize& ts) const _ALWAYS_INLINE {
    return !(*this == ts);
  }
  TSize operator +(const TSize& rhs) const _ALWAYS_INLINE {
    return TSize(this->cx + rhs.cx, this->cy + rhs.cy);
  }
  TSize operator -(const TSize& rhs) const _ALWAYS_INLINE {
    return TSize(this->cx - rhs.cx, this->cy - rhs.cy);
  }
  TSize& operator+= (const TSize& rhs) _ALWAYS_INLINE {
      this->cx += rhs.cx;
      this->cy += rhs.cy;
      return *this;
  }
  TSize& operator-= (const TSize& rhs) _ALWAYS_INLINE {
    this->cx -= rhs.cx;
    this->cy -= rhs.cy;
    return *this;
  }
  bool IsZero() const _ALWAYS_INLINE {
    return !cx && !cy;
  }
};


struct TPoint: public POINT  {
  TPoint() _ALWAYS_INLINE
  { x = y = 0; }
  TPoint(int _x, int _y) _ALWAYS_INLINE
  { x=_x; y=_y; }
  bool operator ==(const TPoint& pt) const _ALWAYS_INLINE {
    return (x == pt.x) && (y == pt.y);
  }
  bool operator !=(const TPoint& pt) const _ALWAYS_INLINE {
    return !(pt == *this);
  }
  TPoint operator +(const TPoint& rhs) const _ALWAYS_INLINE {
    return TPoint(rhs.x + this->x, rhs.y + this->y);
  }
  TPoint operator -(const TPoint& rhs) const _ALWAYS_INLINE {
    return TPoint(this->x - rhs.x, this->y - rhs.y );
  }
  TPoint& operator +=(const TPoint& rhs) _ALWAYS_INLINE {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }
  TPoint& operator -=(const TPoint& rhs) _ALWAYS_INLINE {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
  }
  bool IsZero() const _ALWAYS_INLINE {
    return !x && !y;
  }
  bool IsEmpty() const _ALWAYS_INLINE {
    return IsZero();
  }
  void Offset(int DX, int DY) _ALWAYS_INLINE {
    x += DX;
    y += DY;
  }
  void SetLocation(int nX, int nY) _ALWAYS_INLINE {
    x = nX;
    y = nY;
  }
  void SetLocation(const TPoint& p) _ALWAYS_INLINE {
    x = p.x;
    y = p.y;
  }
  double Distance(const TPoint& p2) const _ALWAYS_INLINE {
    return hypot(static_cast<double>(p2.x - this->x), static_cast<double>(p2.y - this->y));
  }
  static int  _sqr(int i) _ALWAYS_INLINE { // Helper - private?
     return i*i;
  }
  bool PtInCircle(const TPoint& CircleCenter, int Radius) const _ALWAYS_INLINE {
    return (Radius > 0) && ((_sqr(CircleCenter.x-x)+_sqr(CircleCenter.y-y)) < _sqr(Radius));
  }
  float Angle(const TPoint& P) const _ALWAYS_INLINE {
    return atan2((float)y - P.y,(float)x - P.x);
  }
};


struct TRect: public RECT  {
  TRect() _ALWAYS_INLINE
  { init(0,0,0,0); }
  TRect(const TPoint& TL) _ALWAYS_INLINE {
    init(TL.x, TL.y, TL.x, TL.y);
  }
  TRect(const TPoint& TL, int width, int height) _ALWAYS_INLINE {
    init (TL.x, TL.y, TL.x + width, TL.y + height);
  }
  TRect(int l, int t, int r, int b) _ALWAYS_INLINE {
    init(l, t, r, b);
  }
  TRect(const TPoint& TL, const TPoint& BR) _ALWAYS_INLINE {
    init(TL.x, TL.y, BR.x, BR.y);
    Normalize();
  }
  TRect(const RECT& r) _ALWAYS_INLINE {
    init(r.left, r.top, r.right, r.bottom);
  }
  void init(int l, int t, int r, int b) _ALWAYS_INLINE {
    left = l; top = t;
    right = r; bottom = b;
  }
  TPoint& TopLeft() _ALWAYS_INLINE
  { return *((TPoint* )this); }
  TPoint& BottomRight() _ALWAYS_INLINE
  { return *((TPoint* )this+1); }
  const TPoint& TopLeft() const _ALWAYS_INLINE
  { return *((TPoint* )this); }
  const TPoint& BottomRight() const _ALWAYS_INLINE
  { return *((TPoint* )this+1); }
  int Width() const _ALWAYS_INLINE
  { return right  - left; }
  int Height() const _ALWAYS_INLINE
  { return bottom - top ; }
  static TRect Empty() _ALWAYS_INLINE
  { return TRect(); }
  void Normalize() _ALWAYS_INLINE {
    if (top > bottom) {
      top = top ^ bottom;
      bottom = top ^ bottom;
      top = top ^ bottom;
    }
    if (left > right) {
      left = left ^ right;
      right = left ^ right;
      left = left ^ right;
    }
  }
  bool operator ==(const TRect& rc) const  {
     return left ==  rc.left  && top==rc.top &&
            right == rc.right && bottom==rc.bottom;
  }
  bool operator !=(const TRect& rc) const {
    return !(rc==*this);
  }
  TRect operator+(const TRect& rc) const _ALWAYS_INLINE {
    return TRect::Union(*this, rc);
  }
  TRect operator*(const TRect& rc) const _ALWAYS_INLINE {
    return TRect::Intersect(*this, rc);
  }
  TRect& operator+=(const TRect& rhs) _ALWAYS_INLINE {
    Union(rhs);
    return *this;
  }
  TRect& operator*=(const TRect& rhs) _ALWAYS_INLINE {
    Intersect(rhs);
    return *this;
  }
  bool IsEmpty() const _ALWAYS_INLINE {
    return (right == left) || (bottom == top);
  }
  bool Contains(const TPoint& p) const _ALWAYS_INLINE {
    return ((p.x >= left) && (p.y >= top) && (p.x < right) && (p.y < bottom));
  }
  bool PtInRect(const TPoint& p) const _ALWAYS_INLINE {
    return Contains(p);
  }
  bool Contains(const TRect& r) const _ALWAYS_INLINE {
    return Contains(r.TopLeft()) && Contains(r.BottomRight());
  }
  bool Overlaps(const TRect &r) const _ALWAYS_INLINE {
    return IntersectsWith(r);
  }
  bool Intersects(const TRect &r) const _ALWAYS_INLINE {
    return IntersectsWith(r);
  }
  bool IntersectsWith(const TRect &r) const _ALWAYS_INLINE {
    return !( (BottomRight().x < r.TopLeft().x) ||
              (BottomRight().y < r.TopLeft().y) ||
              (r.BottomRight().x < TopLeft().x) ||
              (r.BottomRight().y < TopLeft().y) );
  }
  static TRect Intersect(const TRect &r1, const TRect &r2);
  void Intersect(const TRect &r);
  void Union(const TRect &r);
  static TRect Union(const TRect &r1, const TRect& r2);
  static TRect Union(const TPoint* points, int npoints) _ALWAYS_INLINE {
    TPoint tl, br;
    if (npoints > 0) {
      tl.SetLocation(points[0]);
      br.SetLocation(points[0]);
      for (int i = npoints; --i > 0;) {
        if (points[i].x < tl.x)     tl.x = points[i].x;
        if (points[i].x > br.x)     br.x = points[i].x;
        if (points[i].y < tl.y)     tl.y = points[i].y;
        if (points[i].y > br.y)     br.y = points[i].y;
      }
    }
    return TRect(tl, br);
  }
  bool  IntersectRect(const TRect &R1, const TRect &R2);
  bool  UnionRect(const TRect &R1, const TRect &R2);
  void Offset(int DX, int DY) _ALWAYS_INLINE {
    left   += DX;
    right  += DX;
    top    += DY;
    bottom += DY;
  }
  void Offset(const TPoint& p) _ALWAYS_INLINE { Offset(p.x, p.y); }
  void SetLocation(int X, int Y) _ALWAYS_INLINE {
      Offset(X - left, Y - top);
  }
  void SetLocation(const TPoint& p) _ALWAYS_INLINE {
      Offset(p.x - left, p.y - top);
  }
  void Inflate(int DX, int DY) _ALWAYS_INLINE {
    left   -= DX;
    right  += DX;
    top    -= DY;
    bottom += DY;
  }
  void Inflate(int l, int t, int r, int b) _ALWAYS_INLINE {
    left   -= l;
    right  += r;
    top    -= t;
    bottom += b;
  }
  void NormalizeRect() _ALWAYS_INLINE {
    int i;
    if (left > right)
    {
      i = left;
      left = right;
      right = i;
    }
    if (top > bottom)
    {
      i = top;
      top = bottom;
      bottom = i;
    }
  }
  TPoint CenterPoint() const _ALWAYS_INLINE {
    return TPoint((left+right)/2, (top+bottom)/2);
  }
  TRect CenteredRect(const TRect &CenteredRect) const _ALWAYS_INLINE {
    int w = CenteredRect.Width();
    int h = CenteredRect.Height();
    int x = (right + left)/2;
    int y = (top + bottom)/2;
    return TRect(x-w/2, y-h/2, x+(w+1)/2, y+(h+1)/2);
  }
  TRect SplitRect(TSplitRectType SplitType, int Size) const;
  TRect SplitRect(TSplitRectType SplitType, double Percent) const;
#if defined(_Windows)
  bool SubtractRect(const TRect &R1, const TRect &R2) _ALWAYS_INLINE {
    return ::SubtractRect(this, &R1, &R2) != 0;
  }
#endif
  long GetWidth() const _ALWAYS_INLINE {
    return right - left;
  }
  void SetWidth(LONG width) _ALWAYS_INLINE {
    right = left + width;
  }
  long GetHeight() const _ALWAYS_INLINE {
    return bottom - top;
  }
  void SetHeight(LONG height) _ALWAYS_INLINE {
    bottom = top + height;
  }
  TSize GetSize() const _ALWAYS_INLINE {
    TSize r;
    r.cx = GetWidth();
    r.cy = GetHeight();
    return r;
  }
  void SetSize(const TSize& newSize) _ALWAYS_INLINE {
    SetWidth(newSize.cx);
    SetHeight(newSize.cy);
  }
  TPoint GetLocation() const _ALWAYS_INLINE {
    return TPoint(left, top);
  }
};


#endif

