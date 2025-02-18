#include"PoorPeople.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"



PoorPeople::PoorPeople(std::string season, std::string voice)
:
Serial(std::move(season), std::move(voice))
{
    setUrl(m_website_url);
    setSeasonsPrintBehavior(std::make_unique<NoSeasonsPrintBehavior>());
}


const std::string& PoorPeople::who() const {
    return m_serial_full_name;
}