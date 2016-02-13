#pragma once

#include <cmath>
#include <map>

class Circle {
 public:
  /** コンストラクタ*/
  Circle();

  /** 円の半径を設定する*/
  void setScale(double tScale);

  /** 円の中心座標を設定する*/
  void setPosition(double tX, double tY, double tZ);

  /** 円を表示する*/
  void display();

 protected:
  class Vertices : public std::multimap<double, double> {
   public:
    Vertices(int num);
  };

  int countFromPositionSetting;
  int countFromScaleSetting;
  double srcX, srcY, srcZ, dstX, dstY, dstZ, srcScale, dstScale;
  static int num;
  static Vertices vertices;
};
