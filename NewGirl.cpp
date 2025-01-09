#include"NewGirl.h"
#include<iostream>
#include<memory>
#include"NoSeasonsPrintBehavior.h"


NewGirl::NewGirl(const std::string &season, const std::string &lang)
: Serial(season, lang)
{
    setUrl(m_website_url);

    setSeasonsPrintBehavior(std::make_shared<NoSeasonsPrintBehavior>());

}


const std::string& NewGirl::who() const {
    return m_serial_full_name;
}
