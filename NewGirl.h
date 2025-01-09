#pragma once
#include<string>
#include"Serial.h"


class NewGirl : public Serial {

public:

    NewGirl(const std::string &season, const std::string &lang);

    const std::string& who() const override;


private:

    inline static const std::string m_website_url{"https://baskino.se/17172-serial-novaya-devushka-novenkaya-1-7-sezon-23-05-2018.html"};

    inline static const std::string m_serial_full_name{"New Girl"};
};