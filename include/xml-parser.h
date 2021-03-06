#ifndef _XML_PARSER_H_
#define _XML_PARSER_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "tinyxml2.h"
#include "raster.h"
#include "line.h"
#include "circle.h"
#include "polyline.h"
#include <boost/algorithm/string.hpp>

// Define exceptions
#define INVALID_CANVAS "Invalid canvas specification"
#define INVALID_SHAPE  "Invalid shape specification"
#define INVALID_CIRCLE "Invalid circle specification"
#define INVALID_LINE "Invalid line specification"
#define INVALID_POLYLINE "Invalid polyline specification"

using namespace tinyxml2;

/**
 * @brief Parse and interprets a xml archive
 * @param filename the filename
 */
void parser_xml (std::string filename, std::string imagename);

/**
 * @brief Create a circle object of a xml declaration
 * 
 * @param circle The object circle for creation
 * @param element The element xml with the description circle
 */
void create_circle (Circle *&circle, XMLElement *element );

/**
 * @brief Create a line object
 * 
 * @param line the line object
 * @param element the xml element
 */
void create_line (Line *&line, XMLElement *element );

/**
 * @brief Create a polyline object
 * 
 * @param polyline the polyline object
 * @param element the xml element
 */
void create_polyline (Polyline *&polyline, XMLElement *element);

/**
 * @brief parser a points string in a vector of points
 * 
 * @param points the string points for parsee
 * @return std::vector<POINT> 
 */
std::vector<POINT> parser_many_points (std::string points);

#endif