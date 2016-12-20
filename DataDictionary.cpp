//
// Created by jay on 12/14/16.
//

#include "DataColumnHeader.h"
#include "DataDictionary.h"

unsigned int DataDictionary::Add_Column(DataColumnHeader* dch)
{
    if (!m_is_full )
    {
        unsigned int found = -1;
        if (m_data_dictionary_size > 0)
        {
            found = isDataColumnHeaderExisting(dch->GetColumnHeader());
            if (found == -1) {
                Add_ColumnNow(dch);
            } else {
                std::cout << "Warning!!! -- The DataColumn already exists; No column added." << std::endl;
            }
        }
        else
        {
            Add_ColumnNow(dch);
        }
        if (this->m_data_dictionary_size == -1) {
            m_is_full = true;
            std::cout << "Warning!!! -- The DataDictionary just became full."  << std::endl;
        }
    }
    else
    {
        std::cout << "Warning!!! -- The DataDictionary is already full; No column added."  << std::endl;
    }

    return this->m_data_dictionary_size;
}

void DataDictionary::Add_ColumnNow(DataColumnHeader* dch)
{
    this->m_dc.push_back(*dch);
    this->m_data_dictionary_size += 1;
}


unsigned int DataDictionary::Get_Data_Grid_Index(std::string datagrid_name)
{
    //
    // early return possible in this method
    //
    unsigned int result = -1;
    unsigned int max = this->m_data_grid_name.size();
    bool cont = true;
    for (unsigned int i = 0; i < max; i++) {
        if (this->m_data_grid_name[i] == datagrid_name) {
            result = i;
            // early return here
            return result;
        }
    }
    return result;
}


void DataDictionary::Add_DataGrid(std::string datagrid_name)
{
    //ensure that this is a new (unique) data grid.
    unsigned int found = Get_Data_Grid_Index(datagrid_name);
    if (found == -1) {
        // Add a new data grid
        this->m_data_grid_name.push_back(datagrid_name);
    }
    else
    {
        // Show that data grid already exists.
        std::cout << "Warning!!! Datagrid named: " << datagrid_name << " already exists!" << std::endl;
    }
}


unsigned int DataDictionary::Add_DataGridColumn(std::string data_grid_name, std::string data_column_header)
{

    //ensure that this is a new (unique) data grid.
    unsigned int found_data_grid_index = Get_Data_Grid_Index(data_grid_name);

    if (found_data_grid_index != -1) {
        //ensure that data_column_header exists
        bool found = false;

        for (unsigned int i = 0; i < m_data_grid_name.size(); i++) {
            if (m_data_grid_name[i] == data_grid_name) {
                found = i;
            }
        }
    }
    else
    {
        std::cout << "Warning!!! Datagrid named: " << data_grid_name << " not found!" << std::endl;
    }

}


DataDictionary::DataDictionary()
{
    Init();
}

unsigned int DataDictionary::Get_CountofDataGrids()
{
    return m_data_grid_name.size();
}

unsigned int DataDictionary::Get_Size()
{
    return this->m_data_dictionary_size;
}

void DataDictionary::Init()
{
    m_is_full = false;
    this->m_data_dictionary_size = 0;
}

unsigned int DataDictionary::isDataColumnHeaderExisting(std::string data_column_header)
{
    unsigned int result = -1;
    if (!m_is_full)
    {
        for (unsigned int i = 0; i < m_data_dictionary_size; i++) {
            if (m_dc[i].GetColumnHeader() == data_column_header) {
                result = i;
            }
        }
    }
    return result;
}


void DataDictionary::Show_DataDictionary(std::string data_grid_name, unsigned int start, unsigned int stop)
{

    unsigned int found;
    unsigned int startx;
    unsigned int stopxx;

    if (data_grid_name == "") {
        if ((stop <= 0) || (stop > m_data_dictionary_size)) {
            stop = m_data_dictionary_size;
        }
    } else
    {
        unsigned int found = Get_Data_Grid_Index(data_grid_name);
        if (found != -1)
        {
            std::cout << "Datagrid named: " << data_grid_name << " found index: " << std::setfill('0') << std::setw(4) << found << std::endl;
        }
    }

    if (start > stop)
    {
        start = stop;
    }

    for(unsigned int i = start; i < stop; i++ )
    {
        std::cout << "DataDictionary Column Number:  " << std::setfill('0') << std::setw(4) << i << std::endl;
        Display_Address(i);
        std::cout << "  Column Name:    " << m_dc[i].GetColumnHeader() << std::endl;
        std::cout << "  Column Width:   " << m_dc[i].GetDisplayWidth() << std::endl;
        std::cout << "  Column Short Description: " << m_dc[i].GetColumnDescriptionShort() << std::endl;
        std::cout << "  Column Long  Description: " << m_dc[i].GetColumnDescriptionLong()  << std::endl;
        std::cout << std::endl << std::endl;
    }
}


void DataDictionary::Display_Address(unsigned int i)
{
    std::cout << "  Column Address: ";  m_dc[i].Display_Address();
}