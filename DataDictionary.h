//
// Created by jay on 12/14/16.
//

#ifndef DATA_DICTIONARY_H
#define DATA_DICTIONARY_H

#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdexcept>

#include "DataColumnHeader.h"

class DataDictionary {
private:
    bool          m_is_full;
    //
    std::vector   < DataColumnHeader >            m_data_column_header;
    std::vector   < std::string>                  m_data_grid_name;
    std::vector   < unsigned long>                m_data_grid_size;
    std::vector   < std::vector<unsigned long> >  m_data_grid_column;
    //
    unsigned long  m_data_dictionary_size;

    //Methods
    bool Ensure_MaxDataColumnHeaderDataGridIndexValid(std::string data_grid_name, unsigned long found_data_grid_index);
    //
    unsigned long  Get_Data_Grid_Index(std::string data_grid_name);
    unsigned long  Get_DataColumnHeaderIndex(std::string data_column_header);
    //
    void Add_ColumnNow(DataColumnHeader* dch);
    void Clear();
    void Display_Column(unsigned long i);
    void Display_DataGridNotFound(std::string data_grid_name);
    void Init();
    void Show_DataDictionaryEmpty();
    void Show_DataGridEmpty();

public:
    DataDictionary();
    ~DataDictionary();
    void Show_DataDictionaryAll();
    void Show_DataDictionary(std::string data_grid_name, unsigned long start, unsigned long stop);
    void Add_DataGrid(std::string data_grid_name);
    unsigned long Get_CountofDataGrids();
    unsigned long Add_DataGridColumn(std::string data_grid_name, std::string data_column_header);
    unsigned long Add_Column(DataColumnHeader* dch);
    unsigned long Get_Size();
    unsigned long Get_Size(std::string data_grid_name);
    void Show_Exception(const __exception e);
    void Display_Address(unsigned long i);
};


#endif //DATA_DICTIONARY_H
