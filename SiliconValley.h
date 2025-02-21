#pragma once
#include<string>
#include"Serial.h"


class SiliconValley : public Serial {

public:

    SiliconValley(const std::string &season, const std::string &lang);

    const std::string& who() const override;


private:

    inline static constexpr int m_seasons_nums{6};

    inline static const std::string m_website_url{"https://silicon-valley-kubik.net/"};
    inline static const std::string m_orig_voice{"238-subtitles"};
    inline static const std::string m_rus_voice{"6-kubik-v-kube"};
    inline static const std::string m_season_template{"-season"};
    inline static const std::string m_serial_full_name{"Silicon Valley"};

};