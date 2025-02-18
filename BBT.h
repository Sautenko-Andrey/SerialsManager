#pragma once
#include<string>
#include"Serial.h"


class BigBangTheory : public Serial {

public:

    BigBangTheory(std::string season, std::string lang);

    const std::string& who() const override;


private:

    inline static constexpr int m_seasons_nums{12};

    inline static const std::string m_website_url{"https://big-bang-theory-kuraj-bambey.net/"};
    inline static const std::string m_orig_voice{"238-subtitles"};
    inline static const std::string m_rus_voice{"8-kuraj-bambey"};
    inline static const std::string m_season_template{"-season"};

    inline static const std::string m_serial_full_name{"The Big Bang Theory"};

};