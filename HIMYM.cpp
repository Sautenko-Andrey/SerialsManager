#include"HIMYM.h"
#include<iostream>
#include<memory>
#include"HasSeasonsPrintBehavior.h"


HIMYM::HIMYM(const std::string &season, const std::string &lang)
: Serial(season, lang)
{
    setUrl(m_website_url);
    setVoiceUrlRus(m_rus_voice);
    setVoiceUrlEng(m_orig_voice);
    setSeasonUrl(m_season_template);
    setMaxSeasonNumber(m_seasons_nums);
    setSeasonsPrintBehavior(std::make_shared<HasSeasonsPrintBehavior>());
}



const std::string& HIMYM::who() const {
    return m_serial_full_name;
}