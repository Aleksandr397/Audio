#include "Music.h"

int Music::m_id = 0;

Music::Music()
{
    ++m_id;
}

Music::Music(int id)
{
    m_id = id;
}

Music::~Music()
{

}

void Music::setName(const std::string &name)
{
    m_name = name;
}

void Music::setAuthor(const std::string &author)
{
    m_author = author;
}

void Music::setPath(const std::string &path)
{
    m_path = path;
}

std::string Music::getName() const
{
    return m_name;
}

std::string Music::getAuthor() const
{
    return m_author;
}

std::string Music::getPath() const
{
    return m_path;
}

int Music::getId() const
{
    return m_id;
}
