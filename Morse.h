/* 
 * File:   Morse.h
 * Author: lunelink
 *
 * Created on 16 вересня 2015, 12:39
 */

#ifndef MORSE_H
#define	MORSE_H

#include <fstream>
#include <unordered_map>
#include <iosfwd>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <time.h>

class Morse {
public:
    Morse(std::string file);
    Morse(const Morse& orig);
    
    void Decode(std::string file_name);
    void Create2RandFile(std::string file1, std::string file2);
    
    void Print();
    void Print_Time();
    
    std::string GetResult();
    
    virtual ~Morse();
private:
    void AddInMap(std::string str);
    bool FileOpen(std::ifstream* file_name);
    std::string FileGet(std::ifstream* file_name);
    
    std::unordered_map <std::string,char> map;
    std::string result;
    
    float Decode_Time;
    float AddInMap_Time;
    float Print_time;
    
};

#endif	/* MORSE_H */

