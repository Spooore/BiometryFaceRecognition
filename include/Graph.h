//Graph.h
#ifndef Graph_H
#define Graph_H

#include <cstdio>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;
using namespace cv;

class Graph
{
private:
  Mat image;
  int margin;
  vector<vector<int>> edges;
  vector<vector<pair<int,int>>> vertices;
  bool** visited;
  void MakeGraph(void);
  vector<pair<int,int>> DFS(int,int);
  bool isMarginCloseEnough(Vec3b currentBlobIntensity,Vec3b candidateIntensity);
public:
  Graph(Mat image,int margin);
  bool ValidBoundries(int x,int y);
};


#endif
