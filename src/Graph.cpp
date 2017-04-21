#include "/root/Documents/Biometria/FaRe/include/Graph.h"

Graph::Graph(Mat image, int margin)
{
  this->image=image;
  this->margin=margin;
  visited=new bool*[image.rows];
  for (int i=0;i<image.rows;i++)
    visited[i]=new bool[image.cols];
  MakeGraph();
}

void Graph::MakeGraph(void)
{
  stack<pair<int,int>> s;
  for (int i=0;i<image.rows;i++)
  {
    for (int j=0;j<image.cols;j++)
    {
      if (!visited[i][j])
      {
        vertices.push_back(DFS(i,j));
        cout << vertices.size() << "Number of blobs \n";
      }
    }
  }
}

bool Graph::isMarginCloseEnough(Vec3b currentBlobIntensity, Vec3b candidateIntensity)
{
  return (
           abs(currentBlobIntensity.val[0] - candidateIntensity.val[0])<= margin &&
           abs(currentBlobIntensity.val[1] - candidateIntensity.val[1])<= margin &&
           abs(currentBlobIntensity.val[2] - candidateIntensity.val[2])<= margin
          );
}

bool Graph::ValidBoundries(int x,int y)
{
  return x>=0 && x<image.rows && y>=0 && y<image.cols;
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
                && !visited[currentVertex.first+i][currentVertex.second+j]
                && isMarginCloseEnough(image.at<Vec3b>(currentVertex.first,currentVertex.second),image.at<Vec3b>(currentVertex.first+i,currentVertex.second+j)))
                s.push(pair<int,int>(currentVertex.first+i,currentVertex.second+j));
        }
      }
  }
  return blob;
}
