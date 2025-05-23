#include"BBT.h"
#include<iostream>
#include<memory>
#include"HasSeasonsPrintBehavior.h"



BigBangTheory::BigBangTheory(const std::string &season, const std::string &lang)
:
Serial(season, lang)
{
    setUrl(m_website_url);
    setVoiceUrlRus(m_rus_voice);
    setVoiceUrlEng(m_orig_voice);
    setSeasonUrl(m_season_template);
    setMaxSeasonNumber(m_seasons_nums);
    setSeasonsPrintBehavior(std::make_unique<HasSeasonsPrintBehavior>());
}


const std::string& BigBangTheory::who() const {
    return m_serial_full_name;
}