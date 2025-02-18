#pragma once
#include"Serial.h"



class THM : public Serial {

public:

    THM(std::string season, std::string lang);

    const std::string& who() const override;

private:

    inline static constexpr int m_seasons_nums{12};

    inline static const std::string m_website_url{"https://two-and-a-half-men.net/"};
    inline static const std::string m_orig_voice{"238-subtitles"};
    inline static const std::string m_rus_voice{"408-mtv"};
    inline static const std::string m_season_template{"-season"};
    inline static const std::string m_serial_full_name{"Two And A Half Men"};

};