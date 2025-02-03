#pragma once
#include<string>
#include<memory>
#include"SeasonsPrintBehavior.h"


class Serial {

public:

    Serial(const std::string &season, const std::string &voice);

    virtual ~Serial() = default;

    virtual const std::string& who() const = 0;

    void openSerial(std::string &season, std::string &voice);
    void openSerial();

    void setUrl(const std::string &url);
    void setVoiceUrlEng(const std::string &voice_url_eng);
    void setVoiceUrlRus(const std::string &voice_url_rus);
    void setSeasonUrl(const std::string &season_url);
    void setMaxSeasonNumber(const int number);

    constexpr int getSeasonsNumber() const;

    void printSeasons() const;


    void setSeasonsPrintBehavior(
        std::unique_ptr<SeasonsPrintBehavior> &&behavior);
    

private:

    inline void checkAndSetStr(std::string &first,
                               const std::string &second);

    std::string m_season;
    std::string m_voice;

    std::string m_url{""};
    std::string m_voice_url_eng{""};
    std::string m_voice_url_rus{""};
    std::string m_season_url{""};
    int m_max_season_number{1};
    std::unique_ptr<SeasonsPrintBehavior> m_ptr_seasons_print{nullptr};

};