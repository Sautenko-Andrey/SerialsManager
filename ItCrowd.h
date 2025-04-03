#pragma once
#include<string>
#include"Serial.h"


class ItCrowd : public Serial {

public:

    ItCrowd(const std::string &season, const std::string &lang);

    const std::string& who() const override;


private:

    inline static const std::string m_website_url{"https://baskino.se/53905-kompyuterschiki-1-4-sezon.html"};

    inline static const std::string m_serial_full_name{"IT Crowd"};
};