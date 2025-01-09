#pragma once
#include<string>
#include"Serial.h"


class PoorPeople : public Serial {

public:

    PoorPeople(const std::string &season, const std::string &voice);

    const std::string& who() const override;


private:

    inline static const std::string m_website_url{"https://baskino.se/28109-serial-bednye-lyudi-2016.html"};
    inline static const std::string m_serial_full_name{"Poor people"};
};