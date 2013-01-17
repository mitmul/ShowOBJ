#ifndef OBJPARSER_H
#define OBJPARSER_H

#include <string>
#include <vector>
#include <obj.hpp>
#include <Eigen/Eigen>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace Eigen;
using namespace boost;
using namespace obj;

class OBJParser
{
  public:
    OBJParser();
    OBJParser(const string &file_name);

    void setObj(const string &file_name);

    int getVertexNum();
    Vector3d getVertex(int num);
    VectorXd getVertices();
    VectorXd getVertices(const int vertex_num);
    vector<Vector3d> getVertexVec();
    vector<Vector3i> getFaces();

    Vector3d getMax();
    Vector3d getMin();

  private:
    // 両者とも0から
    void setVertex(const float_type x, const float_type y, const float_type z);
    void setFace(const index_type v1, const index_type v2, const index_type v3);

    string file_name;
    vector<Vector3d> vertices;
    vector<Vector3i> faces;
    VectorXd vertex_vec;

    Vector3d max;
    Vector3d min;
};

#endif // OBJPARSER_H
