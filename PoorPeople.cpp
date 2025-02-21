#include"PoorPeople.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"



PoorPeople::PoorPeople(const std::string &season, const std::string &lang)
:
Serial(season, lang)
{
    setUrl(m_website_url);
    setSeasonsPrintBehavior(std::make_unique<NoSeasonsPrintBehavior>());
}


const std::string& PoorPeople::who() const {
    return m_serial_full_name;
}