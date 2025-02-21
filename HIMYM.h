#pragma once
#include"Serial.h"


class HIMYM : public Serial {

public:

    HIMYM(const std::string &season, const std::string &lang);

    const std::string& who() const override;

private:

    inline static constexpr int m_seasons_nums{9};

    inline static const std::string m_website_url{"https://vashumamu-paramountcomedy.net/"};
    inline static const std::string m_orig_voice{"238-subtitles"};
    inline static const std::string m_rus_voice{"8-kuraj-bambey"};
    inline static const std::string m_season_template{"-season"};
    inline static const std::string m_serial_full_name{"How I Met Your Mother"};

};