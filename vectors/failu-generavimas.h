#ifndef FAILU_GENERAVIMAS_H
#define FAILU_GENERAVIMAS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#include <ctime>
#include <cstdlib>
#include "vektoriai.h"
#include "student.h"

using namespace std;

void writeCategorizedStudents(const vector<Student>& students, const string& filename);
void generateFiles();
void sortAndWriteToFile(const string& inputFilename);
void generatingFinal();

#endif
