#include"ItCrowd.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"



ItCrowd::ItCrowd(const std::string &season, const std::string &lang)
:
Serial(season, lang)
{
    setUrl(m_website_url);

    setSeasonsPrintBehavior(std::make_unique<NoSeasonsPrintBehavior>());
}


const std::string& ItCrowd::who() const {
    return m_serial_full_name;
}
