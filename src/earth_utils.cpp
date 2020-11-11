//Author: Hunter Spack
//File: earth_utils.cpp
//Breif: defines functions
#include "earth_utils.h"
#include <sstream>

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    int recordsWrit = 0;
    std::string strCountry, strCapital, strLat, strLong, strName;
    std::string strLine;

    std::ofstream kmlOut;
    kmlOut.open(kmlFileName, std::ios_base::app);
    if (kmlOut)
    {
        kmlOut << KMLHEADER;
    }
    kmlOut.close();

    if (inFile)
    {
        std::getline(inFile, strLine);
    
        while(std::getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            std::getline(s_stream, strCountry, ',');
            std::getline(s_stream, strCapital, ',');
            std::getline(s_stream, strLat, ',');
            std::getline(s_stream, strLong, ',');
            strName = strCapital + ", " + strCountry; 
            kmlOut.open(kmlFileName, std::ios_base::app);
            if (kmlOut)
            {
                writePlacemark(kmlOut,strName, strLat, strLong);
                recordsWrit++;
            }
            kmlOut.close();
            
        }
        kmlOut.open(kmlFileName, std::ios_base::app);
        if (kmlOut)
        {
            kmlOut << KMLFOOTER;
        }
        kmlOut.close();
        return recordsWrit;
    }
    else
    {
        return recordsWrit;
    }
    




}

void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitutde)
{
    kmlFile << "<Placemark>\n";
    kmlFile << "<name>" << name << "</name>\n";
    kmlFile << "<Point><coordinates>" << longitutde << "," << latitude << "</coordinates></Point>\n";
    kmlFile << "</Placemark>\n"; 
}
