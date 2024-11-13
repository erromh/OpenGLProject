//
// XMLParser.h
//
// Описание: данный класс отвечает за чтение XML-файла и загрузку координат, направлений и длин отрезков.
//

#pragma once
#include <string>
#include <vector>

#include "Segment.h"
#include "libs/tinyxml2/tinyxml2.h"

class XMLParser
{
  private:
    std::string _pathTofile;

  public:
    XMLParser();

    static std::vector<Segment> loadSegment(const char *pathTofile);
};
