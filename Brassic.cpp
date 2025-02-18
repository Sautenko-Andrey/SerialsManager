#include"Brassic.h"
#include<iostream>
#include<memory>
#include"HasSeasonsPrintBehavior.h"



Brassic::Brassic(std::string season, std::string lang)
:
Serial(std::move(season), std::move(lang))
{
    setUrl(m_website_url);
    setVoiceUrlRus(m_rus_voice);
    setVoiceUrlEng(m_orig_voice);
    setSeasonUrl(m_season_template);
    setMaxSeasonNumber(m_seasons_nums);
    setSeasonsPrintBehavior(std::make_unique<HasSeasonsPrintBehavior>());
}


const std::string& Brassic::who() const {
    return m_serial_full_name;
}