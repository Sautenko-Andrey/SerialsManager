#include"ATJ.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"



ATJ::ATJ(const std::string &season, const std::string &lang)
:
Serial(season, lang)
{
    setUrl(m_website_url);
    setSeasonsPrintBehavior(std::make_unique<NoSeasonsPrintBehavior>());
}


const std::string& ATJ::who() const {
    return m_serial_full_name;
}
