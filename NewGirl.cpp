#include"NewGirl.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"



NewGirl::NewGirl(std::string season, std::string lang)
:
Serial(std::move(season), std::move(lang))
{
    setUrl(m_website_url);

    setSeasonsPrintBehavior(std::make_unique<NoSeasonsPrintBehavior>());
}


const std::string& NewGirl::who() const {
    return m_serial_full_name;
}
