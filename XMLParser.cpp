#include <iostream>

#include "XMLParser.h"

XMLParser::XMLParser()
{
}

std::vector<Segment> XMLParser::loadSegment(const char *pathTofile)
{
    std::vector<Segment> segment;

    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(pathTofile) == tinyxml2::XML_SUCCESS)
    {
        tinyxml2::XMLElement *root = doc.FirstChildElement("Segments");

        if (root)
        {
            for (tinyxml2::XMLElement *elem = root->FirstChildElement("Segment"); elem != nullptr;
                 elem = elem->NextSiblingElement("Segment"))
            {
                float x1 = elem->FloatAttribute("x1");
                float y1 = elem->FloatAttribute("y1");
                float z1 = elem->FloatAttribute("z1");

                float x2 = elem->FloatAttribute("x2");
                float y2 = elem->FloatAttribute("y2");
                float z2 = elem->FloatAttribute("z2");

                segment.emplace_back(x1, y1, z1, x2, y2, z2);
            }
        }
    }

    else
    {
        std::cout << "Xml file loading error\n";
    }

    return segment;
}
