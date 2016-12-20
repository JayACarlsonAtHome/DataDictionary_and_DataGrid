//
// Created by jay on 12/14/16.
//

#include "DataColumnHeader.h"

DataColumnHeader::DataColumnHeader()
{
    m_address = this;
    this->m_display_width = 14; // default width;
    this->m_column_header = "Default Header";
    this->m_column_description_short = "Default Short Description";
    this->m_column_description_long  = "Default Long  Description";
}



DataColumnHeader::DataColumnHeader(int display_width, std::string column_header, std::string column_description_short, std::string column_description_long)
{
    m_address = this;
    Init(     display_width
            , column_header
            , column_description_short
            , column_description_long
        );
}

//copy constructor
DataColumnHeader::DataColumnHeader(const DataColumnHeader &dch)
{
    m_address = this;
    this->m_display_width = dch.m_display_width;
    this->m_column_header = dch.m_column_header;
    this->m_column_description_short = dch.m_column_description_short;
    this->m_column_description_long  = dch.m_column_description_long;
}



void DataColumnHeader::Init(int display_width, std::string column_header, std::string column_description_short, std::string column_description_long)
{
    m_allow_data_multi_line_output = false;  // for now there is not option to do multi-line outputs
    Set_DisplayWidth(display_width);
    Set_ColumnHeader(column_header);
    Set_ColumnDescriptionShort(column_description_short);
    Set_ColumnDescriptionLong( column_description_long);
}



std::string DataColumnHeader::GetColumnHeader()
{
    return this->m_column_header;
}

int DataColumnHeader::GetDisplayWidth()
{
    return this->m_display_width;
}

std::string DataColumnHeader::GetColumnDescriptionShort()
{
    return this->m_column_description_short;
}

std::string DataColumnHeader::GetColumnDescriptionLong()
{
    return this->m_column_description_long;
}

void DataColumnHeader::Set_ColumnHeader(std::string value)
{
    if (value.length() > m_display_width)
    {
        m_column_header = value.substr(0, m_display_width);
    }
    else
    {
        m_column_header = value;
    }
}

void DataColumnHeader::Set_ColumnDescriptionShort(std::string value)
{
    if (value.length() > m_display_width)
    {
        m_column_description_short = value.substr(0, m_display_width);
    }
    else
    {
        m_column_description_short = value;
    }
}

void DataColumnHeader::Set_ColumnDescriptionLong( std::string value)
{
    {
        m_column_description_long = value;
    }
}

void DataColumnHeader::Set_DisplayWidth(unsigned int value)
{
    m_display_width = value;
}

void DataColumnHeader::Display_Address()
{
    std::cout << this << std::endl;
}