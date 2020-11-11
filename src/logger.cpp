//Author: Hunter Spack
//File: logger.cpp
//Breif: declares functions
#include "logger.h"

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    //get time
    std::string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize -1] = ' ';
    }

    passwd *pws;
    //get pid
    pid_t pid = getpid();

    //get hostname
    //std::string hostNameStr;
    char* hostNameCha;
    gethostname(hostNameCha, _SC_HOST_NAME_MAX);
    //hostNameStr = system("hostname");

    
    if(logFile)
    {
        //write the log
        logFile << strTime << hostNameCha << " " << programName << "[" << pid << "]: " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    


}