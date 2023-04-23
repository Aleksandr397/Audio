#pragma once
#include <string>

class Music
{
public:
    Music();
    Music(int id);
    ~Music();
public:
    void setName(const std::string &name);
    void setAuthor(const std::string &author);
    void setPath(const std::string &path);

    std::string getName() const;
    std::string getAuthor() const;
    std::string getPath() const;
    int getId() const;


private:
    std::string m_name;
    std::string m_author;
    std::string m_path;
    static int m_id;
};
