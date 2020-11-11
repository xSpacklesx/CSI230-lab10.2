//Author: Hunter Spack
//File: earth_utils.h
//Breif: defines constants and declares functions
#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H

#include <string>
#include <fstream>

//constansts for KML doc
const std::string KMLHEADER = "<?xml version='1.0' encoding='UTF-8'?>\n<kml xmlns='http://www.opengis.net/kml/2.2'>\n<Document>\n";
const std::string KMLFOOTER = "</Document>\n</kml>";

//pre in file stream and kml file name
//post csv is read and a kml file is made, returns number of records read in csv
//purpose read csv 
int processCSV(std::ifstream& inFile, std::string kmlFileName);


//pre kml file stream and data for the kml file
//post a kml placemark is made
//purpose to make a kml file
void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitutde);

#endif