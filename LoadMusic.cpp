#include "LoadMusic.h"

Music *LoadMusic::load(const std::string &MusicPath)
{
        Music *p_newMusic = new Music();
        p_newMusic->setPath(MusicPath);

        
    return p_newMusic;
}