#pragma once
#include <map>
#include "Music.h"

class Program
{
public:
    void run();

private:
    void init();
    void loadDB();
public:
    Program();
    ~Program();
private:
    std::map<int, Music*> m_musicMap;
};
