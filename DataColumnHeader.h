//
// Created by jay on 12/14/16.
//

#ifndef DATA_COLUMN_HEADER
#define DATA_COLUMN_HEADER

#include <iostream>

class DataColumnHeader {

private:
    bool         m_allow_data_multi_line_output;
    //
    std::string  m_column_header;
    std::string  m_column_description_long;
    std::string  m_column_description_short;
    //
    unsigned int m_display_width;
    //
public:
    DataColumnHeader();
    DataColumnHeader(const DataColumnHeader &dch);
    DataColumnHeader(int display_width, std::string column_header, std::string m_column_description_short, std::string m_column_description_long);
    //
    std::string  Get_ColumnDescriptionLong();
    std::string  Get_ColumnDescriptionShort();
    std::string  Get_ColumnHeader();
    //
    unsigned int Get_DisplayWidth();
    //
    void Display_Address();
    void Init(int display_width, std::string column_header, std::string m_column_description_short, std::string m_column_description_long);
    //
    void Set_ColumnHeader(std::string value);
    void Set_ColumnDescriptionLong( std::string value);
    void Set_ColumnDescriptionShort(std::string value);
    void Set_DisplayWidth(unsigned int value);

};

#endif //DATA_COLUMN_HEADER
