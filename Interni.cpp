#include"Interni.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"



Interni::Interni(std::string season, std::string lang)
:
Serial(std::move(season), std::move(lang))
{
    setUrl(m_website_url);

    setSeasonsPrintBehavior(std::make_unique<NoSeasonsPrintBehavior>());
}


const std::string& Interni::who() const {
    return m_serial_full_name;
}
