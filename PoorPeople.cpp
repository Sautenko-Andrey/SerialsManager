#include"PoorPeople.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"


PoorPeople::PoorPeople(const std::string &season,
                                 const std::string &voice)
: Serial(season, voice)
{
    setUrl(m_website_url);
    setSeasonsPrintBehavior(std::make_shared<NoSeasonsPrintBehavior>());
}


const std::string& PoorPeople::who() const {
    return m_serial_full_name;
}