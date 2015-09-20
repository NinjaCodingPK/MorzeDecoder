#include <vector>

#include "Morse.h"

Morse::Morse(std::string file) 
{
    this->AddInMap(file);
    this->Print_time = 0;
    this->AddInMap_Time = 0;
    this->Decode_Time = 0;
}

Morse::Morse(const Morse& orig) 
{
    this->map = orig.map;
}

void Morse::AddInMap(std::string str)
{
    float  StartTime = (float)clock()/CLOCKS_PER_SEC;
    std::string part1;
    std::string part2;
    
    std::ifstream file(str.c_str());
    
    char sep = ';';
    
    while(!file.eof())
    {
        getline (file , part1, ';');
        getline (file , part2, '\n');
        this->map.insert(std::pair<std::string, char>(part1, (char)part2.c_str()[0]));   
    }  
    AddInMap_Time = ((float)clock()/CLOCKS_PER_SEC) - StartTime;
    
}

bool Morse::FileOpen(std::ifstream* file_name)
{
    if(file_name->is_open()) 
        return true;
    return false;
}

std::string Morse::FileGet(std::ifstream* file_name)
{
   std::string buf; 
   
   getline (*file_name , buf, ' ');
   return buf;
}

void Morse::Decode(std::string file_name)
{
    float  StartTime = (float)clock()/CLOCKS_PER_SEC;
    result.clear();
    
    //if(access(file_name, 0) != -1)
    std::ifstream file(file_name.c_str());
    
    if(this->FileOpen(&file))
    {
        //std::string buf;
    
        while(!file.eof())
        {
            //getline (file , buf, ' ');
            result += map[this->FileGet(&file)];
        }
        Decode_Time = ((float)clock()/CLOCKS_PER_SEC) - StartTime;
    }
}

void Morse::Print_Time()
{
    std::cout<< AddInMap_Time<<std::endl;
    std::cout<< Decode_Time<<std::endl;
    std::cout<< Print_time<<std::endl;
}

void Morse::Print()
{
    std::ofstream fout;
    fout.open("output.txt");
    
    float  StartTime = (float)clock()/CLOCKS_PER_SEC;
    fout << result;
    Print_time = ((float)clock()/CLOCKS_PER_SEC) - StartTime;
    
    fout << EOF; 
    fout.close();
    
}

std::string Morse::GetResult()
{
    return this->result;
}

Morse::~Morse() 
{
    map.clear();
    result.clear();
}

