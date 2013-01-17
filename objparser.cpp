#include "objparser.h"

OBJParser::OBJParser()
{
}

OBJParser::OBJParser(const string &file_name)
{
  setObj(file_name);
}

void OBJParser::setObj(const string &file_name)
{
  obj_parser parser;

  function<void (float_type, float_type, float_type)> f;
  f = bind(&OBJParser::setVertex, this, _1, _2, _3);
  parser.geometric_vertex_callback(f);

  function<void (index_type, index_type, index_type)> g;
  g = bind(&OBJParser::setFace, this, _1, _2, _3);
  parser.face_callbacks(g, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

  if(parser.parse(file_name))
  {
    max = getVertex(0);
    min = getVertex(0);

    int vnum = getVertexNum();

    vertex_vec.resize(vnum * 3);
    for(int i = 0; i < vnum; ++i)
    {
      for(int j = 0; j < 3; ++j)
      {
        vertex_vec(i * 3 + j) = getVertex(i)(j);

        if(max(j) < vertex_vec(i * 3 + j))
          max(j) = vertex_vec(i * 3 + j);
        if(min(j) > vertex_vec(i * 3 + j))
          min(j) = vertex_vec(i * 3 + j);
      }
    }
  }
  else
    cerr << "OBJ File Parsing Failed" << endl;
}

int OBJParser::getVertexNum()
{
  return vertices.size();
}

Vector3d OBJParser::getVertex(int num)
{
  return vertices.at(num);
}

VectorXd OBJParser::getVertices()
{
  return vertex_vec;
}

VectorXd OBJParser::getVertices(const int vertex_num)
{
  // limit番目の頂点を取り出す
  VectorXd vec(vertex_num * 3);
  for(int i = 0; i < vec.rows(); ++i)
  {
    vec(i) = vertex_vec(i);
  }
  return vec;
}

vector<Vector3d> OBJParser::getVertexVec()
{
  return vertices;
}

vector<Vector3i> OBJParser::getFaces()
{
  return faces;
}

Vector3d OBJParser::getMax()
{
  return max;
}

Vector3d OBJParser::getMin()
{
  return min;
}

void OBJParser::setVertex(const float_type x, const float_type y, const float_type z)
{
  Vector3d v(x, y, z);
  vertices.push_back(v);
}

void OBJParser::setFace(const index_type v1, const index_type v2, const index_type v3)
{
  Vector3i f(v1 - 1, v2 - 1, v3 - 1);
  faces.push_back(f);
}
