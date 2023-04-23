#include "Program.h"
#include "EventListener.h"
#include "LoadMusic.h"

#include <fstream>
#include <iostream>


const std::string dbPath = "./musicdb.txt";

void Program::run()
{   
    init();
    EventListener listener;
    Music* tmp = LoadMusic::load("user/music/erg6");
    m_musicMap.insert(std::make_pair(tmp->getId(), tmp));
    /* for(auto [id, music] : m_musicMap)
    {
        std::cout << id << " : " << music->getPath() << std::endl;
    } 
    */

    while(true)
    {
        listener.listen();
    } 
}


void Program::loadDB()
{
    std::ifstream ifs;
    try
    {
        ifs.open(dbPath);
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    while(!ifs.eof())
    {
        std::string musicPath;
        ifs >> musicPath;
        if(musicPath.empty())
        {
            continue;
        }
        Music* p_newMusic = new Music();
        p_newMusic->setPath(musicPath);

        m_musicMap.insert(std::make_pair(p_newMusic->getId(), p_newMusic));

    }
    ifs.close();
}

Program::Program()
{
}

Program::~Program()
{
    std::ofstream ofs;
    ofs.exceptions(std::ifstream::failbit |
                    std::ifstream::badbit);

    try
    {
        ofs.open(dbPath);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for(auto [id, music] : m_musicMap)
    {
        ofs << music->getPath() << "\n";
    }

    ofs.close();

    for(auto [id, music] : m_musicMap)
    {
        delete music;
    }
}

void Program::init()
{
    loadDB();
}
