//Author: Hunter Spack
//File: logger.h
//Breif: declares functions
#ifndef LOGGER_H
#define LOGGER_H

#include<string>
#include<fstream>
#include<pwd.h>

#define _X_OPEN_SOURCE >= 500;

#include<unistd.h>
#include<libgen.h>

//pre a message a program name and a log file stream
//post the info is logged
//purpose to log what was passed into program
bool log(std::string msg, std::string programName, std::ofstream& logFile);

#endif