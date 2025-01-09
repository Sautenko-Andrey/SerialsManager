#pragma once
#include<string>
#include"Serial.h"


class ATJ : public Serial {

public:

    ATJ(const std::string &season, const std::string &lang);

    const std::string& who() const override;


private:

    inline static const std::string m_website_url{"https://baskino.se/6459-kak-skazal-dzhim-serial-2001-2009-1-8-sezon.html"};

    inline static const std::string m_serial_full_name{"According To Jim"};
};