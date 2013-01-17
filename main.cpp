#include <iostream>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "objparser.h"

using namespace std;
using namespace pcl;

int main()
{
  OBJParser obj("B10_50.obj");

  cout << "obj parsed" << endl;

  PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

  vector<Vector3d> points = obj.getVertexVec();
  for(int i = 0; i < (int)points.size(); ++i)
  {
    PointXYZ point((double)rand() / (double)RAND_MAX,
                   (double)rand() / (double)RAND_MAX,
                   (double)rand() / (double)RAND_MAX);
    cloud->push_back(point);
  }

  boost::shared_ptr<visualization::PCLVisualizer> viewer(new visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor(0, 0, 0);
  viewer->addPointCloud<PointXYZ>(cloud, "sample cloud");
  viewer->addCoordinateSystem(1.0);
  viewer->initCameraParameters();

  while(!viewer->wasStopped())
  {
    viewer->spinOnce();
  }

  return 0;
}
