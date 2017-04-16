#include "/root/Documents/Biometria/FaRe/include/Graph.h"

Graph::Graph(Mat image, int margin)
{
  this->image=image;
  this->margin=margin;
  visited=new bool*[image.rows];
  for (int i=0;i<image.rows;i++)
    visited[i]=new bool[image.cols];
}

void Graph::MakeGraph(void)
{
  stack<pair<int,int>> s;
  for (int i=0;i<image.rows;i++)
  {
    for (int j=0;j<image.cols;j++)
    {
      if (!visited[i][j])
      DFS(i,j);
    }
  }
}

bool Graph::ValidBoundries(int x,int y)
{
  return x>=0 && x<image.cols && y>=0 && y<image.rows;
}

vector<pair<int,int >> Graph::DFS(int pX,int pY)
{
  vector<pair<int,int>> blob;
  stack<pair<int,int>> s;
  s.push(pair<int,int>(pX,pY));
  while(!s.empty())
  {
      auto currentVertex = s.top();
      s.pop();
      visited[currentVertex.first][currentVertex.second]=true;
      blob.push_back(currentVertex);

      for (int i=-1;i<=1;i++)
      {
        for(int j=-1;j<=1;j++)
        {
            if (ValidBoundries(currentVertex.first+i, currentVertex.second+j)
              && !visited[currentVertex.first+i][currentVertex.second+j])
            s.push(pair<int,int>(currentVertex.first+i,currentVertex.second+j));
        }
      }
  }
  return blob;
}
