#include"ATJ.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"



ATJ::ATJ(std::string season, std::string lang)
:
Serial(std::move(season), std::move(lang))
{
    setUrl(m_website_url);
    setSeasonsPrintBehavior(std::make_unique<NoSeasonsPrintBehavior>());
}


const std::string& ATJ::who() const {
    return m_serial_full_name;
}
