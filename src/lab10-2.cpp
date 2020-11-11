//Author: Hunter Spack
//File: lab10-2.cpp
//Breif: Main for making KML file from csv
#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "earth_utils.h"
#include "logger.h"

using namespace std;

int main(int argc, char* argv[])
{
    //define vars
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string logValue;
    string kmlValue;
    bool optErr = true;

    //check command line args
    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch (opt)
        {
        //csv file
        case 'k':
            kmlFlag = true;
            kmlValue = optarg;         
            break;

        //log file
        case 'l':
            logFlag = true;
            logValue = optarg;
        
        default:
            optErr = true;
            break;
        }

    }

  
    if(kmlFlag && logFlag)
    {
        cout << "flag set" << endl;
        if(logValue.empty() || kmlValue.empty())
        {
            optErr = true;
            cout << "options args aren't set" << endl;
        }
        else
        {
            //logs info
            ofstream flog;
            flog.open(logValue, ios_base::app);
            if(flog)
            {
                std::string programName = basename(argv[0]);
                std::string msg = "The kmlfile is:" + kmlValue + " and logfile is:" + logValue;

                log(msg, programName, flog);

                optErr = false;
                flog.close();
            }
            //process csv
            ifstream inFile;
            inFile.open(kmlValue);
            if (inFile)
            {
                int recordCount = processCSV(inFile, kmlValue + ".kml");
                inFile.close();
                if(recordCount)
                {
                cout << recordCount << " records processed" << endl;
                optErr = false;
                }
                else
                {
                    optErr = true;
                }
                
            }
            
            else 
            {
                cout << "Couldn't open file: " << logValue << endl;
                optErr = true;
            }
        }
    

    }
    else
    {
        cout << "error flags not set" << endl;
        optErr = true;
    }

    if(optErr)
    {
        return EXIT_FAILURE;
    }



    cout << "kml flag:" << kmlFlag << endl << "log flag:" << logFlag << endl;
    cout << "kml file:" << kmlValue << endl << "log file:" << logValue << endl;
    cout << "error:" << optErr << endl;
    

    return EXIT_SUCCESS;
}