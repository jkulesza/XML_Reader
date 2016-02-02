#include "pugixml.hpp"
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

std::vector<double> getVertexIndices(std::string const& pointLine)
{
  std::istringstream iss(pointLine);

  return std::vector<double>{ 
    std::istream_iterator<double>(iss),
    std::istream_iterator<double>()
  };
}


int main()
{

  cout.precision(3);

  pugi::xml_document doc;
  if (!doc.load_file("tree2.xml")) return -1;
  pugi::xml_node scalars = doc.child("input").child("scalars");
  string xmesh = doc.child("input").child_value("xmesh");

  cout << scalars.child_value("author") << endl;
  cout << scalars.child_value("title") << endl;
  cout << scalars.child_value("genre") << endl;
  cout << scalars.child_value("price") << endl;
  cout << scalars.child_value("publish_date") << endl;

  cout << xmesh << endl;  

  vector<double> test = getVertexIndices(xmesh);

  for(int i = 0; i < test.size(); i++) {
    cout << test[i] << endl;
  }

}
