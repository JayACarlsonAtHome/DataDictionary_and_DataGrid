//
// Created by jay on 12/14/16.
//

#ifndef DATA_DICTIONARY_H
#define DATA_DICTIONARY_H

#include <algorithm>
#include <vector>
#include <iomanip>

#include "DataColumnHeader.h"

class DataDictionary {
private:
    unsigned int m_data_dictionary_size;
    bool         m_is_full;
    std::vector  <DataColumnHeader>  m_dc;
    std::vector  <std::string>                  m_data_grid_name;
    std::vector  < std::vector<unsigned int> >  m_data_grid_size;
    std::vector  < std::vector<DataColumnHeader*> > ptr_m_dc;
    bool         isDataGridExisting(std::string data_grid_name);
    unsigned int isDataColumnHeaderExisting(std::string data_column_header);
    unsigned int Get_Data_Grid_Index(std::string datagrid_name);
    void Add_ColumnNow(DataColumnHeader* dch);
    void Init();
public:
    DataDictionary();
    void Show_DataDictionary(std::string data_grid_name, unsigned int start, unsigned int stop);
    void Add_DataGrid(std::string data_grid_name);
    unsigned int Get_CountofDataGrids();
    unsigned int Add_DataGridColumn(std::string data_grid_name, std::string data_column_header);
    unsigned int Add_Column(DataColumnHeader* dch);
    unsigned int Get_Size();
    void Display_Address(unsigned int i);



};


#endif //DATA_DICTIONARY_H
