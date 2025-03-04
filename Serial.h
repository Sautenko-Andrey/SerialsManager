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

    template<typename T>
    std::enable_if_t<std::is_convertible_v<T, std::string>>
    setUrl(T &&url){
        checkAndSetStr(m_url, std::forward<T>(url));
    }

    template<typename T>
    std::enable_if_t<std::is_convertible_v<T, std::string>>
    setVoiceUrlEng(T &&voice_url_eng){
        checkAndSetStr(m_voice_url_eng, std::forward<T>(voice_url_eng));
    }

    template<typename T>
    std::enable_if_t<std::is_convertible_v<T, std::string>>
    setVoiceUrlRus(T &&voice_url_rus){
        checkAndSetStr(m_voice_url_rus, std::forward<T>(voice_url_rus));
    }

    template<typename T>
    std::enable_if_t<std::is_convertible_v<T, std::string>>
    setSeasonUrl(T &&season_url){
        checkAndSetStr(m_season_url, std::forward<T>(season_url));
    }

    void setMaxSeasonNumber(const int number);
    void setMaxSeasonNumber(double number) = delete;
    void setMaxSeasonNumber(bool number) = delete;

    constexpr int getSeasonsNumber() const;

    void printSeasons() const;

    // For r-value param
    void setSeasonsPrintBehavior(
        std::unique_ptr<SeasonsPrintBehavior> &&behavior);

    // Prohibit copy and move
    Serial(const Serial &other) = delete;
    Serial& operator=(const Serial &other) = delete;
    Serial(Serial &&other) = delete;
    Serial& operator=(Serial &&other) = delete;
    

private:

    template<typename T>
    std::enable_if_t<std::is_convertible_v<T, std::string>>
    checkAndSetStr(std::string &first_str, T &&second_str)
    {
        if(!second_str.empty()){
            first_str = std::forward<T>(second_str);
        }
    }

    std::string m_season;
    std::string m_voice;

    std::string m_url{""};
    std::string m_voice_url_eng{""};
    std::string m_voice_url_rus{""};
    std::string m_season_url{""};
    int m_max_season_number{1};
    std::unique_ptr<SeasonsPrintBehavior> m_ptr_seasons_print{nullptr};

};